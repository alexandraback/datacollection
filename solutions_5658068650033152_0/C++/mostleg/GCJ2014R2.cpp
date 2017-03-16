// GCJ2014R2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T,N,M,K;

void init()
{
	scanf("%d",&T);	
}

int solve()
{
	int swap;
	if (N>M) {
		swap=N;N=M;M=swap;
	}
	if (N<=2) {
		return K;
	}
	if (N*M-K<4) {
		return (N+M-4)*2 + K - N*M + 4;
	}
	if (K<=4) {
		return K;
	}

	int ret = N*M;
	for (int i=1; i<=M-2; i++) {
		int row = 2;
		int count = i*2;
		int stone = i*2;
		int cur = i;

		while (count < K) {
			if (row >= N) {
				stone = K;
				break;
			}
			row++;
			stone+=2;
			cur = cur+2 < M ? cur+2 : M;
			count+=cur;
			if (count < K && row < N) {
				row++;
				stone+=2;			
				count+=cur;
			}
		}
		if (count - K > 2) {
			stone--;
		}
		ret = ret < stone ? ret : stone;
	}
	return ret;
}

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		scanf("%d%d%d", &N, &M, &K);
				
		cout << "Case #" << ca << ": ";		
		int ret = solve();
		cout << ret << endl;		
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\C--small-attempt1.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\C--small-attempt1.out", "w", stdout);
	init();
	work();

	return 0;
}

