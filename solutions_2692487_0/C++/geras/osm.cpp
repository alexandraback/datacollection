// Author: Kamil Niziński
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define debug(fmt,...) fprintf(stderr,fmt, ## __VA_ARGS__)
#define mp make_pair
#define ft first
#define sd second
using namespace std;
typedef long long int ll;
typedef long long unsigned llu;
typedef double dd;
//const int inf=1000000009;
int A,n,T[101],odp;
void solve() {
	int i,added=0,wsk;
	scanf("%d%d",&A,&n);
	for(i=0;i<n;i++) scanf("%d",&T[i]);
	if(A==1) {
		printf("%d\n",n);
		return;
	}
	odp=n;
	sort(T,T+n);
	wsk=0;
	while(wsk<n) {
		while(wsk<n&&A>T[wsk]) {
			A+=T[wsk];
			wsk++;
		}
		odp=min(odp,added+(n-wsk));
		added++;
		A+=A-1;
	}
	printf("%d\n",odp);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
