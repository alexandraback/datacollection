/*
 * A.cpp
 *
 *  Created on: May 5, 2012
 *      Author: alexei
 */

#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector < pair < unsigned long long , unsigned long long > > A,B;

int N,M;
unsigned long long ans;

bool check_B( int pos, unsigned long long target )
{
	for( unsigned int i = pos; i < B.size(); ++i )
	{
		if( B[i].second == target )
			return true;
	}
	return false;
}

bool check_A( int pos, unsigned long long target )
{
	for( unsigned int i = pos; i < A.size(); ++i )
	{
		if( A[i].second == target )
			return true;
	}
	return false;
}

unsigned long long max( unsigned long long a, unsigned long long b )
{
	return a>b?a:b;
}
unsigned long long min( unsigned long long a, unsigned long long b )
{
	return a<b?a:b;
}

unsigned long long df( int p1, int p2, unsigned long long sol )
{
	if( p1 == N || p2 == M )
		return sol;

	//printf("Enter: %d %d %d\n",p1,p2,sol);

	unsigned long long m = 0;
	if( A[p1].second == B[p2].second && A[p1].first > 0 && B[p2].first > 0 )
	{
		m=min( A[p1].first , B[p2].first );

		//printf("%d\n",m);

		sol+=m;

		A[p1].first -= m;
		B[p2].first -= m;

		unsigned long long s1 = 0,s2 = 0,s3 = 0;
		if( A[p1].first > 0 && check_B(p2+1,A[p1].second) )
			s1 = df(p1,p2+1,sol);
		if( B[p2].first > 0 && check_A(p1+1,B[p2].second) )
			s2 = df(p1+1,p2,sol);

		s3 = df( p1+1,p2+1,sol); sol = max(sol,s3);

		sol = max( sol, max( s1 , s2 ) );

		A[p1].first += m;
		B[p2].first += m;
	}
	else
	{
		unsigned long long s1 = 0,s2 = 0, s3 = 0;
		if( A[p1].first > 0 && check_B(p2+1,A[p1].second))
			s1 = df(p1,p2+1,sol);

		if( B[p2].first > 0 && check_A(p1+1,B[p2].second) )
			s2 = df(p1+1,p2,sol);

		s3 = df( p1+1,p2+1,sol); sol = max(sol,s3);

		sol = max( sol, max( s1 , s2 ) );
	}

	//cout << p1 << "  " << p2 << " " << sol << "\n";
	//printf("Exit: %d %d %d\n",p1,p2,sol);

	return sol;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

	int T;
	scanf("%d",&T);

	for( int t = 1; t <= T; ++t )
	{
		A.clear();
		B.clear();

		unsigned long long a1,a2;

		scanf("%d%d",&N,&M);

		ans = 0;

		for( int i = 0; i < N; ++i )
		{
			cin >> a1 >> a2;
			A.push_back(make_pair(a1,a2));
		}
		for( int i = 0; i < M; ++i )
		{
			cin >> a1 >> a2;
			B.push_back(make_pair(a1,a2));
		}

		ans = df(0,0,0);
		cout << "Case #" << t << ": " << ans << "\n";
	}

	return 0;
}
