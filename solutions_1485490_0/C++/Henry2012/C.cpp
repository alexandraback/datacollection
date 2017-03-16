#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

#define sz(x) ((int)x.size())
#define mp(x,y) make_pair(x, y)
#define pb(x) push_back(x)

template<class T> inline T gcd(T a,T b)
{
    if(a<0) return gcd(-a, b);
    if(b<0) return gcd(a, -b);

    return (b==0) ? a : gcd(b, a % b);
}

template<class T> inline T lcm(T a,T b)
{
    if(a<0) return lcm(-a,b); 
    if(b<0)return lcm(a,-b);

    return a*(b/gcd(a,b));
}

inline bool isPrime(ll n)
{
    if(n<=1)  return false;

    for (ll i=2;i*i<=n; i++) 
        if (n%i==0) return false;

    return true;
}

using namespace std;

// const bool FILE_WRITE = false;
const bool SHOW_TIME = 
true;

//#define MYDEBUG

#define START_CLOCK  clock_t start_clock = clock();
#define PRINT_TIME   if(SHOW_TIME) cout << (clock() - start_clock) / double(CLOCKS_PER_SEC) << endl;

// ---  Solution begins. ---------------------- 

#define NN 5
ll cbox[NN];
ll tbox[NN];
ll ctoy[NN];
ll ttoy[NN];
ll gain[NN][NN];
ll boxleft[NN][NN];
ll toyleft[NN][NN];

ll  Solve(int n, int m)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            gain[i][j] = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            boxleft[i][j] = cbox[i];
            toyleft[i][j] = ctoy[j];
        }
    }

    for (int j=0; j<m; j++) {
        if (tbox[0] == ttoy[j]) {
            gain[0][j] = min(cbox[0], ctoy[j]);
            boxleft[0][j] -= gain[0][j];
            toyleft[0][j] -= gain[0][j];
        }
    }

    for (int i=1; i<n; i++) {
        if (tbox[i] == ttoy[0]) {
            gain[i][0] = min(cbox[i], ctoy[0]);
            boxleft[i][0] -= gain[i][0];
            toyleft[i][0] -= gain[i][0];
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            ll score1 = 0;
            if (boxleft[i][j-1] > 0) {
                if (tbox[i] == ttoy[j]) {
                    score1 = gain[i][j-1] + min(boxleft[i][j-1], toyleft[i][j]);
                } else {
                    score1 = gain[i][j-1]; 
                }
            }

            ll score2 = 0;
            if (toyleft[i-1][j] > 0) {
                if (tbox[i] == ttoy[j]) {
                    score2 = gain[i-1][j] + min(boxleft[i][j], toyleft[i-1][j]);
                } else {
                    score2 = gain[i-1][j]; 
                }
            }

            ll score3 = 0;
            if (tbox[i] == ttoy[j]) {
                score3 = gain[i-1][j-1] + min(boxleft[i][j], toyleft[i][j]);
            } else {
                score3 = gain[i-1][j-1]; 
            }

            ll best = max(score1, max(score2, score3));

            if (best == score1) {
                boxleft[i][j] = boxleft[i][j-1] - min(boxleft[i][j-1], toyleft[i][j]);
                toyleft[i][j] -= min(boxleft[i][j-1], toyleft[i][j]);
            }
            else if (best == score2) {
                boxleft[i][j] -= min(boxleft[i][j], toyleft[i-1][j]);
                toyleft[i][j] =  toyleft[i-1][j] -min(boxleft[i][j], toyleft[i-1][j]);
            } else {
                boxleft[i][j] -=  min(boxleft[i][j], toyleft[i][j]);
                toyleft[i][j] -=  min(boxleft[i][j], toyleft[i][j]);
            }

            //ll best = 0;
            //for (int k=0;k<j; k++) {
            //    if (gain[i-1][k] > best) {
            //         best = gain[i-1][k];

            //    }
            //}
            //best = best + min(cbox[i], ctoy[j]);

            //for (int k=0;k<j; k++) {
            //    if (gain[i][k] > 0 && boxleft[i][k]) {
            //        min(boxleft[i][k], 
            //        if (
            //        best == max(best, gain[i][k] + boxleft[i][k]);
            //    }
            //}

            //for (int k=0;k<i; k++) {
            //    if (gain[k][j] > 0 && toyleft[k][j]) {
            //        best == max(best, gain[k][j] + toyleft[k][j]);
            //    }
            //}

            gain[i][j] = best;

        }
    }

    ll ans = 0;
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            ans = max(ans, gain[i][j]);
        }
    }

    return ans;
}

int main(int argc, char * argv[])
{
    ifstream fin; 
    FILE * fout;
    int run_mode(0);
    switch (run_mode)
    {
    case -1:
        fin.open("C.in");
        fout = stdout;
        break;
    case 0: 
        fin.open("C-small-attempt0.in");
        fout = fopen("C-small-attempt0.out", "w");
        break;
    case 1: 
        fin.open("C-small-attempt1.in");
        fout = fopen("C-small-attempt1.out", "w");
        break;
    case 10:
        fin.open("C-large.in");
        fout = fopen("C-large.out", "w");
     //   fout =stdout;
        break;
    }
    assert(fin && fout);

    START_CLOCK;

    int T;  fin >> T;
    for (int t=0; t<T; t++) {
        int n,m;   fin >> n >> m; 
        for (int j=0; j<n; j++) {
            fin >> cbox[j];
            fin >> tbox[j];
        }
        for (int j=0; j<m; j++) {
            fin >> ctoy[j];
            fin >> ttoy[j];
        }

        ll ans = Solve(n,m);
        fprintf(fout, "Case #%d: %I64d%\n", t+1, ans);
       //  fprintf(stdout, "Case #%d: %I64d\n", t+1, ans);
    }

    PRINT_TIME

    return 0;
}


