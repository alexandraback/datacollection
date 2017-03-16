#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm> 
#include <iostream>
#include <cmath>
using namespace std;
int t,lol[10000005];
long long a,b;

bool pal(long long x){
	int a[200];
	int s = 0;
	while (x > 0){
		a[++s] = x%10LL;
		x/=10LL;
	}
	for (int i = 1; i <= s; ++i)
		if (a[i] != a[s-i+1]) return 0;
	return 1;
}

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	lol[0] = 0;
	for (long long i = 1; i <= 10000000; ++i){
		lol[i] = lol[i-1];
		if (pal(i)){
			if (pal(i*i)){
				lol[i]++;
			}
		}
	}
	scanf("%d",&t);
	int tc = 0;
	while (tc <t){
		printf("Case #%d: ",++tc);
		scanf("%lld %lld",&a,&b);
		a = ceil(sqrt(a))-1LL;
		b = floor(sqrt(b));
		printf("%d\n",lol[b]-lol[a]);
	}
}