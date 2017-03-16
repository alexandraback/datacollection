/*
 * =====================================================================================
 *
 *       Filename:  2778.cpp
 *        Version:  1.0
 *        Created:  2013-08-25 00:26:31
 *       Revision:  none
 *       Compiler:  GNU C++
 *
 *      Just like you,wait you forever~~
 *
 * =====================================================================================
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;

void RI (int& x){
	x = 0;
	char c = getchar ();
	while (c == ' '||c == '\n')     c = getchar ();
	bool flag = 1;
	if (c == '-'){
		flag = 0;
		c = getchar ();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar ();
	}
	if (!flag)      x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}

/**************************************END define***************************************/

const ll mod = 100000;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

const int NODE = 105;
const int CHD = 26;

int code[255];

int chd[NODE][CHD], sz, fail[NODE], val[NODE];

void init (){
	sz = 1;
	clr (val, 0);
	clr (fail, 0);
	clr (chd[0], 0);
}

void insert (char* s){
	int len = strlen (s);
	int p = 0;
	FOR (i, 0, len-1){
		int c = code[s[i]];
		if (!chd[p][c]){
			clr (chd[sz], 0);
			chd[p][c] = sz ++;
		}
		p = chd[p][c];
	}
	val[p] = 1;
}

void getfail (){
	queue<int> q;
	FOR (i, 0, CHD-1){
		fail[chd[0][i]] = 0;
		if (chd[0][i]){
			q.push (chd[0][i]);
		}
	}
	while (SIZE (q)){
		int node = q.front ();
		q.pop ();
		FOR (i, 0, CHD-1){
			if (chd[node][i]){
				int tmp = fail[node];
				fail[chd[node][i]] = chd[tmp][i];
				val[chd[node][i]] += val[chd[tmp][i]];
				q.push (chd[node][i]);
			}else{
				chd[node][i] = chd[fail[node]][i];
			}
		}
	}
}

char s[10005], t[10004];
double dp[105][105][105];

int main (){
	FOR (i, 'A', 'Z'){
		code[i] = i-'A';
	}

	int T;
	RI (T);
	FOR (cas, 1, T){
		init ();
		int K, L, S;
		scanf ("%d%d%d", &K, &L, &S);
		//RIII (K, L, S);
		scanf ("%s%s", s, t);
		insert (t);
		getfail ();
		FOR (i, 0, 100){
			FOR (j, 0, 100){
				FOR (k, 0, 100){
					dp[i][j][k] = 0.0;
				}
			}
		}
		dp[0][0][0] = 1;
		int ans = 0;
		FOR (i, 0, S-1){
			FOR (j, 0, sz-1){
				FOR (k, 0, S){
					if (dp[i][j][k]){
						FOR (h, 0, K-1){
							int sta = chd[j][code[ s[h] ]];
							int tz = k;
							if (val[sta]){
								tz ++;
								ans = max (ans, tz);
							}
							dp[i+1][sta][tz] += dp[i][j][k]/K;
						}
					}
				}
			}
		}
		double tt = 0;
		FOR (i, 0, sz-1){
			FOR (j, 0, S){
				tt += dp[S][i][j]*j;
			}
		}
		printf ("Case #%d: %.10f\n", cas, ans-tt);
	}

	/*int n, len;
	RII (n, len);
	FOR (i, 1, n){
		char s[15];
		RS (s);
		insert (s);
	}
	getfail ();
	FOR (i, 0, sz-1){
		if (!val[i]){
			FOR (j, 0, CHD-1){
				int v = chd[i][j];
				if (!val[v]){
					a.a[v][i] ++;
				}
			}
		}
	}
	a = a^len;
	ll ans = 0;
	FOR (i, 0, sz-1){
		ans = (ans + a.a[i][0]) % mod;
	}
	cout << ans << endl;*/
}


