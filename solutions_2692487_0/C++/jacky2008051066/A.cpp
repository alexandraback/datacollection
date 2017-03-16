#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N= 1000009;
int r[N];
typedef __int64 I;

struct node{
	int step;
	I ar;
};

bool cmp(const int r1, const int r2){
	return r1 < r2;
}

node countStep(I ar, int ri){
	node nd;
	nd.ar= ar; nd.step= 0;
	while(1){
		if(nd.ar > ri){
			nd.ar += ri;
			break;
		}else{
			nd.ar= nd.ar+nd.ar-(I)1;
			nd.step++;
		}
	}
	return nd;
}

int main(){
	freopen("A.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas= 1; cas <= T; cas++){
		int ar, n;
		scanf("%d%d", &ar, &n);
		for(int i= 1; i <= n; i++)
			scanf("%d", r+i);
		sort(r+1, r+n+1, cmp);
		int ans= n;
		if(ar == 1){
			printf("Case #%d: %d\n", cas, n);
			continue;
		}
		int cnt= 0;
		node nd;
		nd.ar= ar;
		for(int i= 1; i <= n; i++){
			nd= countStep(nd.ar, r[i]);
			cnt+= nd.step;
			if(cnt+n-i < ans)
				ans= cnt+n-i;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}