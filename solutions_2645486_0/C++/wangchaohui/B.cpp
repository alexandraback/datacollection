#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
#define SIZE(x) ((int)(x).size())
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for0r(i,n) for(int i=(n)-1;i>=0;i--)
#define for1r(i,n) for(int i=(n);i>=1;i--)
typedef long long ll;

int f[100][12];

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	int T,TC=0;
	scanf("%d",&T);
	while (++TC<=T)
	{
		printf("Case #%d: ",TC);
		int n,e,r;
		scanf("%d %d %d",&e,&r,&n);
		checkmin(r,e);
		memset(f,0,sizeof(f));
		for1(i,n)
		{
			int t;
			scanf("%d",&t);
			for0(j,e+1)
			{
				int jj=min(e,j+r);
				for0(k,jj+1)
				{
					checkmax(f[i][jj-k],f[i-1][j]+k*t);
				}
			}
		}
		printf("%I64d\n",f[n][0]);
	}
	return 0;
}
