#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<map>
#include<cmath>
//#include<iostream>
using namespace std;

#define LL long long int

LL gcd(LL a,LL b)
{
	if(a*b == 0) return a+b;
	if(a >= b) {
		LL tmp = a;
		a = b;
		b = tmp;
	}
	return gcd(a, b%a);
}
int gg = 0;
LL get(const char *str)
{
	LL ret = 0;
	int lx;
	for(lx = 0;str[lx] != '\0' and str[lx] != '/';lx++){
		ret = ret*10 + (str[lx] - '0');
	}
	gg = lx;
	return ret;
}
int main()
{
	int T; scanf("%d",&T);
	for(int lT=1; lT<=T ;lT++)
	{
		char str[1000];
		long long int a,b;
		bool imp = false;
		scanf("%s",str);
		a = get(str);
		b = get(str + gg + 1);
		//printf("%lld/%lld = %lld\n",a,b,gcd(a,b));
		long long int c= gcd(a,b);
		a /= c;
		b /= c;
		int cnt=1;
		LL bb = b;
		while(bb > 1){
			if(bb%2 == 1) imp = true;
			bb /= 2;
		}
		if(imp){
			printf("Case #%d: impossible\n",lT);
			continue;
		}
		if(2*a >= b){
			printf("Case #%d: 1\n",lT);
			continue;
		}

		while(2*a < b){
			cnt++;
			a <<= 1;
		}
		
		printf("Case #%d: %d\n",lT,cnt);
	}
	return 0;
}

