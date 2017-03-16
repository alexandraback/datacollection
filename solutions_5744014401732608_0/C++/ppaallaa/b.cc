/*************************************************************************

       Author:            palayutm
       Created Time :     Sun 08 May 2016 05:39:00 PM CST

       File Name:         b.cc
       Description:       new style, new life

 ************************************************************************/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define clr(x,y) memset(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ALL(t) (t).begin(),(t).end()
#define FOR(i,n,m) for (int i = n; i <= m; i ++)
#define ROF(i,n,m) for (int i = n; i >= m; i --)
#define RI(x) scanf ("%d", &(x))
#define RII(x,y) RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

/**************************************END************************************/

int a[55][55];

int main (){
	int T;
	cin >> T;
	FOR (cas, 1, T){
		printf ("Case #%d: ", cas);
		ll n, m;
		cin >> n >> m;
		if (m > (1LL<<(n-2))){
			cout << "IMPOSSIBLE" << endl;
		}else{
			cout << "POSSIBLE" << endl;
			clr (a, 0);
			FOR (i, 2, n){
				FOR (j, i+1, n){
					a[i][j] = 1;
				}
			}
			if (m == (1LL<<(n-2))){
				FOR (i, 2, n){
					a[1][i] = 1;
				}
			}else{
				FOR (i, 0, n){
					if ((1LL << i)&m){
						a[1][n-i-1] = 1;
					}
				}
			}
			FOR (i, 1, n){
				FOR (j, 1, n){
					cout << a[i][j];
				}
				cout << endl;
			}
		}
	}
}

