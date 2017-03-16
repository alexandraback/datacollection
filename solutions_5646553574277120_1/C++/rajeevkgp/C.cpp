#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <string.h>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef vector<int> vi;

void FJ(){
    #ifndef ONLINE_JUDGE
        freopen("C.in","r",stdin);
        freopen("C.out","w",stdout);
    #endif
}

#define MAX 1000000007
#define MOD 1000000007
#define FT first
#define SE second
#define SZ size()
#define BG begin()
#define EN end()
#define SP system("pause")
#define PB(a) push_back(a)
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define PT(a) printf("%d\n",a)
#define GT(a) int a;scanf("%d",&a)
#define MS(a,b) memset(a,b,sizeof(a))
#define FI freopen("I.txt","r",stdin)
#define FO freopen("O.txt","w",stdout)
#define rev(i,n) for(int i=n;i>=0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define take(ar,n) int ar[n]; rep(i,n) cin>>ar[i]
#define foreach(V,it) for(typeof((V).BG)it=(V.BG);it!=V.EN;it++)
#define show(ar,n) rep(i,n+1) printf("%d%c",ar[i],(i == n)?'\n':' ');

int main()
{
    FJ();
    GT(test);
	rep(zz,test)
	{
		ll c,d,v;
		cin>>c>>d>>v;
		ll ar[d];
		rep(i,d) cin>>ar[i];
		ll r=0,tot=0;
		for(int i=0;i<d;i++)
		{
			if(r>=v) break;
			if(ar[i]>(r+1))
			{
				r+=c*(r+1);
				tot++;
				i--;
			}
			else r+=ar[i];
		}
		while(r<v)
		{
			r+=c*(r+1);
			tot++;
		}
		printf("Case #%d: %lld\n",zz+1,tot);
	}
    return 0;
}