#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<#x<<" = "<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(int i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";

bool isp(LL n) {
	vector<int> v;
	while(n) {v.push_back(n % 10); n /= 10;}
	n = v.size();
	for(int i = 0; i + i < n; i++) if(v[i] != v[n - 1 - i]) return 0;
	return 1;
}

bool v[10000010];

LL f(LL n) {
	LL r = 0;
	for(LL i = 0; i * i <= n; i++) {
		if(v[i] && isp(i * i)) r++;
	}
	return r;
}

int main() {
	LL A, B;
	int T;
	cin >> T;
	for(int i = 0; i <= 10000000; i++) v[i] = isp(i);
	for(int i = 1; i <= T; i++) {
		cin >> A >> B;
		LL r = f(B) - f(A - 1);
		cout << "Case #" << i << ": " << r << endl;

	}
	return 0;
}
