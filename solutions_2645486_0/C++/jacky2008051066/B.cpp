#include<iostream>
using namespace std;

typedef __int64 I;

const int N= 10004;
I val[N];

I comMax(I u, I v){
	if(u > v)
		return u;
	else
		return v;
}

int main(){
	freopen("B.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas= 1; cas <= T; cas++){
		I e, r;
		int n;
		scanf("%I64d%I64d%d", &e, &r, &n);
		int maxInd;
		I maxx= 0;
		for(int i= 1; i <= n; i++){
			scanf("%I64d", val+i);
			if(val[i] > maxx){
				maxInd= i;
				maxx= val[i];
			}
		}
		I ans;
		if(r >= e){
			ans= 0;
			for(int i= 1; i <= n; i++)
				ans+= val[i]*e;
			printf("Case #%d: %I64d\n", cas, ans);
			continue;
		}
		ans= 0;
		for(int i= 1; i <= n; i++){
			if(i == maxInd)
				ans+= val[i]*e;
			else
				ans+= val[i]*r;
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}