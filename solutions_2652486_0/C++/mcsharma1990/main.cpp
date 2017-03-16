// Author : Mahesh

/* 1. Did u interpret the qns correctly ?
 2. Is your i/o correct ?
 3. Int overflow, double precesion
 4. Array size correct ?
 5. Clearing/resetting vector, map etc.
 6. Stack ovrflow
 7. Global/local conflict
 8. Check for obvious typo(most imp)
 */

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

/* Program Body starts here */


int main() {
    
    cout<<"Case #1:\n";
    int T = SS;
    int R = SS, N = SS, M = SS, K = SS;
    rep(_, R) {
        int v[7];
        int C5 = 0, C2 = 0, C3 = 0, C4 = 0;
        rep(i, K) {
            v[i] = SS;
        }
        
        rep(i, K) {
            int c5 = 0, c2 = 0, c3 = 0, c4 = 0;
            int save = v[i];
            while(v[i] % 5 ==0) {
                v[i]/=5;
                c5++;
            }
            C5 = max(c5, C5);
            v[i] = save;
            c3 = 0;
            
            while(v[i] % 3 ==0) {
                v[i]/=3;
                c3++;
            }
            C3 = max(c3, C3);
            
            v[i] = save;
            c2 = 0;
            if (v[i] == 2) {
                c2++;
            }
            C2 = max(c2, C2);
            if (v[i] % 16 ==0) {
                C4 = max(C4, 1);
            }
            if (v[i]%32==0){
                C4 = max(C4, 2);
            }
            if (v[i] %64 ==0) {
                C4 = max(C4, 3);
            }
            if (v[i] % 8 ==0 && v[i]%16) {
                C2 = max(1, C2);
            }
            if( v[i] % 32 ==0 && v[i]%64) {
                C2 = max(1, C2);
            }
        }
        
        cout<<S(C2, '2')+S(C3, '3')+S(C4, '4')+S(C5, '5');
        cout<<S(N-C2-C3-C4-C5, '2');
        cout<<endl;
    }
    
}