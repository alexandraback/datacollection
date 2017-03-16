//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 10010

LL K;
char s[N];
int n, L[N], R[N];

int mm[5][5] = {{0, 1, 2, 3, 4}, 
				{1, 1, 2, 3, 4},
				{2, 2,-1, 4,-3},
				{3, 3,-4,-1, 2},
				{4, 4, 3,-2,-1}};

int getV(char ch) {
	return ch == 'i' ? 2 : (ch == 'j' ? 3 : 4);
}

int cal(int lp, int rp) {
	int ret = mm[abs(lp)][abs(rp)];
	if (lp * rp < 0) ret *= -1;
	return ret;
}

int quick_sqr(int v, LL K) {
	int ret = 1;
	while (K) {
		if (K%2 == 1) ret = cal(ret, v);
		v = cal(v, v);
		K >>= 1;
	}
	return ret;
}

bool solveL(LL &a, int &num, int target) {
	a = 0;
	int cur = 1;
	set<int> ss;
	ss.insert(1);
	while (true) {
		for (num = 1; num <= n; num++)
			if (cal(cur, L[num]) == target) return true;
		num = 0;
		a++;
		cur = cal(cur, L[n]);
		if (cur == target) return true;
		if (ss.find(cur) != ss.end()) return false;
		ss.insert(cur);
	}
}

bool solveR(LL &a, int &num, int target) {
	a = 0;
	int cur = 1;
	set<int> ss;
	ss.insert(1);
	while (true) {
		for (num = 1; num <= n; num++)
			if (cal(R[num], cur) == target) return true;
		num = 0;
		a++;
		cur = cal(R[n], cur);
		if (cur == target) return true;
		if (ss.find(cur) != ss.end()) return false;
		ss.insert(cur);
	}
}

bool solve() {
	L[0] = R[0] = 1;
	for (int i = 1; i<= n; i++) {
		L[i] = cal(L[i - 1], getV(s[i - 1]));
		R[i] = cal(getV(s[n - i]), R[i - 1]);
	}

	LL a, b, c;
	int num1, num2, ret;
	if (!solveL(a, num1, 2)) return false;
	if (!solveR(b, num2, 4)) return false;
	c = K - a - b;
	if (c >= 2) {
		ret = quick_sqr(L[n], c - 2);
		ret = cal(cal(R[n - num1], ret), L[n - num2]);
	}
	else if (c == 1) {
		if (num1 + num2 >= n) return false;
		ret = 1;
		for (int i = num1 + 1; i <= n - num2; i++)
			ret = cal(ret, getV(s[i - 1]));
	}
	else return false;
	return ret == 3;
}
int		main(){
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d%lld%s", &n, &K, s);
		printf("Case #%d: %s\n", ++tt, solve() ? "YES" : "NO");
	}
	return 0;
}
