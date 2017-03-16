// B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct struLevel
{
	int req;
	int lev2;
};

struct state
{
	int ith;
	int score;
	int arr[1100];
};

bool cmp_l(const struLevel & s1, const struLevel & s2)
{
	if(s1.lev2 == s2.lev2)
		return s1.req < s2.req;
	else
		return s1.lev2 > s2.lev2;
}

int slove(vector<struLevel> & vs)
{
	int score = 0;
	int ret = 0;
	int arr_lcnt[1100];
	memset(arr_lcnt, 0, sizeof(arr_lcnt));

	bool exit = false;
	while(!exit)
	{
		bool is_ok = false;
		for(int i=0; i<vs.size(); i++)
		{
			if(arr_lcnt[i]<2 && score>=vs[i].req)
			{
				ret++;
				is_ok = true;
				if(score>=vs[i].lev2)
				{
					arr_lcnt[i] = 2;
					score += 2;
				}else
				{
					arr_lcnt[i]++;
					score++;
				}
				break;
			}
		}


		//先完成score达到的，但是只有一次的
		bool is_done =false;
		while(!is_done)
		{
			is_done = true;
			for(int j=0; j<vs.size(); j++)
			{
				if(arr_lcnt[j]<2 && score>=vs[j].lev2 && score>=vs[j].req)
				{
					score += 2-arr_lcnt[j];
					arr_lcnt[j] = 2;
					ret++;
					is_done = false;
					is_ok = true;
				}
			}
		}

		if(!is_ok)
			return -1;

		exit = true;
		for(int i=0; i<vs.size(); i++)
		{
			if(arr_lcnt[i]<2)
			{
				exit = false;
				break;
			}
		}

	}
	return ret;
}

int main()
{
	int n;
	ifstream inf("in-B.txt");
	ofstream outf("out-B.txt");

	inf>>n;
	for(int zi=1; zi<=n; zi++)
	{
		int lcnt;
		inf>>lcnt;
		vector<struLevel> vs;
		for(int i=0; i<lcnt; i++)
		{
			struLevel sadd;
			inf>>sadd.req>>sadd.lev2;
			vs.push_back(sadd);
		}

		sort(vs.begin(), vs.end(), cmp_l);

		int ret = slove(vs);
		if(ret < 0)
			outf<<"Case #"<<zi<<": Too Bad"<<endl;
		else
			outf<<"Case #"<<zi<<": "<<ret<<endl;
	}

	inf.close();
	outf.close();
	return 0;
}

