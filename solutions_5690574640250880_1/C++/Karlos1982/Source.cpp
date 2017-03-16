//program minesweeper master
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <tokenizer.hpp>  //split function to tokenize strings according to delimiters

using namespace std;


char assign_symbol(char *board, int width, int x, int y) {
	int danger = 0;
	int pos = (y - 1)*width + (x - 1); //top-left corner of current cell
	if ((y)>0) {
		if ((x>0) && (board[pos] == '*')) danger++;
		if (board[pos + 1] == '*') danger++;
		if ((x<width - 1) && (board[pos + 2] == '*')) danger++;
	}
	pos += (width); //left neighbour of current cell
	if ((x>0) && (board[pos] == '*')) danger++;
	pos += (width); //bottom left corner of current cell
	if ((x>0) && (board[pos] == '*')) danger++;
	//because of the method of filling, there cannot be more mines
	if (danger > 0) { return (danger + '0'); }  //adds ASCII code for 0 to turn number into char
	return'.';
}

string printmap(char* board, int height, int width) {
	string solution;
	for (int i = 0; i < height; i++) {
		solution.push_back('\n');
		solution.append(&board[i*width], width);
	}
	return solution;
}

//this method solves the problem
string solve(vector<string> lines) {
	vector<string> tokens = split(lines[0]);
	string solution = "";

	/**
	* BODY of SOLVE method
	*/
	int height = stoi(tokens[0]);
	int width = stoi(tokens[1]);
	int mines = stoi(tokens[2]);
	if ((height == 0) || (width == 0)) return "\nImpossible";
	if ((mines >= ((height*width))) && (mines > 0)) return "\nImpossible";
	//shortcut to solve the large problem
	int fastresolution = height*width - mines;
	if ((mines > 0) && (fastresolution > 1) && (fastresolution<4) && (width>1) && (height > 1)) {
		return "\nImpossible";
	}

	char* board = new char[height*width];

	if (fastresolution == 1) {
		std::fill(board, board + (height*width), '*');
		board[0] = 'c';
		return printmap(board, height, width);
	}
	//////////////////////////////////////////////////////////
	//std::fill(board, board + (height*width) - 1, '.');

	board[0] = 'c';

	if ((width == 1) || (height == 1)) {
		int count = 1;
		int remaining = fastresolution - 1;
		board[0] = 'c';
		std::fill(board + 1, board + remaining+1, '.');
		std::fill(board +remaining+1, board + (height*width), '*');
		return printmap(board, height, width);
	}

	if ((width > 2) && (height > 2)) {
		//shortcut if there are enough mines to fill columns 3 onward and rows 3 onward
		if (mines >= ((width - 2)*(height - 2))) {
			int y = 2;
			//fill the mines
			while (y < height) {
				std::fill_n(board + (y*width) + 2, (width - 2), '*');
				y++;
			}
			mines -= ((width - 2)*(height - 2));

			//shortcut if there are enough mines to fill columns 3 onward for the first two rows;
			if (mines >= (((width - 2) << 1))) {
				std::fill_n(board + 2, (width - 2), '*');
				std::fill_n(board + width + 2, (width - 2), '*');
				mines -= ((width - 2)<<1);
			}
			else {
				//fill the unassigned cells before assigning mines
				std::fill_n(board + 1, (width - 1), '.');
				std::fill_n(board + width, (width), '.');
				for (int i = 2; i < height; i++) {
					std::fill_n(board + (i)*width, 2, '.');
				}
				//not enough mines, we fill them according certain orden and finish

				//if remaining mines are odd, we bite a chunk from the corner to make
				//the problem solvable
				if (mines % 2 == 1) {
					mines++;
					board[2 * width + 2] = '.';
				}
				mines = mines >> 1;
				if (mines < (width - 2)) {
					std::fill_n(board + width - mines, mines, '*');
					std::fill_n(board + (width << 1) - mines, mines, '*');
				}
				else {
					--mines;
					if (height == 3) return "\nImpossible";
					std::fill_n(board + width - mines, mines, '*');
					std::fill_n(board + (width << 1) - mines, mines, '*');
					std::fill_n(board + (width*(height-1)), 2, '*');
				}

				return printmap(board, height, width);
			}
			//fill the remaining spaces;
			for (int i = 0; i < height; i++) {
				std::fill_n(board + (i)*width, 2, '.');
			}
			board[0] = 'c';
			if (mines == 0) {
				return printmap(board, height, width);
			}
			//the last mines will fill the two first columns
			if (mines % 2 == 1) {
				if (((height<<1)-mines-1)<8) return "\nImpossible";
				//move c to make the problem solvable
				board[0] = '.';
				board[width + 1] = 'c';
				board[2] = '.';
				board[width + 2] = '.';
				board[(width << 1) + 2] = '.';
				mines += 3;
			}
			mines = mines >> 1;
			for (int i = 0; i <= mines; i += 1) {
				std::fill_n(board + ((height - i)*width), 2, '*');
			}
			return printmap(board, height, width);
		}
		else {
			//not enough mines, we fill following certain order and finish
			std::fill(board + 1, board + (height*width), '.');

			int phase = 1;
			int offset_m = width - 1;
			int offset_n = height - 1;
			int x = offset_m;
			int y = offset_n;
			while (mines > 0) {
				//fill column (on odd phases)
				if ((phase)& (0x01)) {
					board[y*width + x] = '*';
					mines--;
					if ((--y) == 1) {
						phase++;
						y = offset_n;
						offset_m--;
						x = offset_m;
					}
				}
				else {
					//fill row (on even phases)
					board[y*width + x] = '*';
					mines--;
					if ((--x) == 1) {
						phase++;
						x = offset_m;
						offset_n--;
						y = offset_n;
					}
				}
			}
			return printmap(board, height, width);
		}
	}
	int remaining = fastresolution - 1;

	if (width == 2) {
		//remove impossible boards;
		if ((remaining == 1) || (remaining % 2 == 0)) return "\nImpossible";
		int count = 1;
		while (remaining--) {
			board[count++] = '.';
		}
		while (mines--) {
			board[count++] = '*';
		}
		return printmap(board, height, width);
	}

	if (height == 2) {
		//remove impossible boards;
		if ((remaining == 1) || (remaining % 2 == 0)) return "\nImpossible";
		int count = 1;
		int flip = width;
		while (remaining--) {
			board[flip + (count++ >> 1)] = '.';
			flip = width - flip;
		}
		while (mines--) {
			board[flip + (count++ >> 1)] = '*';
			flip = width - flip;
		}
		return printmap(board, height, width);
	}

	//////////////////////////////////////////////////////////

	return "\nImpossible";
}

int main(int argc, char* argv[]) {
	string in, temp, line;
	if (argc<2 || argc>3) {
		cout << "Please use <app> <infile> <outfile>" << '\n';
		return 0;
	}
	in = argv[1];
	string out = (argc == 3) ? argv[2] : "out.txt";
	
	//reading input file
	ifstream myfile(in);
	ofstream myoutfile(out);
	if (myfile.is_open()&&myoutfile.is_open())
	{
		//read first line, with number of problems to solve
		getline(myfile, line);
		int times = stoi(line); //number of use cases
		int count = 0;
		//solve X problems
		while (count<times) {
			getline(myfile, line);
			vector<string> lines;
			lines.push_back(line);
			//work with the input file one line each time
			myoutfile << "Case #" << (++count) << ":" << solve(lines) << '\n';
			//cout << line << '\n';
		}
		myfile.close();
		myoutfile.close();
	}
	else cout << "Unable to open file\n";
	return 0;
}
