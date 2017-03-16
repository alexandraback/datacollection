#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#define fi "C-small-attempt0.in"
#define fo "C-small-attempt0.out"
//#define fi "Q_C.INP"
//#define fo "Q_C.OUT"
#define nmax
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef set<int> SI;
//VARIABLES
int m,n,k,t,ten[20];
ll res;
SI my_set;
//MAIN
int main()
{
	int test;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
	scanf("%d",&test);
	ten[0]=1;
       for (int i=1;i<=8;++i) ten[i]=ten[i-1]*10;
       for (int tc=1;tc<=test;++tc)
	{
		res=0ll;
	       scanf("%d%d",&m,&n);
       	for (int i=m;i<=n;++i)
	       {
			k=1;while (i>=ten[k]) ++k;--k;
			my_set.clear();
			for (int j=1;j<=k;++j)
			{
				t=(i/ten[j])+(i%ten[j])*ten[k+1-j];
				if ((t>=ten[k]) && (t<=ten[k+1]) && (t<i) && (t>=m))
				my_set.insert(t);
			}
			res+=ll(my_set.size());
		}
		printf("Case #%d: ",tc);cout << res << endl;
	}
       return 0;
}

