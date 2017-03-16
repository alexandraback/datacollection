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

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define ll long long 

template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }

int i,j,k,m,n,l;
double c, f, x;
double ans;

void gao(int n){
    			double a = 2, t = 0;
			repf(j, 1, n)
				t+=c/a, a+=f;
			checkmin(ans, t+x/a);
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
		scanf("%lf%lf%lf", &c, &f, &x);
		ans=x/2;

			int n = (int)( x/c-2/f-1);
		gao(n-1);
        gao(n);
        gao(n+1);
        gao(n+2);
		
		printf("Case #%d: %.7lf\n", te, ans);
    }
    return 0;
}
