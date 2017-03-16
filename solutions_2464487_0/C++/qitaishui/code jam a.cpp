#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
const double pi = acos(-1);
long long gao(long long r)
{
	return (r+1)*(r+1)-r*r;
}
int main()
{
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	long long ans,ret;
	long long r,t;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		ans = 0;
		cin>>r>>t;
		for(long long i = r; ; i+=2)
		{
			ret = gao(i);
			if(t>=ret) t-=ret,ans++;
			else break;
		}
		cout<<"Case #"<<ca<<": ";
		cout<<ans<<"\n";
	}

    return 0;
}


