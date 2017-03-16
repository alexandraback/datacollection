#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;

char buf[32];
string s, t;
vector<LL> v;

inline bool is_par(LL x){
	sprintf(buf, "%lld", x);
	s = t = buf;
	reverse(t.begin(), t.end());
	return s == t;
}

int solve(){
	LL a, b;
	scanf("%lld%lld", &a, &b);
	return upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
}

int main(){
	for(LL i = 1; i <= 3069307; ++i){
		if(!is_par(i)){ continue; }
		LL k = i * i;
		if(is_par(k)){
			v.push_back(k);
		}
	}
	
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		printf("Case #%d: %d\n", i, solve());
	}
}
