#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
using namespace std;

#define LL long long

const int MOD = 30000000+3;

int N;
LL S[500];

int H[MOD], pos[MOD];
int n;
LL seq[MOD], msk[MOD];

void clear()
{
	for(int i=1;i<=n;++i)
		H[pos[i]]=0;
	n = 0;
}

int use;

LL A1, A2;

bool INS(LL s, LL ms)
{
	int p = s % MOD;
	for(; H[p]!=0 && seq[H[p]]!=s; p = (p==MOD-1?0:p+1));
	if(H[p]==0)
	{
		++n;
		H[p]=n;
		pos[n] = p;
		seq[n] = s;
		msk[n] = ms;
		return false;
	}
	A1 = msk[H[p]];
	A2 = ms;
	return true;
}

bool Dfs(int i, int c, LL msk, LL sum)
{
	if(i == N)
	{
		if(c != use) return false;
		if(INS(sum, msk)) {
			return true;
		}
		return false;
	}
	if(c < use)
		if(Dfs(i+1, c+1, msk|1ll<<i, sum+S[i])) return true;
	if(N - i > use - c)
		if(Dfs(i+1, c, msk, sum)) return true;
	return false;
}

void run()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)scanf("%I64d", S+i);
	random_shuffle(S, S+N);
	N = min(50,N);
	clear();
	for(use=1;!Dfs(0,0,0,0);++use){
		cerr << use << endl;
	}
	bool flag=false;
	for(int i=0;i<N;++i)
		if(A1&1ll<<i)
		{
			if(flag)putchar(' ');
			else flag=true;
			printf("%I64d", S[i]);
		}
	printf("\n");
	flag=false;
	for(int i=0;i<N;++i)
		if(A2&1ll<<i)
		{
			if(flag)putchar(' ');
			else flag=true;
			printf("%I64d", S[i]);
		}
	printf("\n");
}

bool check(int a)
{
	for(int i=2;i<=a/i;++i)
		if(a%i==0) return false;
return true;
}

int main()
{

	/*int x=MOD;
	for(x;!check(x);++x);
	cout << x << endl;
	while(1);
	*/
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d:\n",no);

		cerr << "no#"<<no<<endl;

		run();
	}
	return 0;
}