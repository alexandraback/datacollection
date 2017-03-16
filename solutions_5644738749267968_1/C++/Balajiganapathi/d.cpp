//Coder: Balajiganapathi
#define TRACE
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

int get() {
    long double d;
    cin >> d;
    return d * 100000;
}
    
const int mx = 1003;
int kim[mx], nim[mx], vis[mx], n;

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("D-small-attempt1.in", "r", stdin);
    freopen("D-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    //freopen("small1.txt", "w", stdout);
    freopen("large.txt", "w", stdout);
    
    int kases, kase;
    scanf("%d", &kases);
    for(kase = 1; kase <= kases; ++kase) {
        printf("Case #%d: ", kase);
        scanf("%d", &n);
        fr(i, n) nim[i] = get();
        fr(i, n) kim[i] = get();
        sort(kim, kim + n); sort(nim, nim + n);
        //fr(i, n) cerr << nim[i] << " "; cerr << endl; fr(i, n) cerr << kim[i] << " "; cerr << endl;
        ini(vis, 0);
        int dw, w;
        dw = w = 0;
        fr(i, n) {
            int z = 0;
            fr(j, n) if(!vis[j]) {
                z = j;
                break;
            }
            fr(j, n) if(!vis[j] && kim[j] > nim[i]) {
                z = j;
                break;
            }

            vis[z] = 1;
            if(nim[i] > kim[z]) ++w;
        }

        ini(vis, 0);
        fr(i, n) {
            int z = 0;
            fr(j, n) if(!vis[j]) {
                z = j;
                break;
            }
            if(nim[i] > kim[z]) {
                vis[z] = 1;
                ++dw;
                continue;
            }
            fr(j, n) if(!vis[j] && kim[j] > nim[i]) {
                z = j;
                break;
            }

            if(nim[i] < kim[z]) {
                fr(j, n) if(!vis[j]) {
                    z = j;
                }
            }
            vis[z] = 1;
            if(nim[i] > kim[z]) ++dw;
            //trace2(i, z);
        }

        printf("%d %d\n", dw, w);
    }
    
	return 0;
}
