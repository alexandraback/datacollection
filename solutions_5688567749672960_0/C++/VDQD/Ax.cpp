#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000000 + 10;

int d[maxN];

int rev(int x){
	int R = 0;
	while (x > 0){
		R = R * 10 + x % 10;
		x /= 10;
	}
	return R;
}

void build(){
    memset(d, -1, sizeof d);
    d[1] = 1;
    queue<int> qu; qu.push(1);
    while (qu.size()){
        int u = qu.front(); qu.pop();
        int R = rev(u);
        //printf("u = %d\n", u);
        if (u+1 < maxN && d[u+1] == -1){
            d[u+1] = d[u] + 1;
            qu.push(u+1);
        }
        if (R < maxN && d[R] == -1){
            d[R] = d[u] + 1;
            qu.push(R);
        }
    }
}

long long solve(long long n){
    return d[n];
}

int main(){
    freopen("A.in", "r", stdin);
    freopen("Ax.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    build();
    while (t--){
    	long long n;
    	scanf("%lld", &n);
    	printf("Case #%d: %lld\n", ++cases, solve(n));
    }
	return 0;
}

