#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

void scase() {    
    int A,N;
    scanf("%d%d",&A,&N);
    vector<int> V;
    REP(i,N) {
        int p;
        scanf("%d",&p);
        V.push_back(p);
    }
    
    if (A == 1) {
        printf("%d\n", N);
        return;
    }
    
    sort(V.begin(), V.end());
    int result = N;
    REP(M,N+1) {
        int tmp = (N - M);
        int X = A;
        REP(i,M) {
            while (V[i] >= X) {
                ++tmp;
                X += X - 1;
            }
            X += V[i];
        }
        result = min(result, tmp);
    }
    printf("%d\n", result);
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
