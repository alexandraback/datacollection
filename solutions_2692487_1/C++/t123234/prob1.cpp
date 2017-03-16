#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct{
	int a1, a2, o1, o2;
} dpt;

vector<int> m;
dpt dp[101];

void expand(const int& org, const int& dst, const int& po, int& a, int& o){
	a = org;
	o = po;
	while (a<=dst) {
		a += a-1;
		o++;
	}
	a+=dst;
}

void solve(int idx){
	if (dp[idx-1].o1<dp[idx-1].o2 || (dp[idx-1].o1==dp[idx-1].o2 && dp[idx-1].a1>dp[idx-1].a2)) {
		dp[idx].o1 = dp[idx-1].o1+1;
		dp[idx].a1 = dp[idx-1].a1;
	} else {
		dp[idx].o1 = dp[idx-1].o2+1;
		dp[idx].a1 = dp[idx-1].a2;
	}
	int ta, to;
	expand(dp[idx-1].a1, m[idx], dp[idx-1].o1, ta, to);
	expand(dp[idx-1].a2, m[idx], dp[idx-1].o2, dp[idx].a2, dp[idx].o2);
	if (to<dp[idx].o2 || (to==dp[idx].o2 && ta>dp[idx].a2)) {
		dp[idx].o2=to;
		dp[idx].a2=ta;
	}
}

int main(){
	int t, a, n, i, j, k;
	cin >> t;	
	for (i=0; i<t; ++i) {
		cin >> a >> n;
		m.clear();
		for (j=0; j<n; ++j) {
			cin>>k;
			m.push_back(k);
		}
		
		if (a==1) {
			cout << "Case #"<<(i+1)<<": "<<n<<endl;
			continue;
		}
		
		sort(m.begin(), m.end());
		
		dp[0].a1 = a; dp[0].o1 = 1;
		expand(a, m[0], 0, dp[0].a2, dp[0].o2);
		
		for (j=1; j<n; ++j) {
			solve(j);
		}
		
		if (dp[n-1].o1<dp[n-1].o2) {
			cout << "Case #"<<(i+1)<<": "<<dp[n-1].o1<<endl;
		} else {
			cout << "Case #"<<(i+1)<<": "<<dp[n-1].o2<<endl;
		}
		
	}
	
	return 0;
}