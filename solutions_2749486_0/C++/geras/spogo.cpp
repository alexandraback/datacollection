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
int X,Y,A,B;
void solve() {
	scanf("%d%d",&X,&Y);
	A=B=0;
	while(A<X) {
		printf("WE");
		A++;
	}
	while(A>X) {
		printf("EW");
		A--;
	}
	while(B<Y) {
		printf("SN");
		B++;
	}
	while(B>Y) {
		printf("NS");
		B--;
	}
	printf("\n");
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
