/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

vector<int> a,b,k;
ill dp[30][2][2][2];

ill f(int idx,int A,int B,int K) {
    // cout << idx << " " << A << " " << B << " " << K << endl;
    if ( idx == 30 ) return 1;
    ill &res = dp[idx][A][B][K];
    if ( res != -1 ) return res;
    res = 0;
    int ax = a[idx], bx = b[idx], kx = k[idx];

    if ( K == 0 ) {
        if ( A == 0 && B == 0 ) {
            F(i,0,2) {
                F(j,0,2) {
                    res += f(idx+1,0,0,0);
                }
            }
        } else if ( A == 0 && B == 1 ) {
            F(i,0,2) {
                F(j,0,bx+1) {
                    res += f(idx+1,0,j==bx,0);
                }
            }
        } else if ( A == 1 && B == 0 ) {
            F(i,0,ax+1) {
                F(j,0,2) {
                    res += f(idx+1,i==ax,0,0);
                }
            }
        } else {
            F(i,0,ax+1) {
                F(j,0,bx+1) {
                    res += f(idx+1,i==ax,j==bx,0);
                }
            }
        }
        return res;
    }


    if ( A == 0 && B == 0 ) {
        F(i,0,2) {
            F(j,0,2) {
                int xx = (i&j);
                if ( xx > kx ) continue;
                res += f(idx+1,0,0,xx==kx);
            }
        }
    } else if ( A == 0 && B == 1 ) {
        F(i,0,2) {
            F(j,0,bx+1) {
                int xx = (i&j);
                if ( xx > kx ) continue;
                res += f(idx+1,0,j==bx,xx==kx);
            }
        }
    } else if ( A == 1 && B == 0 ) {
        F(i,0,ax+1) {
            F(j,0,2) {
                int xx = (i&j);
                if ( xx > kx ) continue;
                res += f(idx+1,i==ax,0,xx==kx);
            }
        }
    } else {
        F(i,0,ax+1) {
            F(j,0,bx+1) {
                int xx = (i&j);
                if ( xx > kx ) continue;
                res += f(idx+1,i==ax,j==bx,xx==kx);
            }
        }
    }
    return res;
}

void fill( vector<int> &x,ill X) {
    x.clear();
    int iter = 0;
    while ( iter < 30 ) {
        x.pb(X%2);
        X /= 2;
        iter++;
    }
    reverse(x.begin(),x.end());
    // F(i,0,x.size()) cout << x[i];
    // cout << endl;
}

int main() {

    // input();

    int t, test =1;
    cin >> t;

    while ( t-- ) {

        ill A,B,K;
        
        cin >> A >> B >> K;
        A-- ; B--; K--;
        fill(a,A);fill(b,B);fill(k,K);

        ill ans = 0 ,ans2 =0;
        // F(i,0,A+1) { F(j,0,B+1) { if ( (i&j) <= K ) ans2++; } }
        M(dp,-1);
        // cout << a[27] << " " << b[27] << endl;
        ans = f(0,1,1,1);
        // assert(ans==ans2);
        
        cout << "Case #" << test++ << ": ";
        cout << ans << endl;

    }

    return 0;
}