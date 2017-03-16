//#include <algorithm>

//#include <cstdio>

#include <cmath>
#include <cstdio>
#include <iostream>

//#include <iostream>

//#include <map>
//#include <utility>

//#include <vector>

using namespace std;

typedef long long int big;

int cas;
big gcd(big a,big b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main() {
	big p,q,qq;
	freopen("a.in", "r", stdin);
	freopen("a.txt", "w", stdout);
	int cass;
	scanf("%d",&cas);
	for(cass=1; cass<=cas;cass++) {
		printf("Case #%d: ",cass);
		scanf("%lld/%lld",&p,&q);
		big d=gcd(p,q);
		p/=d;q/=d;
		qq=q;
		while(qq%2==0)qq/=2;
		if(qq!=1)
		{
			puts("impossible");
			continue;
		}
		int i;
		for(i=1;q>1;i++)
		{
			if(p+p>=q)break;
			q/=2;
		}
		int res=i;
		printf("%d\n",res);
	}
}
