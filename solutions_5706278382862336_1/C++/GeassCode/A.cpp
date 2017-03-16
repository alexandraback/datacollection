#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define LL long long
int check(LL x)
{
	while(x>1){
		if(x%2)return 0;
		x/=2;
	}
	return 1;
}
LL gcd(LL a,LL b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	LL a,b,d;
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%I64d/%I64d",&a,&b);
		int cnt=0;
		while((a!=b)&&a>0){
			cnt++;
			if(2*a>=b){
				a=2*a-b;
				d=gcd(a,b);
				a/=d;
				b/=d;
				if(!check(b))cnt=-1;
				break;
			}else a=2*a;
		//	printf("%d %d\n",a,b);
		}
		printf("Case #%d: ",cas);
		if(cnt<0)printf("impossible\n");
		else printf("%d\n",cnt);
	}
	return 0;
}

