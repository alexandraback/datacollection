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
int main(int argc, char* argv[])
{
	int T;
	fcin >> T;
	long long r,t;
	long long sum;
	long long cnt;
	for(int iCase = 1; iCase <= T; ++iCase)
	{
		fin >> r >> t;
		sum = 0,cnt=0;
		while(sum <= t)
		{
			cnt++;
			sum += 2*r+1;
			r = r+2;
		}
		fcout << "Case #" << iCase <<": " << cnt-1 << endl;
		cout << "Case #" << iCase <<": "  << cnt-1 << endl;
		
	}
	return 0;
}

