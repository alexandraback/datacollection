/* Round 1C
 * Problem A
 * intrepid
 */
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <numeric>
#include <memory>
#include <limits>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

default_random_engine generator(system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution(1,100);
auto myRand = bind(distribution, generator);

void drawOneRow(int free, int total)
{
	int remaining = free - 1;
	cout << 'c';
	for (int i=0; i<remaining; ++i)
		cout << '.';
	for (int i=free; i<total; ++i)
		cout << "*";
	cout << "\n";
}

void drawOneCol(int free, int total)
{
	int remaining = free - 1;
	cout << "c\n";
	for (int i=0; i<remaining; ++i)
		cout << ".\n";
	for (int i=free; i<total; ++i)
		cout << "*\n";
}

void draw_bomb_row(int cols)
{
	for (int col=0; col<cols; ++col)
		cout << "*";
	cout << "\n";
}

bool try_one(int rows, int cols, int free_space)
{
	if ( free_space == 1 )
	{
		// Draw a single square
		cout << "c";
		for (int col=1; col<cols; ++col)
			cout << "*";
		cout << "\n";
		for (int row=1; row<rows; ++row)
			draw_bomb_row(cols);
		return true;
	}
	else if ( rows == 1 )
	{
		drawOneRow(free_space, cols);
		return true;
	}
	else if ( cols == 1 )
	{
		drawOneCol(free_space, rows);
		return true;
	}
	
	return false;
}

int eat_first_two_rows(int cols, int free_space)
{
	int remaining_space = free_space;
	int used_cols = 0;
	for (int col=0; col<cols; ++col)
	{
		if ( remaining_space != 3 && remaining_space != 0 )
		{
			if ( col == 0 )
				cout << "c";
			else
				cout << ".";
			remaining_space -= 2;
			++used_cols;
		}
		else
		{
			cout << "*";
		}
	}
	cout << "\n";
	for (int col=0; col<cols; ++col)
	{
		if ( col < used_cols )
			cout << ".";
		else
			cout << "*";
	}
	cout << "\n";
	
	return remaining_space;
}

int eat_a_row(int cols, int free_space)
{
	int to_draw = min(free_space, cols);
	int after_draw = free_space - to_draw;
	if ( after_draw == 1 )
	{
		--to_draw;
		++after_draw;
	}
	for (int col=0; col<to_draw; ++col)
		cout << ".";
	for (int col=to_draw; col<cols; ++col)
		cout << "*";
	cout << "\n";
	
	return after_draw;
}

bool solve_many(int rows, int cols, int free_space)
{
	// Check possible
	if ( free_space < 4 )
		return false;
	else if ( free_space == 5 )
		return false;
	else if ( free_space == 7 )
		return false;
	
	int smallest_side = min(rows, cols);
	if ( smallest_side == 2 && (free_space % 2 != 0) )
		return false;
	
	// Passed check means solvable!
	int row = 0;
	int remaining_space = eat_first_two_rows(cols, free_space);
	row = 2;
	
	while ( remaining_space > 0 )
	{
		remaining_space = eat_a_row(cols, remaining_space);
		++row;
	}
	while ( row < rows )
	{
		draw_bomb_row(cols);
		++row;
	}
	
	return true;
}

bool doTest()
{
	int rows, cols, mines;
	cin >> rows >> cols >> mines;
	if ( ! cin.good() )
		return false;
	
	int free_space = rows * cols - mines;
	
	if ( try_one(rows, cols, free_space) )
		return true;
	else if ( solve_many(rows, cols, free_space) )
		return true;
	
	cout << "Impossible\n";
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(7);
	int runs;
	cin >> runs;
	for (int run=1; run <= runs; ++run) {
		cout << "Case #" << run << ":\n";
		
		if ( !doTest() )
		{
			cerr << "Test case failed!" << endl;
			break;
		}
		
		//cout << "\n";
	}
	if ( !cin.good() ) cerr << "Error reading!\n" << endl;
	
	return 0;
}
