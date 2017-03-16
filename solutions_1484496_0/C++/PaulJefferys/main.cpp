#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../output.txt");
ifstream fin("../../input.txt");

long long nums[500];

long long sums[1<<20];

bool cmp(pair<long long, int> a, pair<long long,int> b)
{
	return (a.first<b.first);
}

int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	cout.precision(9);
	fout.precision(9);
	
	while(ttt>0)
	{
		ct++;
		ttt--;
		int n,i,j,k;
		
		fin >> n;
		
		for(i=0; i<n; i++)
		{
			fin >> nums[i];
		}
		
		memset(sums,0,sizeof(sums));
		
		vector<pair<long long,int> > lis;
		
		for(i=0; i<(1<<20); i++)
		{
			long long p =0;
			
			for(j=0; j<20; j++)
			{
				if( (i&(1<<j))>0)
				{
					p+=nums[j];
				}
			}
			lis.push_back(make_pair(p,i));
		}
		sort(lis.begin(),lis.end(),cmp);
		
		for(i=0; i<lis.size()-1; i++)
		{
			if(lis[i].first==lis[i+1].first)
				break;
		}
		
		
		
		
		cout << "Case #" << ct << ":" << endl;
		fout << "Case #" << ct << ":" << endl;
		
		for(j=0; j<20; j++)
		{
			if( (lis[i].second & (1<<j))>0 && (lis[i+1].second&(1<<j))==0)
			{
				cout << nums[j] << " ";
				fout << nums[j] << " ";
			}
		}
		cout << endl;
		fout << endl;
		
		for(j=0; j<20; j++)
		{
			if( (lis[i+1].second & (1<<j))>0 && (lis[i].second&(1<<j))==0)
			{
				cout << nums[j] << " ";
				fout << nums[j] << " ";
			}
		}
		cout << endl;
		fout << endl;
		
			
		
	}
	
	
	return 0;
}

