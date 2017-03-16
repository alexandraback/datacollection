/*
 * A.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: carlosjosetoribio
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;

double iprob[100010];

int main()
{
	cin.sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc<=TC ; ++tc)
	{
		double p = 0;
		int N,L;
		cin >> N >> L;
		for(int i = 0; i < N; ++i)
			cin >> iprob[i];
		
	
		double mi = 2 + L;
		for(int i = 0; i <= N; ++i)
		{
			double np = p + (1-iprob[i]) - p * (1-iprob[i]);
			
			double stp = (N-i + L-i + 1)*(1-p) + (N-i + L-i + 1 + L + 1)*p;
			mi = min( stp , mi );
			
			p = np;
		}
		cout <<"Case #"<<tc<<": "<<setprecision(6)<<fixed<< mi << endl;
	}


	return 0;
}


