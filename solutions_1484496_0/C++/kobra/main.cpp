#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define pb push_back

bool comp(pair<int,int> a, pair<int,int> b)
{
	if(a.first < b.first)
		return true;
	else
		return false;
}

vector<int> Sums[3000001];

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z = 0; z < T; z++)
	{
		printf("Case #%d:\n",z+1);
		for(int i = 1; i <= 20 * 100000; i++)
			Sums[i].clear();
		vector<int> A;
		int N;
		scanf("%d",&N);
		for(int i = 0; i < N; i++)
		{
			int p;
			scanf("%d",&p);
			A.push_back(p);
		}
		for(int i = 0; i < (1<<20); i++)
		{
			int sum = 0;
			for(int j = 0; j < 20; j++)
			{
				if((i & (1<<j)) != 0)
					sum += A[j];
			}
			Sums[sum].push_back(i);
		}
		bool flag = false;
		for(int i = 1; i <= 20 * 100000; i++)
		{
			if(Sums[i].size()>1)
				for(int j = 1; j < Sums[i].size(); j++)
				{
					for(int k = 0; k < j; k++)
						if((Sums[i][j] & Sums[i][k]) == 0)
						{
							for(int l = 0; l < 20; l++)
							{
								if((Sums[i][j] & (1<<l)) != 0)
									printf("%d ", A[l]);
							}
							printf("\n");
							for(int l = 0; l < 20; l++)
							{
								if((Sums[i][k] & (1<<l)) != 0)
									printf("%d ", A[l]);
							}
							flag = true;
							break;
						}
					if(flag)
						break;
				}
			if(flag)
				break;
		}
		if(!flag)
			printf("Impossible");
		printf("\n");
	}
	return 0;
}