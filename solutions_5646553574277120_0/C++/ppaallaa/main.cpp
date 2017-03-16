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
#include <stdio.h>

using namespace std;

#define PB			  push_back
#define SIZE(x)		 (int)x.size()
#define clr(x,y)		memset(x,y,sizeof(x))
#define MP(x,y)		 make_pair(x,y)
#define RS(n)		   scanf ("%s", n)
#define ALL(t)		  (t).begin(),(t).end()
#define FOR(i,n,m)	  for (int i = n; i <= m; i ++)
#define ROF(i,n,m)	  for (int i = n; i >= m; i --)
#define IT			  iterator
#define FF			  first
#define SS			  second

typedef long long			   ll;
typedef unsigned int			uint;
typedef unsigned long long	  ull;
typedef vector<int>			 vint;
typedef vector<string>		  vstring;
typedef pair<int, int>		  PII;

void RI (int& x){
	x = 0;
	char c = getchar ();
	while (!(c>='0' && c<='9' || c=='-'))	 c = getchar ();
	bool flag = 1;
	if (c == '-'){
		flag = 0;
		c = getchar ();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar ();
	}
	if (!flag)	  x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}
void RC (char& c){
	c = getchar ();
	while (c == ' '||c == '\n')	 c = getchar ();
}
char RC (){
	char c = getchar ();
	while (c == ' '||c == '\n')	 c = getchar ();
	return c;
}

/**************************************END define***************************************/

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

int d, v;
int t[128];
bool val[128];

int chk(int ind, int tot){
	if (ind == tot) {
		clr(val, 0);
		val[0] = 1;
		FOR (i, 0, ind - 1)
			ROF (j, v, t[i])
				if (val[j - t[i]])
					val[j] = 1;
		ROF (i, v, 1)
			if (!val[i])
				return 0;
		return 1;
	}
	FOR (i, 1, v){
		bool flag = 1;
		FOR (j, 0, ind - 1)
			if (i == t[j])
				flag = 0;
		if (flag){
			t[ind] = i;
			if (chk (ind + 1, tot)){
				return 1;
			}
		}
	}
	return 0;
}

int main (){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T;
	RI (T);
	FOR (cas, 1, T){
		RI (d);
		RII (d, v);
		FOR (i, 0, d - 1)
			RI (t[i]);
		FOR (i, d, 100){
			if (chk (d, i)){
				printf ("Case #%d: %d\n", cas, i - d);
				break;
			}
		}
	}
}
