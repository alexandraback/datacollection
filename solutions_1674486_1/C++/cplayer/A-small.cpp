#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
template<class T> inline T Max(T a,T b)
{if(a>b)return a;else return b;}
template<class T> inline T Min(T a,T b)
{if(a<b)return a;else return b;}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T TripleMax(T a,T b,T c)
{return Max(Max(a,b),c);}
template<class T> inline T TripleMin(T a,T b,T c)
{return Min(Min(a,b),c);}
#define ll long long
#define For(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define DFor(i, b, a) for (int (i) = (b) - 1; (i) >= (a); (i)--)
#define PB push_back
#define MP make_pair

int     t;
int     graph[1005][1005];
int     n;
int     mi;
int     father;
int     ct;
int     judge;

void init () {
    memset(graph, 0, sizeof(graph));
    judge = 0;
}

int solve () {
    int     tmp;
    For(k, 1, n + 1) {
        For(i, 1, n + 1) {
            For(j, 1, n + 1) {
                tmp = graph[i][k] * graph[k][j];
                graph[i][j] = graph[i][j] + tmp;
                if (graph[i][j] >= 2) return 1;
            }
        }
    }
    return 0;
}

int main (int argc, const char* argv[]) {
    
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    
    cin >> t;
    ct = t;
    while (t > 0) {
        cin >> n;
        init();
        For(i, 1, n + 1) {
            cin >> mi;
            For(j, 0, mi) {
                cin >> father;
                graph[i][father] = 1;
            }
        }
        cout << "Case #" << ct - t + 1 << ":";
        judge = solve();
        if (judge == 1) {
            cout << " Yes" << endl;
        }
        if (judge == 0) cout << " No" << endl;
        t--;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
