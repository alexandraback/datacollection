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
#define FRI(a) scanf("%lf", &a);
#define RII(a, b) scanf("%d %d", &a, &b);

#define MM(arr, num) memset((arr), (num), sizeof((arr)))

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;

/*************************************************************/

int N;

double nao[1050];
double ken[1050];

int main(){

    int w, dw, nU, kU, nD, kD;

    DRI(cs);
    FOR(c,1,cs){

        RI(N);
        REP(i,N)FRI(nao[i]);
        REP(i,N)FRI(ken[i]);

        sort(nao, nao + N);
        sort(ken, ken + N);

        w = 0;
        int j = 0;
        REP(i,N){
            while(ken[j] < nao[i] && j < N){j++;w++;}
            if (j >= N)break;
            j++;
        }

        dw = 0;

        nU = kU = N-1;
        nD = kD = 0;

        while(nU != nD){

            if (nao[nU] > ken[kU] ){dw++;nU--;kU--;}
            else{nD++;kU--;}

        }
        if (nao[nU] > ken[kU] )dw++;

        printf("Case #%d: %d %d\n",c,dw, w);

    }


    return 0;
}

