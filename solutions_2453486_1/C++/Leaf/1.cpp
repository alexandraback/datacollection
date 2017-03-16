#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<functional>
#include<iostream>
#include<map>
#include<bitset>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define MP(a,b) make_pair(a,b)
#define clr(x,y) memset(x,y,sizeof x)
#define fi first
#define se second
#define LL long long
#define sqr(z) ((z)*(z))
using namespace std;
typedef pair<int,int> PII;
const int oo=1047483647,maxn=310;
int n,i,j,k,m,q,kind,ge[300],T;
char s[6][6];
bool flag;
void check()
{
    		if (ge['X']==4)
			{
				kind=1;
			}
			if (ge['O']==4)
			{
				kind=2;
			}
			if (ge['T']==1)
			{
                if (ge['X']==3)
				{
					kind=1;
				} else
				if(ge['O']==3)
				{
					kind=2;
				}
			}
			if (ge['.']) flag=1;
}
int main()
{
//	freopen("1.in","r",stdin);
 // freopen("1.out","w",stdout);
	scanf("%d\n",&T);
	int z;
	fo(z,1,T)
	{
		scanf("%s",s[1]+1);
		scanf("%s",s[2]+1);
		scanf("%s",s[3]+1);
		scanf("%s",s[4]+1);
		flag=0;kind=0;
		fo(i,1,4)
		{
			memset(ge,0,sizeof ge);
			fo(j,1,4)
			ge[s[i][j]]++;
	        check();
		}
		fo(j,1,4)
		{
			memset(ge,0,sizeof ge);
			fo(i,1,4)
			ge[s[i][j]]++;
	        check();
		}
	memset(ge,0,sizeof ge);
	ge[s[1][1]]++;
	ge[s[2][2]]++;
	ge[s[3][3]]++;
	ge[s[4][4]]++;
	check();
	memset(ge,0,sizeof ge);
	ge[s[1][4]]++;
	ge[s[2][3]]++;
	ge[s[3][2]]++;
	ge[s[4][1]]++;
	check();
		printf("Case #%d: ",z);
		if (!kind)
		{
			if (!flag)puts("Draw");
			else puts("Game has not completed");
		} else
		{
			if (kind==1) puts("X won");
			else puts("O won");
		}
	}
	return 0;
}
