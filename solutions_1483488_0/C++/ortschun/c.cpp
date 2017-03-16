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
int dig[15], p[10];
int get(int n, int up){
	int m = n, cnt = 0;
	while(m){
		dig[cnt ++] = m % 10;
		m /= 10;
	}
	set<int> s;
	int ret = 0;
	for(int j = 1; j <= cnt; j ++){
		int rem = cnt - j;
		ret = (n % p[rem]) * p[j] + (n / p[rem]);
		if(ret > n && ret <= up){
			s.insert(ret);
		}
	}
		
	return SIZE(s);
}
long long solve(int a, int b){
	long long ret = 0;
	for(int i = a; i <= b; i ++){
		ret += get(i, b);
	}
	return ret;
}
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
	p[0] = 1;
	for(int i = 1; i <= 9; i ++){
		p[i] = 10 * p[i - 1];
	}
	int T;
	cin>>T;
	for(int t = 1; t <= T; t ++){
		int A, B;
		cin>>A>>B;
		cout<<"Case #"<<t<<": "<<solve(A, B)<<endl;
	}
	return 0;
}
