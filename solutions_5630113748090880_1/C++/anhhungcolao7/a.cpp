
#include <bits/stdc++.h>
#define fi "a.inp"
#define fo "a.out"
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define All(x) x.begin(),x.end()
#define st first
#define nd second
#define It interator
#define sl_int(x) __builtin_popcount(x)

using namespace std;

typedef pair<int,int> II;
typedef pair<int,II> III;
typedef long long ll;
typedef pair<ll,ll> LL;
set <II> th;
struct Point 
{
	int x,y;
	bool operator <(const Point &T)
	{
			if (x==T.x) return (y<T.y);
			return (x<T.x);
	}
};

int x,n,test,f[2501];
int main()
{
	freopen (fi, "r", stdin);
	freopen (fo, "w", stdout);
	scanf("%d",&test);
	For(Test,1,test)
	{
		printf("Case #%d: ",Test);
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		For(i,1,2*n-1)
		{
			For(j,1,n) {
				scanf("%d",&x);
				f[x]++;
			}
		}
		For(i,1,2500) if (f[i]%2==1) {
			cout<<i<<" ";
		}
		puts("");
	}
	return 0;
}
