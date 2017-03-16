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

int d,a[1005];

int main()
{
	freopen("t.out","w",stdout);
	ios::sync_with_stdio(false);
	
    int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		int ans=INF,mx=0;
		cin>>d;
		for(int i=0;i<d;i++)
		{
			cin>>a[i];
			mx=max(a[i],mx);
		}
		for(int i=mx;i>0;i--)
		{
			int sum=i;
			for(int j=0;j<d;j++)
			{
				int res=a[j]/i-1;
				if(a[j]%i)res++;
				sum+=res;
			}
			ans=min(ans,sum);
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	
	return 0;
}
