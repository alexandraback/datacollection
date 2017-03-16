#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_c"
const ldb pi = acos(-1.0);
#define ONE 0
#define I 1
#define J 2
#define K 3

const int pr_sign[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};
const int pr_letter[4][4] = {{ONE, I, J, K}, {I, ONE, K, J}, {J, K, ONE, I}, {K, J, I, ONE}};
const int L = (int) 1e5;

int t;
int64 l, x;
char s[L];

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%I64d%I64d%s", &l, &x, s);
		for (int i = 0; i < l; ++i)
			s[i] = (s[i] == '1') ? ONE : (s[i] - 'i' + 1);
		int64 sign = 1, letter = ONE, min_pos = -1, max_pos = -1;
		for (int64 j = 0, pos = 0; (j < min(x, 4LL)) && (min_pos == -1); ++j)
			for (int i = 0; i < l; ++i, ++pos) {
				int nsign = sign * pr_sign[letter][s[i]], nletter = pr_letter[letter][s[i]];
				sign = nsign, letter = nletter;
				if ((sign == 1) && (letter == I)) {
					min_pos = pos;
					break;
				}
			}
		sign = 1, letter = ONE;	
		for (int64 j = 0, pos = x * l - 1; (j < min(x, 4LL)) && (max_pos == -1); ++j)
			for (int i = l - 1; i >= 0; --i, --pos) {
				int nsign = sign * pr_sign[s[i]][letter], nletter = pr_letter[s[i]][letter];
				sign = nsign, letter = nletter;
				if ((sign == 1) && (letter == K)) {
					max_pos = pos;
					break;
				}
			}
		sign = 1, letter = ONE;
		for (int j = 0; j < x % 4; ++j)
			for (int i = 0; i < l; ++i) {
				int nsign = sign * pr_sign[letter][s[i]], nletter = pr_letter[letter][s[i]];
				sign = nsign, letter = nletter;
			}
		eprintf("%I64d %I64d, %I64d %I64d\n", min_pos, max_pos, sign, letter);
		printf("Case #%d: ", it + 1);	
		if ((min_pos != -1) && (max_pos != -1) && (min_pos < max_pos) && (sign == -1) && (letter == ONE))
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
