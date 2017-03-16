#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<set>
#include<queue>
#include<map>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;

vector<int> v;

struct info
{
	int aval,bval;
	int aset,bset;
	info(int av=0,int bv=0,int as=0,int bs=0)
	{
		aval=av;
		bval=bv;
		aset=as;
		bset=bs;
	}
	bool operator<(const info& b) const
	{
		return aval-bval<b.aval-b.bval;
	}
};

vector<info> bf;

void solve1(int n,int asum,int bsum,int aset,int bset)
{
	if(n==-1)
	{
		bf.push_back(info(asum,bsum,aset,bset));
	}
	else
	{
		solve1(n-1,asum,bsum,aset,bset);
		solve1(n-1,asum+v[n],bsum,aset|(1<<n),bset);
		solve1(n-1,asum,bsum+v[n],aset,bset|(1<<n));
	}
}

pair<int,int> solve2(int n,int nend,int asum,int bsum,int aset,int bset)
{
	if(n==nend)
	{
		vector<info>::iterator it=lower_bound(bf.begin(),bf.end(),info(bsum,asum,0,0));
		int ASUM=asum+it->aval;
		int BSUM=bsum+it->bval;
		if(ASUM==BSUM)
			return make_pair(aset|it->aset,bset|it->bset);
		return make_pair(0,0);
	}
	else
	{
		return max( solve2(n+1,nend,asum,bsum,aset,bset),
                max(solve2(n+1,nend,asum+v[n],bsum,aset|(1<<n),bset),
                solve2(n+1,nend,asum,bsum+v[n],aset,bset|(1<<n))));

	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int N;
		scanf("%d",&N);
		v.clear();
		for(int i=0;i<N;i++)
		{
			int tv;
			scanf("%d",&tv);
			v.push_back(tv);
		}
		bf.clear();
		solve1(N/2-1,0,0,0,0);
		sort(bf.begin(),bf.end());
		pair<int,int> res= solve2(N/2,N,0,0,0,0);
		printf("Case #%d:\n",t);
		if(res.first!=0)
		{
			for(int i=0;i<N;i++)
				if(res.first&(1<<i)) printf("%d ",v[i]);
			puts("");
			for(int i=0;i<N;i++)
				if(res.second&(1<<i)) printf("%d ",v[i]);
			puts("");
		}
		else
			printf("Impossible\n",t);
	}
}
