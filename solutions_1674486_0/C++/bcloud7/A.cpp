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


ifstream fin("a.in");
ofstream fout("a.out");


bool connect[1024][1024];
bool connect2[1024][1024];
bool checked[1024];


int T;
int main()
{
	
	fin>>T;
	for(int c=1;c<=T;c++)
	{
		memset(connect,false, sizeof(connect));
		memset(connect2,false, sizeof(connect2));
		memset(checked,false, sizeof(checked));
		int N;
		fin>>N;
		for(int i=0;i<1024;i++)
		{
			connect2[i][i] = true;
		}
		int cc[1024];
		memset(cc,0,sizeof(cc));
		for(int i=1;i<=N;i++)
		{
			int edge;
			fin>>edge;
			
			for(int e = 0;e<edge;e++)
			{
				int to;
				fin>>to;
				cc[i]++;
				cc[to]++;
				connect[i][to] = true;
				connect[to][i] = true;
				connect2[i][to] = true;
				connect2[to][i] = true;
			}	

		}

		//method 2
		for(int k=1;k<=N;k++)
			for(int i=1;i<=N;i++)
				for(int j=1;j<=N;j++)
				{
					if(connect2[i][k] && connect2[k][j])
					{
						connect2[i][j] = true;
						connect2[j][i] = true;
					}
				}
		for(int k=1;k<=N;k++)
			for(int i=1;i<=N;i++)
				for(int j=1;j<=N;j++)
				{
					if(connect2[i][k] && connect2[k][j])
					{
						connect2[i][j] = true;
						connect2[j][i] = true;
					}
				}
		int myCount[1024];
		for(int i=1;i<=N;i++)
		{
			myCount[i] = 0;
			for(int j=1;j<=N;j++)
				if(connect2[i][j])
					myCount[i]++;
		}

		for(int i=1;i<=N;i++)
		{			
			for(int j=1;j<=N;j++)
				if(connect2[i][j])
					assert(myCount[i] == myCount[j]);
		}



		bool found = false;

		for(int i=1;i<=N;i++)
			if(!checked[i])
			{
				vector<int> v;
				v.clear();
				for(int j=1;j<=N;j++)
					if(connect2[i][j])
					{
						assert(!checked[j]);
						v.push_back(j);
						checked[j] = true;
					}
				int n = v.size();
				int e = 0;
				int e2 = 0;
				for(int x=0;x<n;x++)
					e2 += cc[v[x]];
				


				for(int j=0;j<n;j++)
					for(int k=j+1;k<n;k++)
						if(connect[v[j]][v[k]])
							e++;

				assert(e2 == 2*e);
				if(e>=n)
				{
					found = true;
					break;
				}
			}

		if(found)
		{
			cout<<"Case #"<<c<<": Yes"<<endl;
			fout<<"Case #"<<c<<": Yes"<<endl;
		}
		else
		{
			cout<<"Case #"<<c<<": No"<<endl;
			fout<<"Case #"<<c<<": No"<<endl;
		}
		
	}
	return 0;
}


