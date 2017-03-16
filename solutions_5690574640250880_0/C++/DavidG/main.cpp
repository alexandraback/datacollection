#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DBGLOG  std::cerr
#else
#define DBGLOG  if (0) std::cerr
#endif

enum CELL_STATE {
	CELL_CLICKED = -1,
	CELL_ZERO = 0,
	CELL_SAFE,
	CELL_MINED = 9
};

typedef std::pair<unsigned, unsigned>			coordinate_t;
typedef std::vector<std::vector<CELL_STATE>>	board_type;


void output_board(const board_type& board)
{
	for (const auto& row : board) {
		for (const auto cell : row) {
			switch (cell) {
			case CELL_CLICKED:
				std::cout << 'c';
				break;
			case CELL_MINED:
				std::cout << '*';
				break;
			default:
				std::cout << '.';
			}
		}
		std::cout << endl;
	}
}


void promote_to_zero(coordinate_t cell, board_type& board, std::vector<coordinate_t>& todos, int& mines)
{
	unsigned start_r = cell.first;
	unsigned start_c = cell.second;
	unsigned end_r = cell.first + 1;
	unsigned end_c = cell.second + 1;

	if (start_r > 0)
		start_r--;
	if (start_c > 0)
		start_c--;
	if (end_r < board.size())
		end_r++;
	if (end_c < board[0].size())
		end_c++;

	for (unsigned i = start_r; i < end_r; ++i) {
		for (unsigned j = start_c; j < end_c; ++j) {
			if (board[i][j] == CELL_MINED) {
				board[i][j] = CELL_SAFE;
				mines--;
				if (((i == cell.first) && (j > cell.second))
					|| (i > cell.first))
					todos.push_back(std::make_pair(i, j));
			}
		}
	}
}

bool wall_todos(std::vector<coordinate_t> todos, board_type& board, const int mines, const int M)
{
	while (!todos.empty()) {
		coordinate_t cell = todos.back();
		todos.pop_back();

		auto current_mines = mines;
		auto current_board = board;
		auto current_todos = todos;


		current_board[cell.first][cell.second] = CELL_ZERO;
		promote_to_zero(cell, current_board, current_todos, current_mines);
		if (M == current_mines) {
			board = current_board;
			return true;
		}
		else if (current_mines > M) {
			if (wall_todos(current_todos, current_board, current_mines, M)) {
				board = current_board;
				return true;
			}
		}
	}
	return false;
}


board_type calculate_board_type(int R, int C, int M)
{
	if (!M) {
		board_type retval(R, std::vector<CELL_STATE>(C, CELL_ZERO));
		retval[0][0] = CELL_CLICKED;
		return retval;
	}
	else if (M == (R * C) - 1) {
		board_type retval(R, std::vector<CELL_STATE>(C, CELL_MINED));
		retval[0][0] = CELL_CLICKED;
		return retval;
	}

	int mines = R * C;

	for (int i = 0; i < (R + 1)/2; ++i) {
		for (int j = 0; j < (C + 1)/2; ++j) {
			// try clicked here
			board_type board(R, std::vector<CELL_STATE>(C, CELL_MINED));
			std::vector<coordinate_t> todos;

			mines--;

			board[i][j] = CELL_CLICKED;
			promote_to_zero(std::make_pair(i, j), board, todos, mines);

			if (mines == M)
				return board;
			else if (mines < M) // Failure
				continue;
			else {
				// can we promote one of the SAFE cells to ZERO?

				if (wall_todos(todos, board, mines, M))
					return board;
			}

//TODO
		}
	}

	return board_type();
}


int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Need an input file" << std::endl;
	}
	else {
		std::fstream input;
		input.open(argv[1], std::fstream::in);

		if (!input.is_open())
			return -1;

		unsigned num_testcases;
		input >> num_testcases;
		for (unsigned i = 1; i <= num_testcases; ++i) {
			/*
			 *The first line of the input gives the number of test cases, T.
			 *T lines follow.
			 *
			 *Each line contains three space-separated integers: R, C, and M.
			 */
			unsigned R, C, M;

			input >> R >> C >> M;

			board_type retval = calculate_board_type(R, C, M);
			std::cout << "Case #" << i << ":" << std::endl;
			if (retval.empty())
				std::cout << "Impossible" << std::endl;
			else
				output_board(retval);
		}
	}
	return 0;
}

