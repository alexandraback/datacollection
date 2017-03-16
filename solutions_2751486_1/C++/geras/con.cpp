// Author: Kamil Niziński
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <algorithm>
#define debug(fmt,...) fprintf(stderr,fmt, ## __VA_ARGS__)
#define mp make_pair
#define ft first
#define sd second
#define psb push_back
#define ppb pop_back
using namespace std;
typedef long long int ll;
typedef long long unsigned llu;
typedef double dd;
ll odp=0ll;
int k,n;
char T[1000009];
bool consonant(char c) {
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 0;
	return 1;
}
void solve() {
	scanf("%s",T);
	scanf("%d",&k);
	n=strlen(T);
	odp=0ll;
	int last=-1,i,cons_q=0;
	for(i=0;i<n;i++) {
		if(consonant(T[i])) cons_q++;
		else cons_q=0;
		if(cons_q>=k) last=i-k+1;
		if(last!=-1) odp+=1ll*(1ll+last);
	}
	printf("%lld\n",odp);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
