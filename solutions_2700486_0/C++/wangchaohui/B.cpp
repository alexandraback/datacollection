#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
using namespace std;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
#define SIZE(x) ((int)(x).size())
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for0r(i,n) for(int i=(n)-1;i>=0;i--)
#define for1r(i,n) for(int i=(n);i>=1;i--)
typedef long long ll;

int S[10000];

double C[3000][3000];

void init_C()
{
	for(int i=0;i<3000;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	//freopen("C-large.in","r",stdin);
	//freopen("C-large.out","w",stdout);
	for(int i=1;i<=2000;i++)
	{
		S[i]=(i+1)*i/2;
	}
	init_C();
	int T,TC=0;
	scanf("%d",&T);
	while (++TC<=T)
	{
		printf("Case #%d: ",TC);
		int N,x,y;
		scanf("%d %d %d",&N,&x,&y);
		int h=1;
		while(S[h+2]<=N)h+=2;
		int n = N - S[h];
		int xh = (abs(x)+y)+1;
		if(xh<=h)puts("1.0");
		else if(xh>h+2)puts("0.0");
		else
		{
			h+=2;
			int m = y+1;
			if(m==h)
			{
				puts(n==2*h-1?"1.0":"0.0");
			}
			else
			{
				double ss = 0;
				for(int i = max(0,n-h+1) ; i < m; i++)
				{
					ss+=C[n][i];
				}
				double s=0;
				for(int i = m ; i < h; i++)
				{
					s+=C[n][i];
				}
				ss+=s;
				//printf("%d %d %d\n",h,n,m);
				printf("%.10f\n",s/ss);
			}
		}
	}
	return 0;
}
