#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int t,ind,i,s;
	char str[1005];
	getint(t);
	rep(ind,1,t)
	{
		printf("Case #%d: ",ind);
		getint(s);
		scanf("%s",str);
		int val=0,co=0,len=strlen(str);
		if(len==0)
		{
			putintln(0);
			continue;
		}
		val=str[0]-'0';
		rep(i,1,len-1)
		{
			co=co+max(i-val,0);
			val=val+max(i-val,0);
			val=val+str[i]-'0';
		}
		putintln(co);
	}
}