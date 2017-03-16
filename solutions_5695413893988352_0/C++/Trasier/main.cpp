/*  */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti				set<int>
#define stpii			set<pair<int, int> >
#define mpii			map<int,int>
#define vi				vector<int>
#define pii				pair<int,int>
#define vpii			vector<pair<int,int> >
#define rep(i, a, n) 	for (int i=a;i<n;++i)
#define per(i, a, n) 	for (int i=n-1;i>=a;--i)
#define clr				clear
#define pb 				push_back
#define mp 				make_pair
#define fir				first
#define sec				second
#define all(x) 			(x).begin(),(x).end()
#define SZ(x) 			((int)(x).size())
#define lson			l, mid, rt<<1
#define rson			mid+1, r, rt<<1|1
#define INF				0x3f3f3f3f
#define mset(a, val)	memset(a, (val), sizeof(a))

// #define LOCAL_DEBUG
const int maxn = 24;
char s1[maxn], s2[maxn];
set<int> st[2];
set<int>::iterator iter, iter2;

void dfs(char *s, int val, int id) {
	if (*s == '\0') {
		st[id].insert(val);
		return ;
	}
	
	if (*s == '?') {
		rep(i, 0, 10) {
			int tmp = val*10 + i;
			dfs(s+1, tmp, id);
		}
	} else {
		int tmp = val*10 + (*s) - '0';
		dfs(s+1, tmp, id);
	}
}

int getBits(int x) {
	if (x == 0)	return 1;
	int ret = 0;
	
	while (x) {
		++ret;
		x /= 10;
	}
	
	return ret;
}

void solve() {
	st[0].clr();
	st[1].clr();
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	dfs(s1, 0, 0);
	dfs(s2, 0, 1);
	
	int ansa, ansb;
	int mn = INF;
	
	for (iter=st[0].begin(); iter!=st[0].end(); ++iter) {
		int tmpa = *iter;
		iter2 = lower_bound(all(st[1]), tmpa);
		if (iter2 != st[1].end()) {
			int tmpb = *iter2;
			int tmp = abs(tmpa - tmpb);
			
			if (tmp < mn) {
				mn = tmp;
				ansa = tmpa;
				ansb = tmpb;
			} else if (tmp == mn) {
				if (tmpa < ansa) {
					mn = tmp;
					ansa = tmpa;
					ansb = tmpb;
				} else if (tmpa == ansa) {
					if (tmpb < ansb) {
						mn = tmp;
						ansa = tmpa;
						ansb = tmpb;
					}
				}
			}
		}
		
		if (iter2 != st[1].begin()) {
			--iter2;
			
			int tmpb = *iter2;
			int tmp = abs(tmpa - tmpb);
			
			if (tmp < mn) {
				mn = tmp;
				ansa = tmpa;
				ansb = tmpb;
			} else if (tmp == mn) {
				if (tmpa < ansa) {
					mn = tmp;
					ansa = tmpa;
					ansb = tmpb;
				} else if (tmpa == ansa) {
					if (tmpb < ansb) {
						mn = tmp;
						ansa = tmpa;
						ansb = tmpb;
					}
				}
			}
		}
	}
	
	int la = getBits(ansa), lb = getBits(ansb);
	
	while (la++ < len1) putchar('0');
	printf("%d ", ansa);
	while (lb++ < len2) putchar('0');
	printf("%d\n", ansb);
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef LOCAL_DEBUG
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	
	int t;
	
	scanf("%d", &t);
	rep(tt, 1, t+1) {
		scanf("%s%s", s1, s2);
		printf("Case #%d: ", tt);
		solve();
	}
	
	#ifdef LOCAL_DEBUG
		printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
