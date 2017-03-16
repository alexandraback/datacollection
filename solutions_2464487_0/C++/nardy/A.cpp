#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;
long long r,t;
int T;

void solve()
{
    cin>>r>>t;
	double delta = (2 * r - 1) * (2 * r - 1) + 8 * t;
	delta = sqrt(delta);
	long long ans = (1 - 2 * r + (int)delta) / 4;
    cout<<ans<<endl;
}
int main()
{
	//freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
	return 0;
}
