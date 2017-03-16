#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp[2];
unordered_set<string> s[2];
vector<vector<string>> vec;
int n, m;
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		int left = 0, right = 0;
		scanf("%d", &n);
		vec.clear();
		FOR(i,0,n){
			char s1[100], s2[100];
			scanf("%s%s", s1, s2);
			vec.PB({s1, s2});
		}
		int ans = 0;
		FOR(i,0,1 << n){
			s[0].clear();
			s[1].clear();
			int tmp = 0;
			FOR(j,0,n){
				if ((1 << j) & i){
					s[0].insert(vec[j][0]);
					s[1].insert(vec[j][1]);
				}
			}
			int ok = 1;
			FOR(j,0,n){
				if (!((1 << j) & i)){
					if (!s[0].count(vec[j][0]))
						ok = 0;
					if (!s[1].count(vec[j][1]))
						ok = 0;
					if (!ok) break;
					tmp += 1;
				}
			}
			if (ok)
				ans = max(ans, tmp);
		}
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}

