

#ifndef __STANDINGOVATION__
#define __STANDINGOVATION__ 

using namespace std;

// Includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <random>
#include <cmath>
#include <limits>


int getCharNumber( const char& c ){

	if ( c < '0' || c > '9' )
	{
		throw "Illegal argument, Require 0-9";
	}
	return (int)(c - '0');

}

// (Assumes last number is not 0.)
int calculate( const int Smax, const string input ){

	int shynum;
	int diff;

	int standing = getCharNumber( input.at(0) );
	int friends = 0;
	for (int i = 1; i <= Smax; ++i)
	{
		shynum = getCharNumber( input.at(i) );

		// cout << i << " " << standing << " " << friends << " " << shynum << endl;

		if (i > standing)
		{
			diff = i-standing;
			friends += diff;
			standing += diff;
		}

		standing += shynum;

	}

	// cout << friends << endl;

	return friends;
}

#ifdef __TEST__
#include "tt_test.h"

void testSample(){

	int Smax;
	string input;
	int output;

	Smax = 4;
	input = "11111";
	output = calculate( Smax, input );
	TT_assert_EQ( output, 0 );


	Smax = 1;
	input = "09";
	output = calculate( Smax, input );
	TT_assert_EQ( output, 1 );


	Smax = 5;
	input = "110011";
	output = calculate( Smax, input );
	TT_assert_EQ( output, 2 );


	Smax = 0;
	input = "1";
	output = calculate( Smax, input );
	TT_assert_EQ( output, 0 );

}

void test2(){

	int Smax;
	string input;
	int output;

	Smax = 400;
	input = "0"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000009";
	output = calculate( Smax, input );
	// cout << output;
	TT_assert_EQ( output, 400 );

	Smax = 400;
	input = "9"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000000"
	"00000000000000000009";
	output = calculate( Smax, input );
	// cout << output;
	TT_assert_EQ( output, 391 );

}

void testCharNum(){

	TT_assert_EQ( getCharNumber('0'), 0 );
	TT_assert_EQ( getCharNumber('1'), 1 );
	TT_assert_EQ( getCharNumber('2'), 2 );
	TT_assert_EQ( getCharNumber('3'), 3 );
	TT_assert_EQ( getCharNumber('4'), 4 );
	TT_assert_EQ( getCharNumber('5'), 5 );
	TT_assert_EQ( getCharNumber('6'), 6 );
	TT_assert_EQ( getCharNumber('7'), 7 );
	TT_assert_EQ( getCharNumber('8'), 8 );
	TT_assert_EQ( getCharNumber('9'), 9 );

}

int main(int argc, char const *argv[])
{

	cerr << "Test CharNum:" << endl;
	TT_SETUP;
	TT_TEST(testCharNum);
	TT_TEST(test2);
	TT_FINAL;
	
	cerr << "Test Sample:" << endl;
	TT_SETUP;
	TT_TEST(testSample);
	TT_FINAL;

	return 0;
}

#else

// Actual main method.
int main( int argc, char const *argv[]){

	int t;
	int Smax;
	string s;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> Smax;
		cin.get();
		getline(cin, s);

		// cout << s << endl;

		cout << "Case #" << i+1 << ": " << calculate( Smax, s ) << endl;

	}

}

#endif

#endif