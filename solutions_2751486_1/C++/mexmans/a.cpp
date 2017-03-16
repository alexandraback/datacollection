#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e6 + 10;
int r;
char s[maxn];
char vowels[] = "aeiou";
int vowel[256];
int cnt[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	for (int i = 0; i < 5; i++) {
		vowel[vowels[i]] = 1;
	}
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		scanf("%s%d",&s,&r);
		int n = strlen(s);
		LL res = 0;
		int last = 0;
		for (int i = 0; i < n;) {
			if (vowel[s[i]]) {
				i++;
				continue;
			}
			int j = i;
			while(j < n && !vowel[s[j]]) {
				j++;
			}
			if (j - i < r) {
				i = j;
				continue;
			}
			res = res + (i - last + 1) * (LL)(n - (i + r) + 1);
			i++;
			while(i + r <= j) {
				res = res + n - (i + r) + 1;
				i++;
			}
			last = i;
			i = j;
		}
		printf("Case #%d: %I64d\n",t,res);
	}
	return 0;
}
