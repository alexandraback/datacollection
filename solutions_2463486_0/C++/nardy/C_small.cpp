#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;
int dig[30],fs[1003],A,B,T,sum = 0;
bool v[1003];
bool check(int x)
{
    int cnt = 0;
	while(x){
	   dig[++ cnt] = x % 10; x /= 10;
	}
	rep(i,1,cnt >> 1)
	if(dig[i] != dig[cnt - i + 1]) return false;
	return true;
}
void ready()
{
	v[1] = true;
    for(int i = 1;i <= 1000;++ i)
	if(check(i)){
	   if(v[i]) fs[++ sum] = i;
	   if(i * i <= 1000) v[i * i] = true;
	}
}
void solve()
{
    scanf("%d%d",&A,&B);
	int ans = upper_bound(fs + 1,fs + sum + 1,B) - lower_bound(fs + 1,fs + sum + 1,A);
	printf("%d\n",ans);
}
int main()
{
	//freopen("input","r",stdin); freopen("output","w",stdout);
    ready();
	scanf("%d",&T);
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
	return 0;
}
