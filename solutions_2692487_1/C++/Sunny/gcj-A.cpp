#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<cassert>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<ctime>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b)  ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

#define MP make_pair
#define pb push_back
#define inf  1000000000
#define maxn 1000005
#define maxc 100001
#define MP make_pair

//typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef __int64 LL;


int arr[105],n,maxv;
char memo[101][maxn];

int solve(int pos,int x)
{
	int ret=200;

	if(x>maxv) return 1;
	if(pos==n) return 1;
	if(memo[pos][x]) return memo[pos][x];

	if(arr[pos]<x)
		ret=solve(pos+1,x+arr[pos]);
	else
	{
		int p=1+solve(pos+1,x);
		int q= x>1 ? 1+solve(pos,2*x-1) : 200;

		ret=MIN(p,q);
	}


	return memo[pos][x]=ret;
}

int main()
{
	int i,j,k,tests,cs=0,K;
	string s;


	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&tests);

	while(tests--)
	{
		MEM(memo,0);
		int a;
		scanf("%d%d",&a,&n);
		maxv=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			maxv=MAX(maxv,arr[i]);
		}
		sort(arr,arr+n);

		int ans=solve(0,a);


		printf("Case #%d: %d\n",++cs,ans-1);
	}

	return 0;
}
