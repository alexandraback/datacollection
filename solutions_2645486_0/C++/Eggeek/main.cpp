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
#define maxn 1010
#define maxe 10000010
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
int E,R,N,v[maxn];
void input()
{
	int i;
	scanf("%d%d%d",&E,&R,&N);
	for ( i=0 ; i<N ; i++ ) scanf("%d",&v[i]);
}
void solv1()
{
	LL dp[20][1000];
	memset(dp,-1,sizeof(dp));
	int i,j,k;

	for ( j=0 ; j<=E ; j++ )
	{
		LL tmp = v[0]*j;
		int tmp2 = min(E,E-j+R);
		if (tmp >= dp[0][tmp2]) dp[0][tmp2] = tmp;
	}

	for ( i=0 ; i<N-1 ; i++ )
	for ( j=0 ; j<=E ; j++ )
	if (dp[i][j] != -1)
	{
		for ( k=0 ; k<=j ; k++ )
		{
			LL tmp = v[i+1]*k;
			int tmp2 = min(E,j-k+R);
			if (dp[i][j]+tmp >= dp[i+1][tmp2]) dp[i+1][tmp2] = dp[i][j]+tmp;
		}
	}
	LL ans=0;
	for ( i=0 ; i<=E ; i++ )
	if (dp[N-1][i] >= ans) ans = dp[N-1][i];
	cout<<ans<<endl;
}
int main()
{
	int cas,tt=0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);

	scanf("%d",&cas);
	while (cas--)
	{
		printf("Case #%d: ",++tt);
		input();
		if (N<=10 && R<=5 && E<=5) solv1();
	}
	return 0;
}
