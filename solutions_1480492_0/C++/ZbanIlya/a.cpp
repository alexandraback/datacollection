#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:256000000")

const int maxn=101000, mod=1000000007;
const double eps=1e-9;



int n;
long double ans=1e15;
char c[maxn];
long double s[maxn],p[maxn],d[maxn];
bool f=false;


char gg(char c) {
	if (c=='L') return 'R';
	else return 'L';
}

bool check(char cc, long double dd) {
	for (int i=0; i<n; i++)
		if (cc==c[i] && abs(d[i]-dd)<5+eps) 
			return false;
	return true;
}

bool dfs(long double globtime) {
	long double t=1e15;
	int ci,cj;
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) if (i!=j && abs(s[i]-s[j])>eps && c[i]==c[j]) {
			long double x=d[j]-d[i]-5;
			x/=s[i]-s[j];
			if (x>0 && t-x>eps) {
				t=x;
				ci=i; cj=j;
			}
		}
	if (t>1e14) {
		f=true;
		return true;
	}
	for (int i=0; i<n; i++)
		d[i]+=s[i]*t;
	if (check(gg(c[ci]),d[ci])) {
		c[ci]=gg(c[ci]);
		if (dfs(globtime+t)) return true;
		c[ci]=gg(c[ci]);
	}
	if (check(gg(c[cj]),d[cj])) {
		c[cj]=gg(c[cj]);
		if (dfs(globtime+t)) return true;
		c[cj]=gg(c[cj]);
	}
	if (!check(gg(c[ci]),d[ci]) && !check(gg(c[cj]),d[cj])) {
		ans=min(ans,globtime+t);
	}
	for (int i=0; i<n; i++) 
		d[i]-=s[i]*t;
}


int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cout.precision(20);
	int tests;
	scanf("%d",&tests);
	for (int test=0; test<tests; test++) {
		ans=1e15;
		f=false;
		scanf("%d",&n);
		for (int i=0; i<n; i++) 
			//scanf("%c%lf%lf",&c[i],&s[i],&p[i]), d[i]=p[i];
			cin >> c[i] >> s[i] >> p[i], d[i]=p[i];
		dfs(0);

		cout << "Case #" << test+1 << ": ";
		if (f) cout << "Possible";
		else cout << ans;
		cout << endl;
	}

	return 0;
}