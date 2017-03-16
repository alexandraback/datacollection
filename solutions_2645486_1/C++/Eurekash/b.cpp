#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define For(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define Forr(i,b,a) for(int i=b,_a=a;i>=_a;--i)
#define Rep(i,n) for(int i=0,_n=n;i<_n;++i)
#define Foreach(a,b)\
	for(typeof(b.begin())a=b.begin(); a!=b.end(); ++a)
#define sz(x) ((int)x.size())
#define pb push_back
#define mp make_pair
#define st first
#define nd second

typedef double DB;
typedef long long LL;

const int maxn=10010;

int T,E,R,N,v[maxn],a[maxn],b[maxn];
pair<int,int> p[maxn];
int main()
{
	cin>>T;
	For(num,1,T)
	{
		cin>>E>>R>>N;
		if(R>E) R=E;
		For(i,1,N)  
		{
			cin>>v[i];
			a[i]=0;  b[i]=E;
			p[i]=mp(v[i],i);
		}
		sort(p+1,p+N+1,greater< pair<int,int> > ());
		LL ans=0;
		For(i,1,N)
		{
			int j=p[i].nd;
			if(a[j]>=b[j])  continue;
			ans+=(b[j]-a[j])*v[j];
			For(k,j+1,N)  b[k]=min(b[k],a[j]+R*(k-j));
			Forr(k,j-1,1)  a[k]=max(a[k],b[j]-R*(j-k));
		}
		cout<<"Case #"<<num<<": "<<ans<<endl;
	}
	return 0;
}
