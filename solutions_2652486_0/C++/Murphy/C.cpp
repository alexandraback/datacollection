#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int X[1024], Y[128];
vector<string> A;
int R, N, M, K;

void gao(int N, string s) {
	if (N == 0) {
		memset(Y, 0, sizeof Y);
		int sz = s.size();
		REP(i, 1<<sz) {
			int c = 1;
			REP(j, sz) {
				if (i & (1<<j)) {
					c *= s[j] - '0';
				}
			}
			Y[c] = 1;
		}
		REP(i, K) {
			if (!Y[X[i]]) {
				return;
			}
		}
		A.pb(s);
		return;
	} else {
		for (int num = 2; num <= M; num++) {
			s[N - 1] = '0' + num;
			gao(N - 1, s);
		}
	}
}

int main(){
	srand(time(NULL));
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
	cin>>R>>N>>M>>K;
	printf("Case #1:\n");
    REP(caseN, R) {
    	REP(i, K) {
    		cin>>X[i];
    	}
    	A.clear();
    	string s = "";
    	REP(i, N) {
    		s += ' ';
    	}
    	gao(N, s);
    	int sz = A.size();
    	int r = rand() % sz;
    	printf("%s\n", A[r].c_str());
    }
    return 0;
}