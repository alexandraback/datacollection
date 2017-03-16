#include <iostream>
#include <algorithm>
#include <vector>

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

#define D 100

int c, d, v;
bool a[D+10], flag[D+10];
int cnt;

bool check(){
	vector<int> vec;
	memset(flag, 0, sizeof(flag));

	repf(i, 1, v) if (a[i]) vec.push_back(i);
	
	int n = sz(vec);
	rep(i, 1<<n){
		int cnt=0;
		rep(j, n) if ((1<<j)&i)
			cnt+=vec[j];
		flag[cnt] = 1;	
	}
	repf(i, 1, v) if (!flag[i]) return false;
	return true;
}

int solve(){
	int ret = 0;
	while (!check()){
		repf(i, 1, v) if (!flag[i]){
			a[i]=1;
			ret++;
			break;
		}
	}
	return ret;
}

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%d%d%d", &c, &d, &v);
		memset(a, 0 , sizeof(a));
		int k;
		rep(i, d){
			scanf("%d", &k);
			a[k] = 1;
		}
		printf("Case #%d: %d\n", te, solve());
	}
	return 0;
}
