/* Check cf5-opt.vim defs.
VIM: let g:lcppflags="-std=c++11 -O2 -pthread"
VIM: let g:wcppflags="/O2 /EHsc /DWIN32"
VIM: let g:cppflags=g:Iboost.g:Itbb
VIM: let g:ldflags=g:Lboost.g:Ltbb.g:tbbmalloc.g:tbbmproxy
VIM: let g:ldlibpath=g:Bboost.g:Btbb
VIM: let g:argv=" < tic_tac_toy_tomek.sample_input"
*/
/*
Problem C. Minesweeper Master
Confused? Read the quick-start guide.
Small input
11 points	
Solve C-small
You may try multiple times, with penalties for wrong submissions.
Large input
24 points	
You must solve the small input first.
You have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

Minesweeper is a computer game that became popular in the 1980s, and is still included in some versions of the Microsoft Windows operating system. This problem has a similar idea, but it does not assume you have played Minesweeper.

In this problem, you are playing a game on a grid of identical cells. The content of each cell is initially hidden. There are M mines hidden in M different cells of the grid. No other cells contain mines. You may click on any cell to reveal it. If the revealed cell contains a mine, then the game is over, and you lose. Otherwise, the revealed cell will contain a digit between 0 and 8, inclusive, which corresponds to the number of neighboring cells that contain mines. Two cells are neighbors if they share a corner or an edge. Additionally, if the revealed cell contains a 0, then all of the neighbors of the revealed cell are automatically revealed as well, recursively. When all the cells that don't contain mines have been revealed, the game ends, and you win.

For example, an initial configuration of the board may look like this ('*' denotes a mine, and 'c' is the first clicked cell):

*..*...**.
....*.....
..c..*....
........*.
..........
There are no mines adjacent to the clicked cell, so when it is revealed, it becomes a 0, and its 8 adjacent cells are revealed as well. This process continues, resulting in the following board:
*..*...**.
1112*.....
00012*....
00001111*.
00000001..
At this point, there are still un-revealed cells that do not contain mines (denoted by '.' characters), so the player has to click again in order to continue the game.
You want to win the game as quickly as possible. There is nothing quicker than winning in one click. Given the size of the board (R x C) and the number of hidden mines M, is it possible (however unlikely) to win in one click? You may choose where you click. If it is possible, then print any valid mine configuration and the coordinates of your click, following the specifications in the Output section. Otherwise, print "Impossible".

Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated integers: R, C, and M.

Output

For each test case, output a line containing "Case #x:", where x is the test case number (starting from 1). On the following R lines, output the board configuration with C characters per line, using '.' to represent an empty cell, '*' to represent a cell that contains a mine, and 'c' to represent the clicked cell.

If there is no possible configuration, then instead of the grid, output a line with "Impossible" instead. If there are multiple possible configurations, output any one of them.

Limits

0 ≤ M < R * C.
Small dataset

1 ≤ T ≤ 230.
1 ≤ R, C ≤ 5.
Large dataset

1 ≤ T ≤ 140.
1 ≤ R, C ≤ 50.
Sample


Input 
 	
Output 
 
5
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82

Case #1:
Impossible
Case #2:
c
.
*
Case #3:
Impossible
Case #4:
......*
.c....*
.......
..*....
Case #5:
**********
**********
**********
****....**
***.....**
***.c...**
***....***
**********
**********
**********


*/

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <sstream>

struct puzzle_type
{
	int r;
	int c;
	int m;
};

void read_puzzle( puzzle_type& puzzle )
{
	std::cin >> puzzle.r;
	std::cin >> puzzle.c;
	std::cin >> puzzle.m;
}

inline int idx( int i, int j )
{
}

std::string solve_puzzle( puzzle_type& puzzle )
{
	int r = puzzle.r; // row
	int c = puzzle.c; // col
	int m = puzzle.m; // mines
	int s = r*c-m; // free space


	std::vector<int> b(r*c,-1);
	auto idx = [c](int i, int j) -> int {
		return i*c+j;
	};

	//
	//	No space :-)
	//
	if ( s == 0 )
		return std::string();
	//
	//	Only one free cell, click there :-)
	//
	else if ( s == 1 )
		b[0]=-2;
	//
	//	min(r,c) == 1 then we always have solution.
	//
	else if ( std::min(r,c) == 1 )
	{
		for ( int i = 0; i < s; ++i )
			b[i]=0;
		b[0]=-2;
	}
	//
	//	min(r,c) == 2 then we always have a solution in case of 
	//	even mines if number of free spaces is 4 or above.
	//	And never have solution otherwise. Note: case of 1 is
	//	covered above.
	//
	else if ( std::min(r,c) == 2 )
	{
		if ( s < 4 || s % 2 )
			return std::string();
		else
		{
			int ie = r;
			int je = c;
			
			if ( c == 2 )
				ie = s/2;
			else
				je = s/2;

			for ( int i = 0; i < ie; ++i )
				for ( int j = 0; j < je; ++j )
					b[idx(i,j)]=0;
			b[0] = -2;
		}
	}
	//
	//	Both r and c are above or equal 3. Then we always have solution
	//	if s >= 8 and s = 1,4,6 cases. Otherwise in case of
	//	s = 2,3,5,7 we don't have solution.
	//	Note: s = 1 case is considered above.
	//
	else // if ( std::min(r,c) > 3 )
	{
		if ( s == 2
			|| s == 3
			|| s == 5
			|| s == 7 )
			return std::string();
		else if ( s == 4 )
		{
			//
			//	c.???
			//  ..???
			//  ?????
			//
			b[0] = -2;
			b[idx(0,1)]=0;
			b[idx(1,1)]=0;
			b[idx(1,0)]=0;
		}
		else if ( s == 6 )
		{
			//
			//	c..??
			//  ...??
			//  ?????
			//
			b[0] = -2;
			b[idx(0,1)]=0;
			b[idx(1,1)]=0;
			b[idx(1,0)]=0;
			b[idx(0,2)]=0;
			b[idx(1,2)]=0;
		}
		else
		{
			//
			//	c..??
			//  ...??
			//  ..???
			//  ?????
			//
			b[0] = -2;
			b[idx(0,1)]=0;
			b[idx(1,1)]=0;
			b[idx(1,0)]=0;
			b[idx(0,2)]=0;
			b[idx(1,2)]=0;
			b[idx(2,0)]=0;
			b[idx(2,1)]=0;
			if ( s % 2 )
				b[idx(2,2)]=0;

			//
			//	This amount of space we need to feel on board.
			//	Note: rs is always even.
			//
			int rs = s-8-s%2; 
			//
			//	Fill space on two topmost rows as long rs is not 0.
			//
			for ( int i = 3; i < r && rs; ++i )
			{
				b[idx(i,0)]=0;
				b[idx(i,1)]=0;
				rs -=2;
			}
			//
			//	Fill space on two leftmost columns as long rs is not 0;
			//
			for ( int j = 3; j < c && rs; ++j )
			{
				b[idx(0,j)]=0;
				b[idx(1,j)]=0;
				rs -=2;
			}
			//
			// Remove row by row until we fill the rest of free space.
			//
			if ( s % 2 )
			{
				b[idx(2,2)]=-1; // put mine back, we will remove it in the loop
				++rs;
			}
			for ( int i = 2; i < r && rs; ++i )
			{
				for ( int j = 2; j < c && rs; ++j)
				{
					b[idx(i,j)]=0;
					--rs;
				}
			}
		}
	}
	//
	//	Print board.
	//
	std::stringstream ss;
	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			int v = b[idx(i,j)];
			if ( v == -1 )
				ss << '*';
			else if ( v == 0 )
				ss << '.';
			else if ( v == -2 )
				ss << 'c';
		}
		ss << std::endl;
	}

	return ss.str();
}

int main ( void )
{try{

	int puzzle_count;
	puzzle_type puzzle;

	std::cin >>	puzzle_count;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	for ( int i = 0; i < puzzle_count; i++ )
	{
		read_puzzle(puzzle);
		std::string s = solve_puzzle(puzzle);
		std::cout << "Case #" << (i+1) << ":" << std::endl;
		if ( s.empty() )
			std::cout << "Impossible" << std::endl;
		else
			std::cout << s;
	}

	return 0;
}
catch ( const std::exception& e )
{
	std::cerr << std::endl
			<< "std::exception(\"" << e.what() << "\")." << std::endl;
	return 2;
}
catch ( ... )
{
	std::cerr  << std::endl
			<< "unknown exception." << std::endl;
	return 1;
}}

