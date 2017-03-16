#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;

int keyboardLen, targetLen, typeCount;
int prefix[111];
char keyboard[111];
char target[111];

int freq[100];

double dp[111][111];
bool seen[111][111];

void calc_prefix_function(char str[], int pi[]){
	int len = strlen(str);	
	pi[0] = -1;
	for (int i = 1; i <= len; ++i) {
		int k = pi[i-1];
		while (k > -1 && str[k] != str[i-1]) {
			k = pi[k];
		}
		pi[i] = k + 1;
	}
}

void count_freq() {
	CLR(freq,0);
	for (int i = 0; i < keyboardLen; ++i)
		freq[keyboard[i]-'A']++;
}

bool is_possible() {
	for (int i = 0; i < targetLen; ++i)
		if (freq[target[i]-'A'] == 0) return false;
	return true;	
}

int max_possible() {
	if (is_possible()) {
		int ret = 1, len = targetLen;
		while (1) {
			len += targetLen - prefix[targetLen];
			if (len > typeCount) break;
			++ret;
		}
		return ret;
	}
	return 0;
}

double get_prob(char c) {
	return (double)freq[c-'A'] / (double)keyboardLen;
}

int update_pref(int cur, char c) {
	int k = cur;
	while (k > -1 && target[k] != c) k = prefix[k];
	return k+1;
}

double F(int i, int p) {
	if (i == typeCount) return 0;
	if (seen[i][p]) return dp[i][p];
	seen[i][p] = true;
	
	dp[i][p] = 0.0;
	for (char c = 'A'; c <= 'Z'; ++c) {
		int newPref = update_pref(p,c);
		int score = 0;
		if (newPref == targetLen) score = 1;
		if (newPref == targetLen)
			newPref = prefix[targetLen];
		dp[i][p] += get_prob(c) * (score + F(i+1, newPref));
	}

	return dp[i][p];
}

double solve() {
	count_freq();		
	calc_prefix_function(target, prefix);
	CLR(seen,0);			
	return max_possible() - F(0, 0);
}

int main(){
	int T=INT;
	REP(t,1,T){
		keyboardLen = INT;		
		targetLen = INT;
		typeCount = INT;
		scanf("%s%s",keyboard,target);

		printf("Case #%d: %0.8lf\n", t, solve());
	}	
	return 0;
}
