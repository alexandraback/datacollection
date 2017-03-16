#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>

#define SZ 1005
#define INF (1<<29)
using namespace std;

typedef long long Long;

int d;
int P[SZ];


int Calc(int mid,int mx)
{
	for(int i=1;i<=mx;i++) {
		int sum = 0;
		for(int j=1;j<=d;j++) {
			if(P[j] <= i) {
				///sum += P[j];
			}
			else {
				sum += P[j]/i;
				if(P[j]%i==0) sum--;
			}
		}
		sum += i;
		if(sum <= mid) return sum;
	}

	return mx;
}


int main()
{
	int tst,cas;
	freopen("Pancake.in.txt","rt",stdin);
	freopen("Pancake.out","wt",stdout);
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		scanf("%d",&d);
		int lo , hi , mid , ans  ,mx;
		lo = 1; hi = 1;
		for(int i=1;i<=d;i++) scanf("%d",&P[i]) , hi = max(hi,P[i]);
		ans = hi; mx = hi;


		while(lo<=hi) {
			mid = (lo+hi)/2;
			if(Calc(mid,mx) <= mid) ans = mid , hi = mid-1;
			else lo = mid+1;
		}
		printf("Case #%d: %d\n",cas,ans);
	}


	return 0;
}