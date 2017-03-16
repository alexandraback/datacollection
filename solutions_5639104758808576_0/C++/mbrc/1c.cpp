#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n; string s;

int main() {
	ios::sync_with_stdio(false);
	int t; cin>>t;
	REP(q,1,t) {
		cin>>n>>s; int pref=0;
		int ans=0;
		REP(i,0,n) {
			int cur = s[i]-'0';
			if (cur>0) {
				ans = MAX(ans,i-pref);
			}
			pref+=cur;
		}
		cout<<"Case #"<<q<<": "<<ans<<endl;
	}
	return 0;
}
