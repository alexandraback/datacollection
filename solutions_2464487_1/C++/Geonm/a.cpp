#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<math.h>

using namespace std;

#define MAXN 1000009
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

ll r, t;
void Read() {
	scanf("%lld %lld",&r,&t);
}

void Solve(int kase) {
	int lo=1,hi;
	
	if (r>=1000000000&&r<10000000000000)
		hi=10000;
	if (r>=10000000000000&&r<=1000000000000000)
		hi=1000;
	if (r>1000000000000000&&r<=100000000000000000)
		hi=100;
	if (r>100000000000000000&&r<=1000000000000000000)
		hi=10;
	
	if (r<10000000000)
		hi=707106780;
	
	while (lo<hi) {
		ll mid=(lo+hi+1)/2;
		
		ll p=(ll)((r+1)*(r+1)-r*r)*mid+2*mid*(mid-1);
		
		if (p<=t) {
			lo=mid;
		}
		else
			hi=mid-1;
	}
	
	printf("Case #%d: %d\n",kase,lo);
}

int main () {
	freopen("codejam.in","r",stdin);
	freopen("codejam.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for (int i=1;i<=t;i++) {
		Read();
		Solve(i);
	}
	
	return 0;
}
