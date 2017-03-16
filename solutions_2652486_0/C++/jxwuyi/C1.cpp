#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

#define LL long long

int R, N, M, K;
vector<int> A;
vector<map<int,int> > H;

int pw[10];

int dfs(int i, int s)
{
	if(i == N)
	{
		A.push_back(s);
		map<int,int> h;
		for(int msk=0;msk < (1 << N); ++msk)
		{
			int c = 1;
			for(int i=0;i<N;++i)
				if(msk & 1 << i)
					c = c * (s / pw[i] % 10);
			h[c]++;
		}
		H.push_back(h);
		return 0;
	}
	for(int k=2;k<=M;++k)
		dfs(i+1,s*10+k);
}

int run()
{
	pw[0]=1;
	for(int i=1;i<10;++i)pw[i]=pw[i-1]*10;
	A.clear();
	scanf("%d %d %d %d", &R, &N, &M, &K);
	dfs(0,0);
	
	while(R--)
	{
		vector<int> B;
		for(int i=0;i<K;++i)
		{
			int x;
			scanf("%d", &x);
			B.push_back(x);
		}
		int best = -1;
		LL bcnt;
		for(int i=0;i<A.size();++i)
		{
			LL cnt = 1;
			for(int j=0;j<B.size();++j)
				cnt *= H[i][B[j]];
			if(best < 0 || cnt > bcnt)
			{
				bcnt = cnt;
				best = A[i];
			}
		}
		printf("%d\n", best);
	}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	int test;scanf("%d",&test);
	printf("Case #%d:\n", 1);
	run();
}
