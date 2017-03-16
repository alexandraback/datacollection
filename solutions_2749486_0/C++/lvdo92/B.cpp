/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y, w, d;
    node(){}
    node(int _x, int _y, int _w, int _d){
        x = _x; y = _y; w = _w; d = _d;
    }
};
int x, y, nx, ny;
node a;
string d[222][222][5];
bool isOk(int x, int y) {
    return (x >= 0 && y >= 0 && x <= 200 && y <= 200);
}
void init() {
    for (int i = 0;i < 201;i++)
        for (int j = 0;j < 201;j++)
            for (int k = 0;k < 4;k++) d[i][j][k] = "#";
	    queue <node> q;
	    q.push(node(100, 100, 0, 0));
	    q.push(node(100, 100, 0, 1));
	    q.push(node(100, 100, 0, 2));
	    q.push(node(100, 100, 0, 3));
	    d[100][100][0] = "";
	    d[100][100][1] = "";
	    d[100][100][2] = "";
	    d[100][100][3] = "";
	    while ( !q.empty() ) {
	        a = q.front(); q.pop();
	        nx = a.x;
	        ny = (a.y + a.w + 1);
	        rep(k, 4) {
                if ( isOk(nx, ny) && d[nx][ny][k] == "#") {
                    q.push(node(nx, ny, a.w + 1, k));
                    d[nx][ny][k] = d[a.x][a.y][4 - k - 1] + 'N';
                }
            }
	        nx = a.x;
	        ny = a.y - (a.w + 1);
	        rep(k, 4) {
                if ( isOk(nx, ny) && d[nx][ny][k] == "#") {
                    q.push(node(nx, ny, a.w + 1, k));
                    d[nx][ny][k] = d[a.x][a.y][4 - k - 1] + 'S';
                }
	        }
	        nx = a.x + a.w + 1;
	        ny = a.y;
	        rep(k, 4) {
                if ( isOk(nx, ny) && d[nx][ny][k] == "#") {
                    q.push(node(nx, ny, a.w + 1, k));
                    d[nx][ny][k] = d[a.x][a.y][4 - k - 1] + 'E';
                }
	        }
	        nx = a.x - (a.w + 1);
	        ny = a.y;
	        rep(k, 4) {
                if ( isOk(nx, ny) && d[nx][ny][k] == "#") {
                    q.push(node(nx, ny, a.w + 1, k));
                    d[nx][ny][k] = d[a.x][a.y][4 - k - 1] + 'W';
                }
	        }
	    }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	init();
	/*fr(i, 0, 200)
        fr(j, 0, 200)
            if (d[i][j] == "#") cout << i <<" "<<j<<endl;*/
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &x, &y);
	    x += 100; y += 100;
	    printf("Case #%d: ", ++caseno);
	    if (d[x][y][0] != "#") cout << d[x][y][0] <<endl;
	    else
	    if (d[x][y][1] != "#") cout << d[x][y][1] <<endl;
	    else
	    if (d[x][y][2] != "#") cout << d[x][y][2] <<endl;
	    else
	    if (d[x][y][3] != "#") cout << d[x][y][3] <<endl;
	}
	return 0;
}
