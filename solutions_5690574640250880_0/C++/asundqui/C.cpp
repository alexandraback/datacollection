#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <bitset>
#include <functional>

using namespace std;

const int MAX = 50;

typedef bitset<MAX*MAX> Board;

int YX(int y, int x)
{
	return y*MAX + x;
}

bool InRange(int x, int RC)
{
	return (x >= 0) && (x < RC);
}

int main()
{
	int T;
	cin >> T;

	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int R, C, M;
		cin >> R >> C >> M;
		//cout << case_num << ": " << R << " " << C << " " << M << endl;

		unordered_map<Board, int> solution_map;
		deque<Board> front;
		vector< pair<Board, bool> > solutions(MAX*MAX+1);
		int target = R*C - M;

		Board board1;
		board1[YX(0,0)] = true;
		front.push_front(board1);
		solutions[1] = pair<Board, bool>(board1, true);
		
		Board solution = board1;
		bool solution_found = (target == 1);

		while (!front.empty() && !solution_found)
		{
			Board board = front.back();
			front.pop_back();

			solution_map[board] = board.count();
			for (int y = 0; y < R; ++y)
				for (int x = 0; x < C; ++x)
					if (board[YX(y,x)])
					{
						Board new_board = board;
						for (int i = -1; i <= 1; ++i)
							for (int j = -1; j <= 1; ++j)
								if (InRange(x+i, C) && InRange(y+j, R))
									new_board[YX(y+j,x+i)] = true; 

						if (solution_map.find(new_board) == solution_map.end())
						{
							solution_map[new_board] = new_board.count();
							if (!solution_found && (new_board.count() == target))
							{
								solution = new_board;
								solution_found = true;
							}
							front.push_back(new_board);
#if 0
							cout << "Added board to stack: " << new_board.count() << endl;
							for (int y = 0; y < R; ++y)
							{
								for (int x = 0; x < C; ++x)
									cout  << new_board[YX(y,x)];
								cout << endl;
							}
#endif
						}
					}
		}

		cout << "Case #" << case_num << ":" << endl;
		if (!solution_found)
			cout << "Impossible" << endl;
		else
		{
			for (int y = 0; y < R; ++y)
			{
				for (int x = 0; x < C; ++x)
				{
					if ((y == 0) && (x == 0))
						cout << 'c';
					else 
						cout << (solution[YX(y,x)] ? '.' : '*');
				}
				cout << endl;
			}
		}
	}
	return 0;
}