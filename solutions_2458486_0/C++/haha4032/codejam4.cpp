// codejam4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

const int N=21;

int cur[N];
int type[N];
int lef[N];
int keys[N][N], map[N][N];
int path[N], check[N];
bool go[N], cutgo[N];
bool finish;
int t(0),k(0),n(0),ii(0);
ofstream fout("d:\\out.txt");
ifstream fin("d:\\in.txt");

void init()
{
	finish = false;
	for(int i=0;i<N;++i)
	{
		cur[i] = 0;
		check[i] = 0;
		type[i] = -1;
		path[i] = -1;
		lef[i] = 0;
		go[i] = false;
		cutgo[i] = false;
	}
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			keys[i][j] = 0;
			map[i][j] = -1;
		}
}

bool cut(int ty)
{
	bool ans = false;
	if (cur[ty]>0)
		return true;
	cutgo[ty] = true;
	for(int j=0;j<n;++j)
		if (map[ty][j]>0 && lef[j]>0 && cutgo[j]==false)
			if (cut(j))
			{
				ans = true;
				break;
			}
	cutgo[ty] = false;
	return ans;
}

void search(int step)
{
	if (finish)
		return;
	if (step==n)
	{
		fout<<"Case #"<<ii+1<<":";
		for(int i=0;i<n;++i)
			fout<<" "<<path[i]+1;
		fout<<endl;
		finish = true;
		return;
	}

	for(int i=0;i<n;++i)
		if (lef[i]>0 && !cut(i))
			return;

	for(int i=0;i<n;++i)
		if (!go[i] && cur[type[i]]>0)
		{
			path[step] = i;
			go[i] = true;
			for(int j=0;j<n;++j)
				cur[j]+=keys[i][j];
			cur[type[i]]--;
			lef[type[i]]--;
			search(step+1);
			lef[type[i]]++;
			cur[type[i]]++;
			for(int j=0;j<n;++j)
				cur[j]-=keys[i][j];
			go[i] = false;
		}
}

int main()
{
	fin>>t;
	for(ii=0;ii<t;++ii)
	{
		//cout<<ii<<endl;
		init();
		fin>>k;
		fin>>n;
		cout<<k<<" "<<n<<endl;
		int p(0);
		for (int j=0;j<k;++j)
		{
			fin>>p;
			check[p]++;
			cur[p]++;
		}
		for (int j=0;j<n;++j)
		{
			fin>>type[j];
			lef[type[j]]++;
			check[type[j]]--;
			int nn(0);
			fin>>nn;
			for (int jj=0;jj<nn;++jj)
			{
				int temp(0);
				fin>>temp;
				keys[j][temp]++;
				map[temp][type[j]]++;
				check[temp]++;
			}
		}
		bool pass = true;
		for(int i=0;i<n;++i)
			if (check[i]<0)
			{
				pass = false;
				break;
			}
		if (pass)
			search(0);
		if (!finish)
			fout<<"Case #"<<ii+1<<": IMPOSSIBLE"<<endl;
	}
	return 0;
}
