// GoogleCodeJam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define fcin fin
#define fcout fout
ifstream fin("a.in");
ofstream fout("a.out");
int E,R,N;
int v[10001];
long long maxs;
long long temp;
void work(int now,int e)
{
	if(now == N)
	{
		if(temp >maxs) maxs = temp;
		return;
	}
	for(int i=0; i <= e; ++i)
	{
		temp += i*v[now];
		work(now+1,min(e-i+R,E));
		temp -= i*v[now];
	}
}
int main(int argc, char* argv[])
{
	int T;
	fcin >> T;
	long long r,t;
	long long sum;
	long long cnt;
	for(int iCase = 1; iCase <= T; ++iCase)
	{
		fin >> E >> R >> N;
		sum = 0,cnt=0;
		for(int i=0; i < N; ++i)
		{
			fin >> v[i];
		}
		maxs = 0;
		temp = 0;
		work(0,E);
		fcout << "Case #" << iCase <<": " << maxs << endl;
		cout << "Case #" << iCase <<": "  << maxs << endl;
		
	}
	return 0;
}

