#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int T, n;
int R, C, M;

bool solve(vector<string> &ans){
	M = R*C - M;
	if(!M) return 0;
	ans[0][0] = 'c';
	if(M == 1) return 1;
	if(C == 1){
		REP(i, M-1) ans[i+1][0] = '.';
		return 1;
	}else if(C == 2){
		if(M & 1 || M == 2) return 0;
		REP(i, M/2) ans[i][0] = ans[i][1] = '.';
		ans[0][0] = 'c';
		return 1;
	}else{
		if(M < 4 || M == 5 || M == 7) return 0;
		ans[0][1] = ans[1][0] = ans[1][1] = '.';
		if(M == 4) return 1;
		ans[2][0] = ans[2][1] = '.';
		if(M == 6) return 1;
		ans[0][2] = ans[1][2] = '.';
		if(M == 8) return 1;
		M -= 8;
		if(M & 1){
			ans[2][2] = '.';
			M --;
		}
		for(int i=3;i<R;i++){
			if(!M) return 1;
			ans[i][0] = ans[i][1] = '.';
			M -= 2;
		}
		for(int i=3;i<C;i++){
			if(!M) return 1;
			ans[0][i] = ans[1][i] = '.';
			M -= 2;
		}
		REP(i, R)REP(j, C){
			if(!M) return 1;
			if(ans[i][j] == '*'){
				ans[i][j] = '.';
				M --;
			}
		}
	}
	if(!M) return 1;
}

main(){
	cin >> T;
	REP(t, T){
		int lf = 0;
		cin >> R >> C >> M;
		if(R < C){
			swap(R, C);
			lf = 1;
		}
		
		vector<string> ans(R, string(C, '*'));
		printf("Case #%d:\n", t+1);
		if(!solve(ans)) puts("Impossible");
		else if(lf){
			REP(i, C){
				REP(j, R) putchar(ans[j][i]);
				puts("");
			}
		}else{
			REP(i, R){
				REP(j, C) putchar(ans[i][j]);
				puts("");
			}
		}
	}
	return 0;
}
