#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "A.INP"
#define fo "A.OUT"
#define nmax 1000000+5
#define INF 1000000000
using namespace std;
typedef long long ll;
//VARIABLES
int n,S,res,a[nmax];
ll m;
//MAIN
int main()
{
	int test;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&test);
       for (int tc=1;tc<=test;++tc)
       {
	       scanf("%d%d",&res,&n);m=ll(res);S=0;res=INF;
       	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
       	sort(a+1,a+n+1);
       	for (int i=1;i<=n;++i)
       	{
			res=min(res,n+1-i+S);
			if (m==1)
			{
				S=n;
				break;
			}
			while (m<=a[i])
			{
				m+=(m-1);
				++S;
			}
			m+=a[i];
		}
		res=min(res,S);
		printf("Case #%d: %d\n",tc,res);
	}
       return 0;
}
