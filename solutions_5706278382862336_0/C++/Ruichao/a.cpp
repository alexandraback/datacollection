#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int t;

long long tt;
char ch;

int main(){
	long long a,b;
	int ans;
	double cur,cri;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for ( int i = 1; i <= t; ++ i){
		printf("Case #%d: ",i);
		scanf("%lld%c%lld",&a,&ch,&b);
		tt = (long long) 1 << 40;
		if (tt % b != 0) printf("impossible");
		else{
			ans = 0;
			a = tt / b * a;
			while (tt > a){
				++ ans;
				tt = tt >> 1;
			}
			printf("%d",ans);
		}
		printf("\n");
	}

	return 0;
}
