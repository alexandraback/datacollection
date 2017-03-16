#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <time.h>
#include <memory>
using namespace std;

typedef long long LL;
typedef long long uLL;
typedef unsigned int uint;
#define FOR(i, b, e) for(int i=(b); i<int(e); ++i)
#define dFOR(i, b, e) for(int i=(b); i>int(e); --i)
#define FORV(i, b, e) for(i=(b); i<(e); ++i)
#define dFORV(i, b, e) for(i=(b); i>int(e); --i)
#define GET(a) cin >> a
#define GET2(a, b) cin >> a >> b
#define GET3(a, b, c) cin >> a >> b >> c
#define GET4(a, b, c, d) cin >> a >> b >> c >> d
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PB(a) push_back(a)
#define SIZE(a) a.size()
#define PEEK(a) cout << " >> " #a " = " << a << endl
#define peek(a) _peek(#a, a)
template <typename T> void _peek(char name[], T &obj, size_t max_count=50){
    const size_t ipl = 10;
    cout << " >> " << name << " = ["; size_t _count = 0;
    for(typename T::iterator it=obj.begin(); it!=obj.end(); ++it){
        if(_count && _count%ipl == 0) cout << "      [";
        cout << *it; ++_count;
        if(_count%ipl == 0 || _count >= max_count || it == obj.end()-1) cout << " ]\n";
        else cout << ", ";
        if(_count >= max_count) break;
    }
}
template <typename T> ostream &operator << (ostream &cout, pair<T, T> &x){
    cout << "(" << x.first << "," << x.second << ")";
    return cout;
}
template <typename T> inline T GCD(T a, T b){
    if(b==0) return a;
    a %= b; while(a){ swap(a, b); a %= b; }; return b;
}
template <typename T> inline T LCM(T a, T b){
    if(a == 0 || b == 0) return -1;
    a /= GCD(a, b); T lcm = a * b;
    if(lcm < 0 || lcm/a != b ) return -1;
    return lcm;
}
//===========================================================
int T, test_case;
double D;
int N,A;
double t[2012];
double x[2012];
double a[300];
vector< vector<int> > E;

void solve(){
    FOR(i, 0, A){
        double X0 = 0;
        double V0 = 0;

        double ans = 0;
        if(N == 1){
            ans = sqrt(2*D/a[i]);
            printf("%.7Lf\n",  ans);
            continue;
        }

        FOR(k, 1, N-1){
            double dt = t[k]-t[k-1];
            if (dt == 0) continue;
            double X1 = X0 + V0*dt + 0.5*a[i]*dt*dt;
            
            if(X1 <= x[k]){
                X0 = X1;
                V0 += a[i]*dt;
            }
            else{
                X0 = x[k];
                V0 = (x[k]-x[k-1])/dt;
            }
        }

        double dt1 = (-V0 + sqrt(V0*V0-2*a[i]*(X0-D)) )/a[i];
        double dt2 = (D-x[N-2])*(t[N-1] - t[N-2])/(x[N-1]-x[N-2]);
        if(dt1 < dt2)
            ans = t[N-2]+dt2;
        else
            ans = t[N-2]+dt1;
        
        printf("%.7Lf\n",  ans);
    }
}

void read(){
    GET3(D, N, A);
    FOR(i, 0, N) GET2(t[i], x[i]);
    FOR(i, 0, A) GET(a[i]);
}

int main()
{
    freopen("z:\\output.txt", "w", stdout);

    //freopen("z:\\input.txt", "r", stdin);
    //freopen("z:\\B-small-attempt0.in", "r", stdin);
    freopen("z:\\B-large.in", "r", stdin);


    GET(T);
    FORV(test_case, 1, T+1)
    {
	    //scanf("% % % % %", &, &, &, &, &);
        read();
        cout << "Case #" << test_case << ":\n";
        solve();
    }

    return 0;
}

