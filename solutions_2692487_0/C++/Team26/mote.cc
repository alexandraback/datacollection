#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int t, a, n, ar[105];

main() {
    freopen("mote.in", "r", stdin);
    freopen("mote.out", "w", stdout);
    scanf("%d", &t);
    for(int test=1;test<=t;test++) {
	scanf("%d %d", &a, &n);
	for(int i=0;i<n;i++) scanf("%d", &ar[i]);
	sort(ar, ar+n);
	int ans=(1<<29), cur=0, sz=a;
	for(int i=0;i<n;i++) { //remain = n-i including this
	    ans = min(ans, cur + n-i); //get rid of all motes [i, n)
	    if(sz == 1) {
		cur=(1<<29);
		break;
		}
	    while(sz <= ar[i]) { //need to be larger
		sz += sz-1; //add one smaller
		cur++;
		}
	    sz += ar[i];
	    }
	ans = min(ans, cur);
	printf("Case #%d: %d\n", test, ans);
	}
    }






