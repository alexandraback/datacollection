#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int T, n;
int check(vector<double> &a, vector<double> &b){
	int i = 0, j = 0;
	int ret = 0;
	while(j < n && i < n){
		if(a[j] < b[i]){
			ret ++;
			j ++;
			i ++;
		}else{
			i ++;
		}
	}
	return ret;
}
main(){
	cin >> T;
	REP(t, T){
		cin >> n;
		vector<double> a(n), b(n);
		REP(i, n) cin >> a[i];
		REP(i, n) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		printf("Case #%d: %d %d\n", t+1, check(b, a), n-check(a, b));
	}
	return 0;
}
