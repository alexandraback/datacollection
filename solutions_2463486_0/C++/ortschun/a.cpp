#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
const int MOD = 1000000007;
const int MAXN = 45;
vector<long long> nums;
int T, N;
bool pal(long long sq){
	ostringstream oss;
	oss<<sq;
	string str = oss.str();
	string tmp = str;
	reverse(ALL(tmp));
	return tmp == str;
}
void prep() {
	for(long long i = 1; 1LL * i*i <= 100000000000000LL; i ++) {
		long long sq = i * i;
		if(pal(sq) && pal(i)) {
			nums.push_back(sq);
		}
	}
}
int main() {
	prep();
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin>>T;
	REP(t, T){
		long long a, b;
		cin>>a>>b;
		cout<<"Case #"<<(t + 1)<<": "<<int(upper_bound(ALL(nums),b)-lower_bound(ALL(nums),a))<<endl;
	}
	return 0;
}
