#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <time.h>

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))


using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;

int calc(vector<double> &A, vector<double> &B){
    int N=A.size(),result=0;
    vector<bool> done(N);
    REP(i,N){
        int low=-1,high=-1;
        REP(j,N) if(!done[j]){
            if(B[j]<A[i] && low==-1) low=j;
            if(B[j]>A[i] && high==-1) high=j;
        }
        if(high>-1) done[high]=true;
        else ++result,done[low]=true;
    }
    return result;
}

void doStuff() {
    int N,y=0,z=0;
    scanf("%d",&N);
    vector<double> A(N),B(N);
    REP(i,N) scanf("%lf",&A[i]);
    REP(i,N) scanf("%lf",&B[i]);
    sort(ALL(A)),sort(ALL(B));
    printf("%d %d\n", N - calc(B,A), calc(A,B));
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d: ", t + 1), doStuff();
    return 0;
}