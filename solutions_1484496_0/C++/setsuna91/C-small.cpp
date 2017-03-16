//TC Accretia Code Template
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>

#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define FILL(arr,n) memset(arr,n,sizeof(arr))
#define FORUP(i,m,n) for(int i=(m); i<(n); i++)
#define FORDOWN(i,m,n) for(int i=(m)-1; i>=(n); i--)

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define INF 2000000000
#define EPS 1e-11
#define PI acos(-1.0)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;

struct node
{
	vector<int> isi1;
	vector<int> isi2;
	int jum1;
	int jum2;
	int pos;
	node(int pos1)
	{
		isi1.clear();
		isi2.clear();
		jum1 = 0;
		jum2 = 0;
		pos = pos1; 
	}
	node(vector<int> isi1x,vector<int> isi2x,int pos1)
	{
		jum1 = 0;
		jum2 = 0;
		for(int i = 0;i < isi1x.size();i++)
		{
			isi1.PB(isi1x[i]);
			jum1 += isi1x[i];
		}
		for(int i = 0;i < isi2x.size();i++)
		{
			isi2.PB(isi2x[i]);
			jum2 += isi2x[i];
		}
		pos = pos1;
	}
	void isiNode1(int news)
	{
		jum1+= news;
		isi1.PB(news);
	}
	void isiNode2(int news)
	{
		jum2+= news;
		isi2.PB(news);
	}
};

int
main()
{
	bool yes;
	queue<node> Q;
	int T,N;
	vector<int> S;
	scanf("%d", &T);
	for(int tc = 1;tc <= T;tc++)
	{
		S.clear();
		while(!Q.empty())Q.pop();
		scanf("%d", &N);
		for(int i = 0;i < N;i++)
		{
			int temp;
			scanf("%d", &temp);
			S.PB(temp);
		}
		node temp(0);
		Q.push(temp);
		
		node temp1(0);
		temp1.isiNode1(S[0]);
		Q.push(temp1);
		
		node temp2(0);
		temp2.isiNode2(S[0]);
		Q.push(temp2);
		
		yes = false;
		printf("Case #%d:\n",tc);
		while(!Q.empty())
		{
			node news = Q.front();
			Q.pop();
			if(news.pos == N-1)continue;
			node tnews(news.isi1,news.isi2,news.pos+1);
			Q.push(tnews);

			node tnews1(news.isi1,news.isi2,news.pos+1);
			tnews1.isiNode1(S[news.pos+1]);
			if(tnews1.jum1 != 0 && tnews1.jum1 == tnews1.jum2)
			{
				for(int i = 0;i < tnews1.isi1.size()-1;i++)
				{
					printf("%d ",tnews1.isi1[i]);
				}
				printf("%d\n",tnews1.isi1[tnews1.isi1.size()-1]);
				for(int i = 0;i < tnews1.isi2.size()-1;i++)
				{
					printf("%d ",tnews1.isi2[i]);
				}
				printf("%d\n",tnews1.isi2[tnews1.isi2.size()-1]);
				yes = true;
				break;
			}
			else
			{
				Q.push(tnews1);
			}

			node tnews2(news.isi1,news.isi2,news.pos+1);
			tnews2.isiNode2(S[news.pos+1]);
			if(tnews2.jum1 != 0 && tnews2.jum1 == tnews2.jum2)
			{
				for(int i = 0;i < tnews2.isi1.size()-1;i++)
				{
					printf("%d ",tnews2.isi1[i]);
				}
				printf("%d\n",tnews2.isi1[tnews2.isi1.size()-1]);
				for(int i = 0;i < tnews2.isi2.size()-1;i++)
				{
					printf("%d ",tnews2.isi2[i]);
				}
				printf("%d\n",tnews2.isi2[tnews2.isi2.size()-1]);
				yes = true;
				break;
			}
			else
			{
				Q.push(tnews2);
			}
		}
		if(!yes)
		{
			printf("Impossible\n");
		}
	}
return 0;
}