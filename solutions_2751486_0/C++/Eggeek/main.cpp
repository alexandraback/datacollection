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
#define maxn 150

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
int n;
char str[maxn];
int judge(char c)
{
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 0;
	return 1;
}
int getval(int l,int r)
{
	int i,res=0,ans=0;
	for ( i=l ; i<=r ; i++ )
	if (judge(str[i])) res++;
	else
	{
		ans = max(ans,res);
		res=0;
	}
	ans = max(ans,res);
	return ans;
}
void solv()
{
	int i,j,len,ans=0;
	len = strlen(str);
	for ( i=0 ; i<len ; i++ )
	for ( j=i ; j<len ; j++ )
	{
	//	for (int k=i ; k<=j ; k++ )	printf("%c",str[k]);printf("\n");
		int tmp = getval(i,j);
	//	printf("%d\n",tmp);
		if (tmp >= n) ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	int cas,tt=0;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);

	scanf("%d",&cas);
	while (cas--)
	{
		printf("Case #%d: ",++tt);
		scanf("%s%d",str,&n);
		solv();
	}
	return 0;
}
