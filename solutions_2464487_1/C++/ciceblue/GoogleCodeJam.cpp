// GoogleCodeJam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define fcin fin
#define fcout fout
ifstream fin("a.in");
ofstream fout("a.out");
int main(int argc, char* argv[])
{
	int T;
	fcin >> T;
	unsigned long long r,t;
	unsigned long long sum;
	unsigned long long cnt;
	unsigned long long left,right;
	for(int iCase = 1; iCase <= T; ++iCase)
	{
		fin >> r >> t;
		sum = 0,cnt=0;
		left = 1;
		right = t/(2*r-1)+10;
		if(right > 1000000001)
		{
			right = 1000000001;
		}
		while(left < right)
		{
			cnt = (left+right)/2;
			if(2*cnt*r+2*cnt*cnt-cnt>t)
			{
				right = cnt;
			}
			else
			{
				left = cnt+1;
			}
		}
		if(2*cnt*r+2*cnt*cnt-cnt>t) cnt--;
		fcout << "Case #" << iCase <<": " << cnt << endl;
		cout << "Case #" << iCase <<": "  << cnt << endl;
		
	}
	return 0;
}

