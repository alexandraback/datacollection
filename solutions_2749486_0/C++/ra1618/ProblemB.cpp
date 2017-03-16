#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <ctime>

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <iostream>
#include <numeric>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair


typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> inline void relaxmin(T& a, const T& b) { if (a > b) a = b; }
template<typename T> inline void relaxmax(T& a, const T& b) { if (a < b) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> int sign(T x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; } 

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

string solve2(){
	int X,Y;
	scanf("%d%d", &X, &Y);

	const int shift = 110;
	const int SZ = 220;
	int desk[SZ][SZ];
	memset(desk, -1, sizeof(desk));

	desk[X+shift][Y+shift] = 100500;
	desk[0+shift][0+shift] = 0;

	vector<vector<string>> moves(SZ, SZ); //[SZ][SZ];
	forn(i, SZ) {
		forn(j, SZ){
			moves[i][j] = "";
		}
	}

	string ans;
	forn(L, 500) {
		forn(x,SZ) {
			forn(y, SZ) {
				if (desk[x][y] == L) {
					if (x+L >= 0 && x+L < SZ) {
						//if (desk[x+L][y] == -1)
						desk[x+L][y] = L+1;
						moves[x+L][y] = moves[x][y] + "E";
					}
					if (x-L >= 0 && x-L < SZ) {
						//if (desk[x-L][y] == -1)
						desk[x-L][y] = L+1;
						moves[x-L][y] = moves[x][y] + "W";
					}
					if (y+L >= 0 && y+L < SZ) {
						//if (desk[x][y+L] == -1)
						desk[x][y+L] = L+1;
						moves[x][y+L] = moves[x][y] + "N";
					}
					if (y-L >= 0 && y-L < SZ) {
						//if (desk[x][y-L] == -1)
						desk[x][y-L] = L+1;
						moves[x][y-L] = moves[x][y] +  "S";
					}
				}
				if (desk[X+shift][Y+shift] != 100500) {
					// backtrack
					return moves[X+shift][Y+shift];
				}
			}
		}
	}

}


void Solve(int caseNo)
{
	string ans = solve2();

	printf("Case #%d: %s\n", caseNo, ans.c_str());
	//printf( "%2.1f\n", ans );
}


int main()
{
	//if (freopen("c:\\_temp\\B.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\B.out", "wt", stdout) == NULL) throw 2;

	if (freopen("c:\\_temp\\B-small-attempt1.in", "rt", stdin) == NULL) throw 1;
	if (freopen("c:\\_temp\\B-small-attempt1.out", "wt", stdout) == NULL) throw 2;

	//if (freopen("c:\\_temp\\B_test.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\B_test.out", "wt", stdout) == NULL) throw 2;

	//if (freopen("c:\\_temp\\B-large.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\B-large.out", "wt", stdout) == NULL) throw 2;

	int caseCount;
	scanf("%d%", &caseCount);
	clock_t totalNow = clock();

	forab(i, 1, caseCount) {
		clock_t now = clock();
		cerr << "case " << i << "...";

		Solve(i);
		fflush(stdout);

		cerr << "Done!; Elapsed ms:" << (double)(clock() - now) * 1000 / CLOCKS_PER_SEC << "\n";
	}
	cerr << "Total elapsed seconds:" << (double)(clock() - totalNow) / CLOCKS_PER_SEC << "\n";

	exit(0);
}
