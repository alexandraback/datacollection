//============================================================================
// Name        : GCJ2013-Round1A-Q3.cpp
// Author      : Anmol Ahuja
// Description : Google Code Jam 2013 - Round 1A, Q3
//============================================================================

#include <gmpxx.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <limits>
#define GREATER(a,b) (a>b?a:b)
#define SMALLER(a,b) (a<b?a:b)
#define FORI(a,b,c) for( int i = a; i<b; ++i )
#define IN(a) cin>>a
#define _USE_MATH_DEFINES
#define TYPE mpz_class
using namespace std;

TYPE numRings( TYPE r, TYPE t )
{
	TYPE a = 2, b = 2*r-1, c = - t;
	TYPE i = (-b + sqrt( b*b-(4*a*c) ) )/4;
	return i;
}

int main() {
	int T, x;
	TYPE r , t;
	cin>>T;
	for( x=1; x<=T; ++x)
	{
		cin>>r>>t;
		cout<<"Case #"<<x<<": "<<numRings(r,t)<<"\n";
	}
	return 0;
}
 
