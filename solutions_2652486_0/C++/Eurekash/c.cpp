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

int R,N,M,K,k,a[13],b[3];
bool vis[13];
void dfs(int i,int P)
{
	if(i==N)
	{
		Rep(j,k)  if(a[j]==P)  
		{
			vis[j]=true;
			break;
		}
		return; 
	}
	dfs(i+1,P*b[i]);
	dfs(i+1,P);
}
bool check(int p,int q,int r)
{
	b[0]=p;b[1]=q;b[2]=r;
	memset(vis,0,sizeof vis);
	dfs(0,1);
	Rep(i,k)  if(!vis[i])  return false;
	return true;
}
int main()
{
	int T;
	cin>>T;
	cout<<"Case #1:\n";
	cin>>R>>N>>M>>K;
	Rep(i,R)
	{
		Rep(j,K)   cin>>a[j];
		sort(a,a+K); k=unique(a,a+K)-a;
		int r1=0,r2=0,r3=0;
		For(n1,2,5)  For(n2,2,5)  For(n3,2,5)
			if(check(n1,n2,n3))  r1=n1,r2=n2,r3=n3;
		cout<<r1<<r2<<r3<<endl;
	}
	return 0;
}
