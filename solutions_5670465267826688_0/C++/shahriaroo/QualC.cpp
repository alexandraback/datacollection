/*	In the name of God	*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;

/*
	i	j	k
	i	-1	k	-j
	j	-k	-1	i
	k	j	-i	-1
	*/
typedef struct quaternions quat;
struct quaternions{
	int x = 0;
	bool isneg = 0;
};
quat a[101 * 101];
quat mul(quat a, quat b){
	quat r;
	r.isneg = a.isneg^b.isneg;
	if (a.x && a.x == b.x)
		r.isneg = r.isneg ^ 1;
	else if (!a.x || !b.x)
		r.x = a.x + b.x;
	else{
		for (size_t i = 1; i <= 4; i <<= 1)
		{
			if (i != a.x && i != b.x){
				r.x = i;
				break;
			}
		}
		if (a.x == 2 * b.x || b.x == 4 * a.x)
			r.isneg = r.isneg ^ 1;
	}
	return r;
}

int n;
ll x;
char s[101 * 101];

bool solve(){
	quat r = a[0];
	int goal = 1;
	for (int j = 1; j < n*x; j++)
	{
		int i = j%n;
		if (!r.isneg && r.x == goal){
			goal <<= 1;
			r.x = 0;
		}
		r = mul(r, a[i]);
	}
	if (!r.isneg && r.x == goal){
		goal <<= 1;
		r.x = 0;
	}
	return goal == 8 && r.x == 0 && !r.isneg;
}


int main(){

	freopen("C-small-attempt1.in", "r", stdin);
	freopen("program.out", "w", stdout);

	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++)
	{
		bool f;
		scanf("%d %lld %s", &n, &x, s);
		for (size_t i = 0; i < n; i++)
		{
			a[i].isneg = 0;
			a[i].x = 1 << (s[i] - 'i');
		}
		if (x > 12){
			x = x % 4 + 12;
		}
		printf("Case #%d: %s\n", ti, solve() ? "YES" : "NO");
	}

	return 0;
}