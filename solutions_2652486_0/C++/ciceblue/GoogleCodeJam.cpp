// GoogleCodeJam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define fcin fin
#define fcout fout
ifstream fin("a.in");
ofstream fout("a.out");

int a[20];
int b[20];
int R,N,M,K;
bool work(int num)
{
	if(num == 1) return true;
	for(int i=1; i <= N; ++i)
	{
		if(num==b[i]) return true;
	}
	for(int i=1; i <= N; ++i)
	{
		for(int j=i+1; j <= N; ++j)
		{
			if(num==b[i]*b[j]) return true;
		}
	}
	if(num==b[1]*b[2]*b[3]) return true;
	return false;
}
int main(int argc, char* argv[])
{
	int T;
	fcin >> T;

	map<int,int> q[20];
	for(int iCase = 1; iCase <= T; ++iCase)
	{
		fin >> R >> N >> M >> K;
		fcout << "Case #" << iCase <<":"  << endl;
		for(int i=1; i <=R; ++i)
		{
			for(int j=1; j<=K;++j)
			{
				fin >> a[j];
			}
			for( b[1]=2; b[1] <= M;++b[1])
			{
				for( b[2]=2;b[2] <=M; ++b[2])
				{
					for( b[3]=2;b[3] <= M; ++b[3])
					{
						bool flag = true;
						for(int j=1; j <= K; ++j)
						{
							if(!work(a[j]))
							{
								flag = false;
								break;
							}
						}
						if(flag)
						{
							fcout <<b[1]<<b[2]<<b[3]    << endl;
							goto goon;
						}
					}
				}
			}
goon:
				cout << "goon" << endl;
		}
	}
	return 0;
}

