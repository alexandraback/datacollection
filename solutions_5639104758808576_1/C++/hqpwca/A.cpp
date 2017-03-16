#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<functional>
#include<string>
#define INF 1000000007
#define ll long long
#define rep(i,k) for(int i=G.start[k];i!=INF;i=G.next[i])

using namespace std;

int n,a[1005];
string s;

int main()
{
freopen("t.in","r",stdin);
freopen("t.out","w",stdout);
	ios::sync_with_stdio(false);
	
    int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		int ans=0;
		cin>>n>>s;
		for(int i=0;i<=n;i++)
			a[i]=s[i]-'0';
		
		int sum=0;
		for(int i=0;i<=n;i++)
		{
			while(sum<i)ans++,sum++;
			sum+=a[i];
		}
		
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	
	return 0;
}
