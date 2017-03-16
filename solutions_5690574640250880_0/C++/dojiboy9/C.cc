#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <deque>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define cerr if (0) cout
#define MV 8
#define MAXR 55
#define MAXC MAXR
int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,-1,-1,-1,0,1,1,1};
char A[MAXR][MAXC];
int R,C;

int count(int i, int j) {
	if (A[i][j] == '*') return MV+1;
	int ans = 0;
	FOR(mv,MV) {
		int i2 = i + dr[mv];
		int j2 = j + dc[mv];
		if (i2<0||i2>=R || j2<0 || j2>=C) continue;
		if (A[i2][j2] == '*') ++ans;
	}
	return ans;
}

bool vis[MAXR][MAXC];
void dfs(int i, int j) {
	if (vis[i][j]) return;
	vis[i][j] = true;
	assert(count(i,j) <= 8);
	if (count(i,j) > 0) return;

	FOR(mv,MV) {
		int i2 = i + dr[mv];
		int j2 = j + dc[mv];
		if (i2 < 0 || i2 >= R || j2 < 0 || j2 >= C) continue;
		assert(count(i2,j2) <= 8);
		dfs(i2,j2);
	}
}
bool check(int MO) {
	int M = MO;
	memset(vis,0,sizeof(vis));
	int components = 0;
	int nonzero = 0;
	int stars = 0;
	FOR(i,R) FOR(j,C) if (A[i][j] == '*') stars++;
	if (stars != M) return false;
	
	FOR(i,R) FOR(j,C) {
		int v = count(i,j);
		if (v==0) {
			assert(A[i][j] == '.');
			if (vis[i][j]) continue;
			components++;
			dfs(i,j);
		} else if (v<=8) {
			assert(A[i][j] == '.');
			nonzero++;
		} else {
			assert(v==9);
			assert(A[i][j] == '*');
		}
	}
	// found at least one zero.
	// if everything is connected, we're done.
	if (components == 1) {
		// check if there is some unvisited guy
		FOR(i,R) FOR(j,C) if ((A[i][j] == '.') && (!vis[i][j]))
			return false;
			
		// no? then we're good.
		return true;
	}
	
	// otherwise, if we found too many disconnected 0's
	if (components >= 2) return false;
	
	// otherwise, there are no zeroes
	// return true iff nonzeroes is exactly 1
	assert(components == 0);
	assert(nonzero >= 1);
	return (nonzero == 1);
}

void print(int ci, int cj) {
	FOR(i,R) {
		FOR(j,C) {
			if (i==ci && j == cj) {
				assert(A[i][j] == '.');
				//printf("%d",count(i,j));
				printf("c");
			} else {
				printf("%c",A[i][j]);
				//printf("%d",count(i,j));
			}
		}
		printf("\n");
	}
}

bool solve2(int MO) {
	int M = MO;
	cerr << "Solving two rows/columns: " << M << endl;
	assert((R==2 || C==2) && R>=2 && C>=2);
	if (M%2) return false;
	if (R==2) {
		FOR(j,C) FOR(i,R) {
			if (!M) break;
			A[i][j] = '*';
			M--;
		}
		assert(check(MO) == true);
		return true;
	} else {
		assert(C==2);
		FOR(i,R) FOR(j,C) {
			if (!M) break;
			A[i][j] = '*';
			M--;
		}
		assert(check(MO) == true);
		return true;
	}
}

// if R==1 || C==1
bool solve1(int MO) {
	int M = MO;
	cerr << "Solving one row/column: " << M << endl;
	assert(R==1 || C==1);
	FOR(i,R) FOR(j,C) {
		if (!M) break;
		A[i][j] = '*';
		M--;
	}
	assert(check(MO) == true);
	return true;
}

bool solve_all_but_one(int MO) {
	int M = MO;
	cerr << "Solving all but one: " << M << endl;
	assert(M == (R*C - 1));
	FOR(i,R) FOR(j,C) {
		if (!M) break;
		A[i][j] = '*';
		M--;
	}
	assert(check(MO) == true);
	return true;
}

bool solve_even(int MO) {
	int M = MO;
	FOR(i,R) FOR(j,C) A[i][j] = '*';
	int L = R*C - M;
	assert((L%2) == 0);
	
	cerr << "Solving even: " << M << " " << L << endl;
	
	FORALL(i,R-2,R-1) FORALL(j,C-2,C-1) {
		assert(L);
		A[i][j] = '.';
		L--;
	}
	assert(L>=0);
	assert((L%2) == 0);
	
	FORB(j,C-3,0) {
		if (!L) break;
		assert(L>=0);
		assert((L%2) == 0);
		A[R-1][j] = A[R-2][j] = '.';
		L -= 2;
	}
	
	FORB(i,R-3,0) {
		if (!L) break;
		assert(L>=0);
		assert((L%2) == 0);
		A[i][C-1] = A[i][C-2] = '.';
		L -= 2;
	}
	
	FORB(i,R-1,0) FORB(j,C-1,0) {
		if (!L) break;
		if (A[i][j] == '.') continue;
		A[i][j] = '.';
		L--;
	}
	
	assert(L==0);
	assert(check(MO) == true);
	return true;
}

bool solve_odd(int MO) {
	int M = MO;
	int L = R*C - M;
	cerr << "Solving for odd >= 9: " << M << " l" << L << endl;
	assert(L%2); assert(L>=9);
	FOR(i,R) FOR(j,C) A[i][j] = '*';
	FORALL(i,R-3,R-1) FORALL(j,C-3,C-1) {
		assert(L);
		A[i][j] = '.';
		L--;
	}
	
	assert(L>=0);
	assert((L%2) == 0);
	
	FORB(j,C-4,0) {
		if (!L) break;
		assert(L>=0);
		assert((L%2) == 0);
		A[R-1][j] = A[R-2][j] = '.';
		L -= 2;
	}
	
	FORB(i,R-4,0) {
		if (!L) break;
		assert(L>=0);
		assert((L%2) == 0);
		A[i][C-1] = A[i][C-2] = '.';
		L -= 2;
	}
	
	FORB(i,R-1,0) FORB(j,C-1,0) {
		if (!L) break;
		if (A[i][j] == '.') continue;
		A[i][j] = '.';
		L--;
	}
	
	assert(L==0);
	assert(check(MO) == true);
	return true;
}


bool solve(int MO) {
	int M = MO;
	
	int left_over = R*C - M;
	cerr << "left_over: " << left_over << endl;
	if (left_over == 1) return solve_all_but_one(M);
	if (R == 1 || C == 1) return solve1(M);
	if (left_over == 2 || left_over == 3) return false;
	if (R == 2 || C == 2) return solve2(M);
	if ((left_over%2) == 0) return solve_even(M);
	if (left_over == 5 || left_over == 7) return false;
	//if ((left_over%3) == 0) return solve_threven(M);
	
	assert(left_over >= 9);
	return solve_odd(M);
}

int main() {
	int TEST,M;
	cin >> TEST;
	FORALL(test,1,TEST) {
		cin >> R >> C >> M;
		FOR(i,R) FOR(j,C) A[i][j] = '.';
		cout << "Case #"<<test<<":" << endl;
		if (solve(M)) {
			// it worked!?
			print(R-1,C-1);
			assert(check(M) == true);
			continue; // done test case;
		} else {
			cout << "Impossible" << endl;
		}
	}
}













