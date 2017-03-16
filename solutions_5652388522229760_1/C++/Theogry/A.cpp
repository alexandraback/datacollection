#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define pb(x) push_back(x)
#define ppb() pop_back()
#define mp(x,y) make_pair(x,y)
#define LL long long
#define ULL unsigned long long
#define eps 1e-9
#define pi acos(-1.0)
LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

int t, n;
int ap[6001];

bool ok(){
	FOE(i, 0, 9) if (!ap[i]) return false;
	return true;
}

void ax(int di){
	while (di){
		ap[di%10] = 1; di /= 10;
	}
}

void solve(){
	scanf("%d", &n);
	if (n == 0) puts("INSOMNIA");
	else {
		FOE(i, 0, 9) ap[i] = 0;
		ax(n);
		int base = n;
		while (!ok()){
			n += base;
			ax(n);
		}
		printf("%d\n", n);
	}
}

int main(){
	scanf("%d", &t);
	FOE(i, 1, t){
		printf("Case #%d: ", i);
		solve();
	}

    return 0;
}
