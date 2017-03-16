/* Check cf5-opt.vim defs.
VIM: let g:lcppflags="-std=c++11 -O2 -pthread"
VIM: let g:wcppflags="/O2 /EHsc /DWIN32"
VIM: let g:cppflags=g:Iboost.g:Itbb
VIM: let g:ldflags=g:Lboost.g:Ltbb.g:tbbmalloc.g:tbbmproxy
VIM: let g:ldlibpath=g:Bboost.g:Btbb
VIM: let g:argv=" < tic_tac_toy_tomek.sample_input"
*/
/*
Problem B. Cookie Clicker Alpha
Confused? Read the quick-start guide.
Small input
8 points	
Solve B-small
You may try multiple times, with penalties for wrong submissions.
Large input
11 points	
You must solve the small input first.
You have 8 minutes to solve 1 input file. (Judged after contest.)
Introduction

Cookie Clicker is a Javascript game by Orteil, where players click on a picture of a giant cookie. Clicking on the giant cookie gives them cookies. They can spend those cookies to buy buildings. Those buildings help them get even more cookies. Like this problem, the game is very cookie-focused. This problem has a similar idea, but it does not assume you have played Cookie Clicker. Please don't go play it now: it might be a long time before you come back.

Problem

In this problem, you start with 0 cookies. You gain cookies at a rate of 2 cookies per second, by clicking on a giant cookie. Any time you have at least C cookies, you can buy a cookie farm. Every time you buy a cookie farm, it costs you C cookies and gives you an extra F cookies per second.

Once you have X cookies that you haven't spent on farms, you win! Figure out how long it will take you to win if you use the best possible strategy.

Example

Suppose C=500.0, F=4.0 and X=2000.0. Here's how the best possible strategy plays out:

You start with 0 cookies, but producing 2 cookies per second.
After 250 seconds, you will have C=500 cookies and can buy a farm that produces F=4 cookies per second.
After buying the farm, you have 0 cookies, and your total cookie production is 6 cookies per second.
The next farm will cost 500 cookies, which you can buy after about 83.3333333 seconds.
After buying your second farm, you have 0 cookies, and your total cookie production is 10 cookies per second.
Another farm will cost 500 cookies, while you can buy after 50 seconds.
After buying your third farm, you have 0 cookies, and your total cookie production is 14 cookies per second.
Another farm would cost 500 cookies, but it actually makes sense not to buy it: instead you can just wait until you have X=2000 cookies, which takes about 142.8571429 seconds.
Total time: 250 + 83.3333333 + 50 + 142.8571429 = 526.1904762 seconds.
Notice that you get cookies continuously: so 0.1 seconds after the game starts you'll have 0.2 cookies, and ? seconds after the game starts you'll have 2? cookies.

Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated real-valued numbers: C, F and X, whose meanings are described earlier in the problem statement.

C, F and X will each consist of at least 1 digit followed by 1 decimal point followed by from 1 to 5 digits. There will be no leading zeroes.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum number of seconds it takes before you can have X delicious cookies.

We recommend outputting y to 7 decimal places, but it is not required. y will be considered correct if it is close enough to the correct number: within an absolute or relative error of 10-6. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits

1 <= T <= 100.

Small dataset

1 <= C <= 500.
1 <= F <= 4.
1 <= X <= 2000.
Large dataset

1 <= C <= 10000.
1 <= F <= 100.
1 <= X <= 100000.
Sample


Input 
 	
Output 
 
4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0

Case #1: 1.0000000
Case #2: 39.1666667
Case #3: 63.9680013
Case #4: 526.1904762

Note

Cookie Clicker was created by Orteil. Orteil does not endorse and has no involvement with Google Code Jam.
*/

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

struct puzzle_type
{
	double c;
	double f;
	double x;
};

void read_puzzle( puzzle_type& puzzle )
{
	std::cin >> puzzle.c;
	std::cin >> puzzle.f;
	std::cin >> puzzle.x;
}

double solve_puzzle( puzzle_type& puzzle )
{
	double r = 2.;	// rate
	double c = puzzle.c; // farm price
	double f = puzzle.f; // farm rate
	double x = puzzle.x; // goal
	double t = 0.; // seconds

	while ( true )
	{
		double t2x = x / r; // time to goal
		double t2c = c / r; // time to farm price
		double t2c2f = t2c + x/(r+f); // time to farm and then goal
		if ( t2c2f < t2x )
		{
			t += t2c;
			r += f;
		}
		else
		{
			t += t2x;
			break;
		}
	}
	
	return t;
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
		double s = solve_puzzle(puzzle);
		std::cout << "Case #" << (i+1) << ": " << std::setprecision(7) << std::fixed << s << std::endl;
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

