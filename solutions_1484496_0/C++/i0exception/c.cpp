#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;

int N;
int d[55];
map<int, vector<int> > m;

void solve()
{
	int i, j, k;
	for(i = 1; i < (1<<N)-1; i++)
	{
		//cout<<i<<" "<<N<<endl;
		int sum = 0;
		for(j = 0; j < N; j++)
		{
			if((i&(1<<j)) == 0)
			{
				//cout<<"cont : "<<j<<endl;
				continue;
			}
			sum += d[j];
		}
		//cout<<"sum - : " << sum<<endl;
		/*if(sum == 3)
		{
			cout<<"3 done"<<endl;
		}*/
		if(m.find(sum) == m.end())
		{
			vector<int> x;
			x.PB(i);
			m[sum] = x;
		}
		else
		{
			m[sum].PB(i);
			if(m[sum].size() > 1)
			{
				//cout<<"sum:"<<sum<<endl;
				return;
			}
		}
	}
}

void printx(vector<int> v)
{
	int i, j, k;
	for(i = 0; i <v.size(); i++)
	{
		//cout<<"hi:"<<v[i]<<endl;
		for(j = 0; j < N; j++)
		{
			if((v[i]&(1<<j))==0)
				continue;
			printf("%d ", d[j]);
		}
		printf("\n");
	}
}

int main()
{
	int tes;
	GI(tes);
	FOR(c, 1, tes+1)
	{
		m.clear();
		GI(N);
		FORN(i, N)
		{
			GI(d[i]);
		}
		solve();
		int done = 0;
		printf("Case #%d:\n", c);
		for(map<int, vector<int> > :: iterator it = m.begin(); it != m.end(); it++)
		{
			if((it->second).size() > 1)
			{
				printx(it->second);
				done = 1;
				break;
			}
		}
		if(!done)
			printf("Impossible\n");
	}
	return 0;
}



