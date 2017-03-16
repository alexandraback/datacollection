#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

#define ll long long
#define eps 1e-8
#define inf 0x3f3f3f3f

char s[10001];
string s0,hehe;
int p[110][1100];
int main()
{
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
	int T,cas=0,n,t;
	cin>>T;
	while (T--)
	{
		int A,B,K,ans=0;
		cin>>A>>B>>K;
		for (int i=0;i<A;i++)
			for (int j=0;j<B;j++)
				if ((i&j)<K) ans++;
		printf("Case #%d: ",++cas);
		cout<<ans<<endl;
	}
}