#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
using namespace std;
template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define ll long long 
#define N 1000

int i,j,k,m,n,l;
double a[N+10], b[N+10];

int gao1(){
	int ret=0, j=0;
	rep(i, n){
		if (j<n && b[j]<a[i]) ret++, j++;
	}
	return ret;
}

int gao2(){
	int j=0, ret=n;
	rep(i, n){
		while (b[j]<a[i] && j<n) j++;
		if (j<n && b[j]>a[i]) ret--, ++j;
	}
	return ret;
}

int main(){
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
		scanf("%d", &n);
		rep(i, n) scanf("%lf", &a[i]);
		rep(i, n) scanf("%lf", &b[i]);
		sort(a, a+n), sort(b, b+n);
		
		printf("Case #%d: %d %d\n", te, gao1(), gao2());
    }
    return 0;
}
