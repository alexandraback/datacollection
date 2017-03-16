/*
 * B.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: carlosjosetoribio
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;

double a[1010];
double b[1010];
int st_lvl[1010];

int main()
{
	cin.sync_with_stdio(false);
	freopen("/Users/carlosjosetoribio/Desktop/B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc<=TC ; ++tc)
	{
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i)
		{
			cin >> a[i] >> b[i];
			st_lvl[i] = 0;
		}
		
		int st = 0 , turns = 0;
		while(true)
		{
			int t = -1 , idx = -1;
			for(int i = 0; i < N; ++i)
			{
				if(st_lvl[i] < 2 && b[i] <= st)
				{
					t = 2;
					idx = i;
					break;
				}
			}
			if(t == -1)
			for(int i = 0; i < N; ++i)
			{
				if(st_lvl[i] < 1 && a[i] <= st)
				{
					if( t==-1 || b[idx] < b[i])
						idx = i;
					t = 1;
				}
			}
			
			if( t == -1 )break;
			turns++;
			st += t-st_lvl[ idx ];
			st_lvl[ idx ] = t;
		}
		
		cout << "Case #" << tc << ": ";
		if( st == 2*N )
			cout << turns << endl;
		else
			cout << "Too Bad" << endl;
		
		
	}


	return 0;
}


