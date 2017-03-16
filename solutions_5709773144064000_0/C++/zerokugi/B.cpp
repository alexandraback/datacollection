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
main(){
	cin >> T;
	REP(t, T){
		double C, F, X;
		cin >> C >> F >> X;
		double cps = 2;
		double ans = X / cps;
		double sum = 0;
		while(1){
			sum += C / cps;
			cps += F;
			if(ans < sum + X / cps) break;
			ans = sum + X / cps;
		}
		printf("Case #%d: %.9f\n", t+1, ans);
	}
	return 0;
}
