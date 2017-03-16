#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);

#define MM(arr, num) memset((arr), (num), sizeof((arr)))

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;

/*************************************************************/

char mat[55][55]; int N, M;

int sus(int i, int j){
    int ret = 0;
    if( i == 0)ret++;
    else if (mat[i-1][j] == '.')ret++;
    if( j == 0)ret++;
    else if (mat[i][j-1] == '.')ret++;
    if( i == N-1)ret++;
    else if (mat[i+1][j] == '.')ret++;
    if( j == M-1)ret++;
    else if (mat[i][j+1] == '.')ret++;

    return ret;
}

int rsus(int i, int j){
    if (mat[i][j] == '.')return 0;
    if (i < 0 || j < 0 || i == N || j == M)return 0;
    int ret = 0;
    if( i == 0);
    else if (mat[i-1][j] == '.')ret++;
    if( j == 0);
    else if (mat[i][j-1] == '.')ret++;
    if( i == N-1);
    else if (mat[i+1][j] == '.')ret++;
    if( i == M-1);
    else if (mat[i][j+1] == '.')ret++;

    return ret;
}

bool kachle(){

    REP(i,N)REP(j,M){
        if( mat[i][j] == '*' && sus(i,j) >= 2 ){
            mat[i][j] = '.';
            if (rsus(i,j-1) >= 2){ mat[i][j-1] = '.'; return true;}
            if (rsus(i,j+1) >= 2){ mat[i][j+1] = '.'; return true;}
            if (rsus(i-1,j) >= 2){ mat[i-1][j] = '.'; return true;}
            if (rsus(i+1,j) >= 2){ mat[i+1][j] = '.'; return true;}
            mat[i][j]= '*';
        }
    }
    return false;
}

int main(){

    DRI(cs);
    FOR(c,1,cs){

        printf("Case #%d:\n",c);

        RII(N,M) DRI(mine);

        int all = N*M;
        int bez = all - mine;
        REP(i,N)REP(j,M)mat[i][j] = '*';

        if( N == 1){REP(i,M){ if (i == 0)cout << 'c'; else if (i < bez) cout << '.'; else cout << '*';   } cout << endl;}
        else if( M == 1){REP(i,N) if (i == 0)cout << 'c' << endl; else if (i < bez) cout << '.' << endl; else cout << '*'<<endl;   }
        else{
            if (bez == 1);
            else if( bez == 2 || bez == 3 || bez == 5 || bez == 7) { cout << "Impossible" << endl; continue;}
            else if( bez / M >= 2 && bez % M != 1 ){
                 REP(i,N) REP(j,M) if ( bez > 0){ mat[i][j]= '.'; bez--;}
            }
            else if(bez%2 == 0){
                REP(j,M)if (bez > 0){ mat[0][j] = mat[1][j] = '.'; bez-=2; }
                FOR(i,2,N-1)REP(j,M)if (bez == 2 && j == M-1);else if (bez > 0){ mat[i][j] = '.'; bez--; }

            }
            else{
                if ( N == 2 || M == 2) { cout << "Impossible" << endl; continue;}
                REP(i,3)REP(j,3){ mat[i][j] = '.';  }

                bez -= 9;
                int cont = 0;

                while(bez > 0){
                    if ( kachle() )bez-= 2;
                    else { break; cont = 1;}
                }
                if (cont){ cout << "Impossible" << endl; continue;}


            }
             mat[0][0] = 'c';

            REP(i,N){
                REP(j,M) cout << mat[i][j];
                cout << endl;
            }
        }
    }


    return 0;
}

