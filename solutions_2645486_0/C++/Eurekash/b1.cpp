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
int T,E,R,N,v[maxn];
int ans=0;
void dfs(int i,int e,int V)
{
	if(i>N)  {
		if(ans<V) ans=V;
		return ;
	}
	For(j,0,e)  dfs(i+1,min(E,e-j+R),V+j*v[i]);
}
int main()
{
	cin>>T;
	For(num,1,T)
	{
		cin>>E>>R>>N;
		ans=0;
		For(i,1,N)  cin>>v[i];
		dfs(1,E,0);
		cout<<"Case #"<<num<<": "<<ans<<endl;
	}
	return 0;
}
