#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
/** Constant List .. **/
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};

const int MOD = 1000000007;
const int INF = 100000;
const LL INFF = 1LL << 60;
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = acos(-1.0); //M_PI;

#define SZ(A) int(A.size())
#define PB push_back
#define ALL(A) A.begin(), A.end()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define maxn 1000010

void PrintMsk(int MASK,int base,int nbit){
	for(int i=0;i<nbit;i++,MASK/=base)printf("%d ",MASK%base);printf("%c",10);}
void Display(int* ARR,int LEFT,int RIGHT){
	for(int i=LEFT ; i<=RIGHT ; i++ )printf("%d ",ARR[i]);printf("%c",10);}
struct matrix
{
	int n; int a[25][25];
	void clear(){ memset(a,0,sizeof(a)); }
	void init(){ clear(); for(int i=1;i<=n;i++) a[i][i]=1; }
	matrix operator * (matrix b)
	{
		matrix c; c.n=n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			c.a[i][j]=0;
			for(int k=1;k<=n;k++) c.a[i][j]+=a[i][k]*b.a[k][j];
		}
		return c;
	}
	matrix operator + (matrix b)
	{
		matrix c; c.n=n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c.a[i][j]=a[i][j]+b.a[i][j];
		return c;
	}
};
/*********************main*********************/
int dp[111][maxn];
int a[111],A,n;
void input()
{
	scanf("%d%d",&A,&n);
	int i;
	for ( i=1 ; i<=n ; i++ ) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
}
void DP(int cur,int pos,int cnt)
{
	int i,j,res=INF;
	for ( i=pos ; i<=n+1 ; i++ )
	for ( j=cur ; j<=a[n]+1 ; j++ ) dp[i][j] = INF;

	dp[pos][cur] = cnt;
	for ( i=pos ; i<=n ; i++ )
	for ( j=cur ; j<=a[n]+1 ; j++ )
	if (dp[i][j]!=INF)
	{
		dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
		if (j<=a[i])
		{
			int tmp1,tmp2;
			tmp1 = j;
			tmp2 = 0;
			while (tmp1<=a[i])
			{
				tmp1 = tmp1+tmp1-1;
				tmp2++;
			}
			tmp1 = min(a[n]+1,tmp1+a[i]);
			dp[i+1][tmp1] = min(dp[i+1][tmp1],dp[i][j]+tmp2);
		}else if(j>a[i])
		{
			int tmp1 = min(a[n]+1,j+a[i]);
			dp[i+1][tmp1] = min(dp[i+1][tmp1],dp[i][j]);
		}
	}
	for ( i=cur ; i<=a[n]+1 ; i++ )
	if (dp[n+1][i] != INF) res=min(res,dp[n+1][i]);
	printf("%d\n",res);
}
void solv()
{
	int cnt=0,cur,i;
	cur = A;
	if (cur == 1)
	{
		printf("%d\n",n);
		return;
	}
	for ( i=1 ; i<=n ; i++ )
	{
		if (cur > a[i]) cur+=a[i];
		else	if(cur+cur-1 > a[i])
		{
			cur = cur+cur-1+a[i];
			cnt++;
		}
		else
		{
			DP(cur,i,cnt);
			return;
		}
	}
	printf("%d\n",cnt);
}
int main()
{
	int cas,tt=0;
//	freopen("test.txt","r",stdin);
	freopen("A-large (1).in","r",stdin);
	freopen("ans.out","w",stdout);

	scanf("%d",&cas);
	while (cas--)
	{
		printf("Case #%d: ",++tt);
		input();
		solv();
	}
	return 0;
}
