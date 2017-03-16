#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <queue>
using namespace std;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define in(x,s) (s.find(x)!=s.end())

typedef long long int64;
typedef vector<int> VI;
typedef vector<string> VS;

const double eps = 1E-12;
const double pi=acos(-1.0); 


ifstream fin("b.in");
ofstream fout("b.out");

int T;

int N;
bool F[1024];
bool F1[1024];
int cost[1024][2];
int main()
{
	
	fin>>T;
	
	
	for(int c=1;c<=T;c++)
	{
		memset(F,false,sizeof(F));
		memset(F1,false,sizeof(F1));
		int res = 0;
		fin>>N;
		for(int i=0;i<N;i++)
		{
			fin>>cost[i][0]>>cost[i][1];

		}

		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
				if(cost[i][0]>cost[j][0] || cost[i][0] == cost[j][0] && cost[i][1]<cost[j][1])
				{
					int tmp = cost[i][0];
					cost[i][0] = cost[j][0];
					cost[j][0] = tmp;
					tmp = cost[i][1];
					cost[i][1] = cost[j][1];
					cost[j][1] = tmp;

				}
			}
		



		int f = 0;
		int s =0;
		bool go = true;
		while(go)
		{
			go = false;
			for(int i=0;i<N;i++) if(!F[i])
			{
				if(s>=cost[i][1])
				{
					res++;
					go = true;
					F[i] = true;
					
					f++;
					if(F1[i])
					{
						s++;
					}
					else
					{
						F1[i] = true;					
						s+=2;
					}
				}				
			}
			if(!go)
			{
				for(int i=0;i<N;i++) if(!F1[i])
				{
					if(s>=cost[i][0])
					{
						res++;
						s++;
						go = true;
						F1[i] = true;					
						
						break;
					}				
				}
			}

		}

		if(f==N)
		{
		
	
			cout<<"Case #"<<c<<": "<<res<<endl;
			fout<<"Case #"<<c<<": "<<res<<endl;
		}
		else
		{
			cout<<"Case #"<<c<<": Too Bad"<<endl;
			fout<<"Case #"<<c<<": Too Bad"<<endl;
		}
		
	}
	return 0;
}
