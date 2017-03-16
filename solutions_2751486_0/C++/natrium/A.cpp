#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;
const double EPS = 1e-10;
const int MAX = 2000000;

ll solve()
{
	char str[100001];
	int n;
	scanf("%s%d", str, &n);
	int L = strlen(str);
	
	int len = 0;
	rep(i, L){
		char c = str[i];
		if(!(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')){
			++len;
			str[i] = 1;
		}
		else{
			str[i] = 0;
			if(len < n){
				rep(j, len)
					str[i-j-1] = 0;
			}
			len = 0;
		}
	}
	if(str[L-1] && len < n){
		rep(j, len)
			str[L-j-1] = 0;
	}
	
	vi data(1, 0);
	bool boin = true;
	rep(i, L){
		bool isboin = str[i];
		if(boin == isboin)
			data[data.size()-1]++;
		else{
			boin = !boin;
			data.push_back(1);
		}
	}
	if(data.size()%2 == 0)
		data.push_back(0);
	
	ll ans = 0;
	for(int i=0; i*2+1<data.size(); ++i){
		int left = data[i*2];
		int right = data[i*2+2];
		int l = data[i*2+1];
		if(left)  l += n-1;
		if(right) l += n-1;
		ans += (ll)l * (l+1) / 2;
		if(left)  ans -= (ll)n*(n-1)/2;
		if(right) ans -= (ll)n*(n-1)/2;
	}
	
	for(int i=0; 2*i<data.size(); ++i){
		if(data[2*i]){
			ans += (n-1)*(ll)data[2*i] + n-1 - (ll)n*(n-1)/2;
		}
	}
	
	return (ll)L*(L+1)/2 - ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t){
		printf("Case #%d: %lld\n", i+1, solve());
	}
	return 0;
}