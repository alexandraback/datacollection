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

struct player
{
	int points;
	int id;
};

vector<player> pl;

double results[200];

bool comp(player a, player b)
{
	return a.points>b.points;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z = 0; z < T; z++)
	{
		printf("Case #%d: ",z+1);
		pl.clear();
		int N, X = 0;
		scanf("%d",&N);
		for(int i = 0; i < N; i++)
		{
			player temp;
			scanf("%d",&temp.points);
			temp.id = i;
			X += temp.points;
			pl.push_back(temp);
		}
		for(int i = 0; i < N; i++)
		{
			double a = 0;
			double b = 1.0;
			for(int j = 0; j < 40; j++)
			{
				double x = (a + b) / 2.0;
				double result = X * x + pl[i].points;
				double left = X * (1.0 - x);
				for(int k = 0; k < N; k++)
					if(k==i)
						continue;
					else
						if(pl[k].points < result)
							left -= result - pl[k].points;
				if(left < 0)
					b = x;
				else
					a = x;
			}
			printf("%0.5lf ",a*100);
		}
		

		

		printf("\n");
	}
	return 0;
}