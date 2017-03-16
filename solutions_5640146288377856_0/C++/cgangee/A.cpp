#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())

int n, m, l;

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%d%d%d", &n, &m, &l);
		int tmp = (n-1)*(m/l);
		int ans = m/l - 1;
		m -= ans*l;
		ans += l;
		if (m != l) ans+=1;
		printf("Case #%d: %d\n", te, ans+tmp);
	}	
	return 0;
}
