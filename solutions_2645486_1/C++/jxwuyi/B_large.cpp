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
#define ME(a) memset(a,0,sizeof(a))
#define MM(a,b) memset(a,b,sizeof(a))
#define MCP(a,b) memcopy(a,b,sizeof(a))
#define PII pair<int,int>
#define mkp(a,b) make_pair(a,b)
#define x first
#define y second
#define CPX complex<double>

int E, R, V[100000];

int N;

LL dp[20][10];

int check(LL &a, LL b)
{
	if(b > a) a= b;
}
int cnt=0;

int MaxN = 10003;

int A[100000], tmp;

int cmp(int a,int b){return V[a] > V[b];}

LL res;

LL run()
{
	scanf("%d %d %d", &E, &R, &N);
	for(int i=1;i<=N;++i) {
		scanf("%d", V+i);
		A[i]=i;
	}
	if(R >= E)
	{
		res=0;
		for(int i=1;i<=N;++i)
			res+=(LL) E * V[i];
		return res;
	}
	sort(A+1,A+N+1,cmp);
//	for(int i=1;i<=N;++i) cout << V[A[i]]<<" "; cout << endl;
	
	res = 0;
	
	set<PII > remain, require;
	remain.insert(mkp(-0,E));
	require.insert(mkp(N+1,R));
	
	set<PII >::iterator it;
	
	for(int i=1;i<=N;++i)
	{
		int p = A[i];
		
		it = remain.lower_bound(mkp(-p,0));
		int l = -it->first, S = it->second;
		it = require.lower_bound(mkp(p,0));
		int r = it->first, T = it->second;
		
		LL Llimit = S + (LL)(p - l - 1) * R;
		LL MaxInput = min(Llimit,(LL)E);
		
		LL lo = 0, hi = MaxInput + 1, mid;
		while(lo + 1 < hi)
		{
			mid = lo + hi >> 1;
			LL ts = min((LL)E, MaxInput - mid + R);
			LL Rlimit = ts + (LL)(r - p - 1) * R;
			if(Rlimit >= T) lo = mid;
			else hi = mid;
		}
		/*
		cout << "--> Location #"<<p<<" val = "<<V[p]<<endl;
		cout << "  > L = "<<l<<"  S = "<<S<<endl;
		cout << "  > R = "<<r<<"  T = "<<T<<endl;
		cout << "  --> choice = "<<lo<<endl;
		*/
		res += lo * V[p];
		
		remain.insert(mkp(-p, min((LL)E, MaxInput - lo + R)));
		require.insert(mkp(p, MaxInput));
	}
	
	return res;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int test;scanf("%d",&test);
	for(int no=1;no<=test;++no)
		printf("Case #%d: %lld\n", no, run());
}
