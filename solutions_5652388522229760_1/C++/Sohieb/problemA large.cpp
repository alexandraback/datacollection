#include <bits/stdc++.h>
#include <ext/numeric>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

#define oo			1e9
#define OO			1e18
#define EPS			1e-7
#define f			first
#define s			second
#define pi 			acos(-1.0)
#define ll			long long
#define ld			long double
#define ull			unsigned long long
#define sz(x)		(int)x.size()
#define all(x)		x.begin(),x.end()
#define rall(x)		x.rbegin(),x.rend()
#define popCnt(x)   __builtin_popcount(x)

int T;
int n;
int arr[10];

void getDigits(long long cur){
	while(cur){
		arr[cur%10]=1;
		cur/=10;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("A-large.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%d",&T);
	for(int C=1;C<=T;C++){
		scanf("%d",&n);
		if(n==0){
			printf("Case #%d: INSOMNIA\n",C);
			continue;
		}
		memset(arr,0,sizeof arr);
		for(int i=1;;i++){
			getDigits(1LL*i*n);
			int sum=0;
			for(int i=0;i<10;i++)
				sum+=arr[i];
			if(sum==10){
				printf("Case #%d: %d\n",C,i*n);
				break;
			}
		}
	}
}
