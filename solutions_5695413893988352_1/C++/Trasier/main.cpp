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

typedef long long LL;
const int maxn = 24;
char s1[maxn], s2[maxn];
char ts1[maxn], ts2[maxn];
char ss1[maxn], ss2[maxn];
char ans1[maxn], ans2[maxn];
bool visit[maxn];
set<LL> st[2];
set<LL>::iterator iter, iter2;
int len;

LL getVal(char *s) {
	int i = 0;
	LL ret = 0;

	while (s[i]) {
		ret = ret * 10 + s[i]-'0';
		++i;
	}

	return ret;
}

int getBits(LL x) {
	if (x == 0)	return 1;
	int ret = 0;

	while (x) {
		++ret;
		x /= 10;
	}

	return ret;
}

void solve_(char* s1, char* s2, set<LL>& st1, set<LL>& st2, int pos) {
	rep(i, pos, len) if (s1[i] == '?') s1[i] = '0';
	rep(i, pos, len) if (s2[i] == '?') s2[i] = '9';
	
	memset(visit, false, sizeof(visit));
	per(i, 0, pos) {
		
	}
	
	int ov = 1;
	int i = pos - 1;
	bool flag;
	
	while (i >= 0) {
		flag = false;
		if (s1[i] != '?') {
			if (s1[i] == '0') {
				s2[i] = '9';
			} else {
				s2[i] = s1[i] - 1;
				ov = 0;
			}
		} else if (s2[i] != '?') {
			if (s2[i] == '9') {
				s1[i] = '0';
			} else {
				s1[i] = s2[i] + 1;
				ov = 0;
			}
		} else {
			flag = true;
			s1[i] = '1';
			s2[i] = '0';
			ov = 0;
		}
		
		--i;
		if (ov == 0) {
			int j = i;
			
			strcpy(ts1, s1);
			strcpy(ts2, s2);
			while (j >= 0) {
				if (s1[j] != '?') {
					s2[j] = s1[j];
				} else if (s2[i] != '?') {
					s1[j] = s2[j];
				} else {
					s1[j] = s2[j] = '0';
				}
				--j;
			}
			
			st1.insert(getVal(s1));
			st2.insert(getVal(s2));
			
			strcpy(s1, ts1);
			strcpy(s2, ts2);
		}
		
		if (flag) {
			#ifdef LOCAL_DEBUG
			assert(ov == 0);
			#endif
			s1[i+1] = '0';
			s2[i+1] = '9';
			ov = 1;
		}
	}	
}

void solve() {
	len = strlen(s1);
	int pos;
	bool eq = true;

	strcpy(ss1, s1);
	strcpy(ss2, s2);
	rep(i, 0, len) {
		if (s1[i]=='?' || s2[i]=='?') {
			if (s1[i] != '?') {
				s2[i] = s1[i];
			} else if (s2[i] != '?') {
				s1[i] = s2[i];
			} else {
				s1[i] = s2[i] = '0';
			}
		} else if (s1[i] != s2[i]) {
			if (s1[i] < s2[i]) {
				rep(j, i, len) if (s1[j]=='?') s1[j]='9';
				rep(j, i, len) if (s2[j]=='?') s2[j]='0';
			} else {
				rep(j, i, len) if (s1[j]=='?') s1[j]='0';
				rep(j, i, len) if (s2[j]=='?') s2[j]='9';
			}
			eq = false;
			pos = i;
			break;
		}
	}

	if (eq) {
		// printf("%s %s\n", s1, s2);
		cout << s1 << " " << s2 << endl;
		return ;
	}

	LL ansa = getVal(s1), ansb = getVal(s2);
	LL mn = abs(ansa - ansb);

	strcpy(ans1, s1);
	strcpy(ans2, s2);
	strcpy(s1, ss1);
	strcpy(s2, ss2);
	st[0].clr();
	st[1].clr();
	
	if (ansa < ansb) {
		// make s1 > s2;
		solve_(s1, s2, st[0], st[1], pos);
	} else {
		// make s2 > s1;
		solve_(s2, s1, st[1], st[0], pos);
	}
	
	#ifdef LOCAL_DEBUG
	// cout << "s1" << endl;
	// for (iter=st[0].begin(); iter!=st[0].end(); ++iter)
		// cout << *iter << " ";
	// cout << endl;
	// cout << "s2" << endl;
	// for (iter=st[1].begin(); iter!=st[1].end(); ++iter)
		// cout << *iter << endl;
	// cout << endl;
	#endif

	for (iter=st[0].begin(); iter!=st[0].end(); ++iter) {
		LL tmpa = *iter;
		iter2 = lower_bound(all(st[1]), tmpa);
		if (iter2 != st[1].end()) {
			LL tmpb = *iter2;
			LL tmp = abs(tmpa - tmpb);
			
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
			
			LL tmpb = *iter2;
			LL tmp = abs(tmpa - tmpb);
			
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
	
	// while (la++ < len) putchar('0');
	// printf("%lld ", ansa);
	// while (lb++ < len) putchar('0');
	// printf("%lld\n", ansb);
	while (la++ < len) cout << '0';
	cout << ansa << ' ';
	while (lb++ < len) cout << '0';
	cout << ansb << endl;
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
		// printf("Case #%d: ", tt);
		cout << "Case #" << tt << ": ";
		solve();
	}

	#ifdef LOCAL_DEBUG
		// printf("time = %ldms.\n", clock());
	#endif

	return 0;
}
