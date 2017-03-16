#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define MAXN 1005
#define MOD 1000000007
#define B 70
typedef long long ll;
int T;

int ans[10];
ll hp1[MAXN];
ll hp2[MAXN];
int cnt1[MAXN];
int cnt2[MAXN];
vector <string> v1;
vector <string> v2;
map <ll, ll> mp;
ll madd(ll a, ll b)
{
	return (a+b) % MOD;
}
ll mmul(ll a, ll b)
{
	return (a*b) % MOD;
}
ll msub(ll a, ll b)
{
	return (a-b) % MOD;
}
int main(void)
{
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		cin >> N;
		memset(hp1, 0, sizeof(hp1));
		memset(hp2, 0, sizeof(hp2));
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for(int i=0; i<N; i++) {
			string s, t;
			cin >> s;
			for(int j=0; j<s.size(); j++) {
				hp1[i] = madd(mmul(hp1[i], B), s[j]);
			}
			int f = 0;
			for(int j=0; j<i; j++) {
				if(hp1[i] == hp1[j]) {
					mp[hp1[i]] = j;
					cnt1[j]++;
					f=1;
				}
			}
			if(f == 0) {
				cnt1[i]++;
				mp[hp1[i]] = i;
			}
			f = 0;
			cin >> t;
			v2.push_back(t);
			for(int j=0; j<t.size(); j++) {
				hp2[i] = madd(mmul(hp2[i], B), t[j]);
			}
			for(int j=0; j<i; j++) {
				if(hp2[i] == hp2[j]) {
					mp[hp2[i]] = j;
					cnt2[j]++;
					f=1;
				}
			}
			if(f == 0) {
				cnt2[i]++;
				mp[hp2[i]] = i;
			}
		}
		int ans = 0;
		if(N < 3) {
			printf("Case #%d: 0\n", t);
			continue;
		}
		//for(int i=0; i<N; i++) printf("%d %d\n", cnt1[i], cnt2[i]);
		for(int i=0; i<N; i++) {
			if((cnt1[mp[hp1[i]]] > 1) && (cnt2[mp[hp2[i]]] > 1)) {
				int mn = min(cnt1[mp[hp1[i]]], cnt2[mp[hp2[i]]]);
				ans += mn/2;
			}
		}
		printf("Case #%d: %d\n", t, ans);
			
	}
			
			
			
	return 0;
}
