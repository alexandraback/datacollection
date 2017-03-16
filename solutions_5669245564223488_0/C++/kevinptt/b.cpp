// Template.cpp by kevinptt 20140306
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
//#include <queue>
//#include <map>
//#include <deque>
#include <set>
#define REP(I, N) for(int I=0; I<(N); ++I)
#define REPP(I, A, B) for(int I=(A); I<(B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
//typedef pair<int,int> pii;

char str[105][105];
int len[105];
bool mapp[105][105];
set<char> pool[105];
int small(const int& n) {
	int per[105];
	REP(i, n) per[i] = i;
	bool used[27], ok;
	int ans=0;
	do {
		ok=true;
		memset(used, false, sizeof(used));
		REP(i, n) {
			int s1 = i==0?0:per[i-1], s2 = per[i];
			REP(j, len[s2]) {
				if( used[str[s2][j]-'a'] && ( (j==0&&str[s1][len[s1]-1]!=str[s2][0]) || (j!=0&&str[s2][j-1]!=str[s2][j]) ) ) {
					ok=false;
					break;
				}
				used[str[s2][j]-'a']  = true;
			}
			if( !ok ) break;
		}
		if( ok ) ++ans;
	} while( next_permutation(per, per+n) );
	return ans;
}
int main() {
	DRI(T);
	REP(casen, T) {
		DRI(n);
		int ans = 1;
		REP(i, n) {
			scanf("%s", str[i]);
			pool[i].clear();
			for(int j=0; str[i][j]; ++j) pool[i].insert(str[i][j]);
			len[i] = strlen(str[i]);
			memset(mapp[i], false, sizeof(mapp[i]));
		}
		printf("Case #%d: ", casen+1);
		REP(i, n) {
			set<char> tmp;
			for(int j=0; str[i][j]; ++j)
				if( str[i][j] != str[i][0] && str[i][j] != str[i][len[i]-1] ) tmp.insert(str[i][j]);
			for(set<char>::iterator itr = tmp.begin(); itr!=tmp.end()&&ans; ++itr)
				for(int j=0; j<n; ++j)
					if( i!=j && pool[j].find(*itr)!=pool[j].end() ) { ans=0; break; }
			if( !ans ) break;
		}
		if( !ans ) { puts("0"); continue; }
		if( n<=10 )
			printf("%d\n", small(n));
		else {
			REP(i, n)
				REP(j, n)
					if( i!=j && str[i][len[i]-1] == str[j][0] ) mapp[i][j] = true;
		}
	}

	return 0;
}

