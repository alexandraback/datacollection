/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int T,n,a[1010],b[1010];
double x;
set<int> A;

int solve(int*a,int*b)
{
	int ret=0;
	A.clear();
	for(int i=0;i<n;i++) A.insert(a[i]);
	for(int i=0;i<n;i++) if (A.upper_bound(b[i])!=A.end()) ret++,A.erase(A.upper_bound(b[i]));
	return ret;
}

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lf",&x),a[i]=int(x*100000+0.5);
		for(int i=0;i<n;i++) scanf("%lf",&x),b[i]=int(x*100000+0.5);
		printf("Case #%d: %d %d\n",tt,solve(a,b),n-solve(b,a));
	}
	
	return 0;
}
