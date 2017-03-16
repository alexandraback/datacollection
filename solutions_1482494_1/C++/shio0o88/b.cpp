// BEGIN CUT HERE

// END CUT HERE
#line 5 "ImportantSequence.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include<stdio.h>
#include<stdlib.h>
#include   <iomanip>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define SZ(v) (int)((v).size())

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("in.in");
	outfile.open("out.in");
	int T;
	infile>>T;
	string line;
	getline(infile,line);


	for(int i=1;i<=T;i++)
	{
		int n,star=0,temp;
		int *stage1,*stage2;
		infile>>n;
		stage1=new int [n];
		stage2=new int [n];
		for(int j=0;j<n;j++)
			infile>>stage1[j]>>stage2[j];
		for(int j=0;j<n-1;j++)
			for(int k=j+1;k<n;k++)
				if(stage1[j]>stage1[k])
				{
					temp=stage1[j];
					stage1[j]=stage1[k];
					stage1[k]=temp;
					temp=stage2[j];
					stage2[j]=stage2[k];
					stage2[k]=temp;
				}
		for(int j=0;j<n-1;j++)
			for(int k=j+1;k<n;k++)
				if(stage2[j]>stage2[k])
				{
					temp=stage1[j];
					stage1[j]=stage1[k];
					stage1[k]=temp;
					temp=stage2[j];
					stage2[j]=stage2[k];
					stage2[k]=temp;
				}
		bool *f1,*f2;
		f1=new bool [n];
		f2=new bool [n];
		for(int j=0;j<n;j++)
		{
			f1[j]=false;
			f2[j]=false;
		}
		int num=0,count=0;
		bool err=false;
		while(num<n)
		{
			bool f=false;
			for(int j=0;j<n;j++)
			{
				if(f2[j]==true)
					continue;
				if(f2[j]==false && star>=stage2[j])
				{
					count++;
					f=true;
					f2[j]=true;
					num++;
					if(f1[j]==false)
					{
						star+=2;
						f1[j]=true;
					}
					else
						star+=1;
				}
				//else if(star<stage2[j])
					break;
			}
			if(f==true)
				continue;
			for(int j=n-1;j>=0;j--)
			{
				if(f1[j]==true)
					continue;
				if(f1[j]==false && star>=stage1[j])
				{
					count++;
					f=true;
					f1[j]=true;
					star+=1;
					break;
				}
			}
			if(f==false)
			{
				err=true;
				break;
			}
		}
		if(err==true)
			outfile<<"Case #"<<i<<": Too Bad"<<endl;
		else
			outfile<<"Case #"<<i<<": "<<count<<endl;
		delete [] stage1;
		delete [] stage2;
		delete [] f1;
		delete [] f2;
	}



	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
