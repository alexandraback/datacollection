#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <locale>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <complex>
#include <valarray>

#define rep(i, n) for (int i = 0; i < n; ++ i)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ll long long
#define cmplxd complex <long double>
#define pi 3.14159265358979323846264338327950288


using namespace std;

const int maxn = 1001 + 10;

int stest;
int n,m;
long long res,le = 0;
pair<long long , long long> a[maxn],b[maxn];

long long get(int t,int u,int v,long long rest) {
     long long r = 0, back_up = b[u].x , l = a[t].x;
     b[u].x = rest;

     for(int i=u; i<=v; i++) if (b[i].y == a[t].y) {
            r += min(b[i].x,l);
            if ( i == v) le = b[i].x - min(b[i].x,l);
            l -= min(b[i].x,l);
     }

     b[u].x = back_up;
     return r;
}

int main() {

    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small.txt","w",stdout);


    cin >> stest;
    long long u,v;
    for(int test = 0; test < stest; test++) {
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            cin >> u >> v;
            a[i] = mp(u,v);
        }

        for(int i=1; i<=m; i++) {
            cin >> u >> v;
            b[i] = mp(u,v);
        }

        res = 0;
        for(int i=1; i<=n; i++) res = max(res,get(i,1,n,b[1].x));

        // 2
        long long r = 0;
        for(int x=1; x<=n; x++) {
            for(int y=x+1; y<=n; y++) {
                for(int i=1; i<=m; i++) {
                    r = get(x  ,1 ,i ,b[1].x);
                    r += get(y ,i ,m ,b[i].x-le);
                    res = max(res,r);
                }
            }
        }

        // 3
        for(int x=1; x<=n; x++) {
            for(int y=x+1; y<=n; y++) {
              for(int z=y+1; z<=n; z++) {
                for(int i=1; i<=m; i++)   {
                  for(int j=i+1; j<=m; j++) {
                    r  = get(x ,1 ,i ,b[1].x);
                    r += get(y ,i ,j ,b[i].x-le);
                    r += get(z ,j ,m ,b[j].x-le);
                    res = max(res,r);
                  }
                }
              }
            }
        }

        cout << "Case #" << test+1 << ": " << res << endl;
    }

    return 0;
}
