#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 10005

int N;
char buf[MAXN];
int x[MAXN], g[8][8];
int dpl[MAXN], dpr[MAXN];
map<string, int> token;
ll X;
int main(){
	int cs;
	cin >> cs;
	ifstream mat("Cmat", ios::in);
	REP(i, 0, 8) {
		string t;
		mat >> t;
		token[t] = i;
	}
	REP(i, 0, 8){
		REP(j, 0, 8){
			string t;
			mat >> t;
			g[i][j] = token[t];
		}
	}
	mat.close();

	int vi = token["i"], vj = token["j"], vk = token["k"];

	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		cin >> N >> X;
		scanf("%s", buf);
		REP(i, 0, N){
			string t = "";
			t += buf[i];
			x[i] = token[t];
		}
		dpl[0] = x[0];
		REP(i, 1, N)
			dpl[i] = g[dpl[i - 1]][x[i]];
		dpr[N - 1] = x[N - 1];
		for (int i = N - 2; i >= 0; i--)
			dpr[i] = g[x[i]][dpr[i + 1]];
		int u[4];
		u[0] = 0;
		REP(i, 1, 4) u[i] = g[u[i - 1]][dpl[N-1]];
		bool ok = 0;
		// cut single
		X--;
		REP(i, 0, N) {
			int z = 0;
			REP(j, i + 2, N) {
				z = g[z][x[j - 1]];
				if (z != vj) continue;
				REP(t, 0, 4){
					if (t > X) break;
					if (g[u[t]][dpl[i]] != vi) continue;
					if (g[dpr[j]][u[(X - t) % 4]] != vk) continue;
					ok = 1;
					goto answer;
				}
			}
		}
		X++;
		// cut two
		if (X >= 2){
			X -= 2;
			REP(i, 0, N){
				REP(j, 0, N){
					REP(p, 0, 4){
						REP(q, 0, 4){
							if (p + q > X) break;
							if (g[u[p]][dpl[i]] != vi) continue;
							if (g[dpr[j]][u[q]] != vk) continue;
							int l = i + 1 == N ? 0 : dpr[i + 1],
								r = j - 1 < 0 ? 0 : dpl[j - 1];
							int m = g[l][u[(X - p - q) % 4]];
							if (g[m][r] != vj) continue;
							ok = 1;
							goto answer;
						}
					}
				}
			}
			X += 2;
		}
answer:
		puts(ok ? "YES" : "NO");
	}
	return 0;
}