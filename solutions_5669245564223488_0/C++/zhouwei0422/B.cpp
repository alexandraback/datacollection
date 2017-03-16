#include <algorithm>  
#include <bitset>  
#include <cctype>  
#include <cmath>  
#include <complex>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <fstream>
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>   
using namespace std;

ifstream ifile;
ofstream ofile;

int T,cases;

int N;

int alp[26];

bool check(string s)
{
	memset(alp,0,sizeof(alp));
	
	char cur = s[0];
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i]!=cur)
		{
			if(alp[s[i]-'a']==0)
			{
				alp[s[i]-'a']=1;
				cur = s[i];
			}
			else
				return false;
		}
		else
		{
			alp[cur-'a']=1;
		}
	}

	return true;
}

void solve()
{
	ifile>>N;
	
	vector<string> v(N);
	vector<int> s(N);

	for(int i = 0; i < N; i++)
	{
		ifile>>v[i];
		s[i]=i;
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < v[i].size()-1; j++)
		{
			if(v[i][j]==v[i][0]||v[i][j]==v[i][v[i].size()-1])
				continue;
			for(int k = 0; k < N; k++)
			{
				if(i==k)
					continue;
				for(int x = 0;x < v[k].size(); x++)
				{
					if(v[i][j]==v[k][x])
					{
						ofile<<"Case #"<<cases<<": "<<0<<endl;
						return;
					}
				}
			}
		}
	}

	for(int i = 0; i < N; i++)
	{
		string tmp="";
		tmp+=char(v[i][0]);
		tmp+=char(v[i][v[i].size()-1]);
		v[i]=tmp;
	}

	long long ret = 0;
	do 
	{
		/*
		int ind = 1;

		int count = 1;
		long long res = 1;

		
		while(ind<N)
		{
			if(v[s[ind-1]][v[s[ind-1]].size()-1]==v[s[ind]][0])
			{
				count++;
				ind++;
			}
			else
			{
				if(count==1)break;
				res*=choice[count];
				ind++;
				count=1;
			}
		}
		if(count>1)
		{
			ret +=res;
			ret%=1000000007;
		}
		*/
		string all = "";
		for(int i = 0; i < N; i++)
			all+=v[s[i]];
		if(check(all))
		{
			ret++;
			ret%=1000000007;
		}
	} while (next_permutation(s.begin(),s.end()));

	ofile<<"Case #"<<cases<<": "<<ret<<endl;
}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");

	ifile>>T;
	for(int i = 0; i < T; i++)
	{
		cases=i+1;
		solve();
	}

	ifile.close();
	ofile.close();
	return 0;
}