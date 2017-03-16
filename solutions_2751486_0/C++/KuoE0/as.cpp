/*
 * as.cpp
 * Copyright (C) 2013 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[ 2000000 ];
char vowel[] = "aeiou";


bool isVowel( char x ) {
	for ( int i = 0; i < 5; ++i )
		if ( x == vowel[ i ] )
			return 1;
	return 0;
}

bool check( int st, int ed, int n ) {

	int cnt = 0;
	for ( int i = st; i <= ed; ++i ) {
		if ( !isVowel( str[ i ] ) )
			++cnt;
		else
			cnt = 0;
		if ( cnt >= n )
			return 1;
	}
	return 0;
}

int main() {

	int T, n;
	scanf( "%d", &T );

	for ( int t = 0; t < T; ++t ) {

		scanf( "%s %d", str, &n );

		int ret = 0;

		for ( int i = 0; str[ i ]; ++i )
			for ( int j = i; str[ j ]; ++j )
				ret += check( i, j, n );

		printf( "Case #%d: %d\n", t + 1, ret );
	}
	return 0;
}





