#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <climits>
#include <sstream>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR_EACH(it,v) for(__typeof((v).begin()) it = (v).begin(); it!=(v).end(); ++it)
#define show(x) cout << #x << ": " << x << endl;

template<typename T>
ostream& operator<<(ostream &o, const vector<T>&v){
    FOR_EACH(x, v){
        if(x==v.begin()) o << "[";
        else o << ", ";
        o << *x;
    }
    o << "]";
    return o;
}

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int>VI;
typedef vector<vector<int> >VII;

int stones(int level){
    return (1 + 4*level + 1)/2*(level+1);
}

const int L = 3000;

double M[L][L];
double C2(int n, int k){
    assert(n<L);
    if(k<0 || k>n) return 0.;
    if(n==0) return 1.;

    double &res = M[n][k];
    if(res>=-1e-9) return res;

    res = 0.;
    if(k==0 || k==n){
        res = C2(n-1,0) / 2.;
    } else {
        res = (C2(n-1,k-1) + C2(n-1, k))/2.;
    }
    return res;
}

double MS[L][L];
double sums(int n, int k){
    assert(n<L);
    double &res = MS[n][k];
    if(res>-1e-9) return res;

    if(k==n) return C2(n,k);

    res = sums(n,k+1) + C2(n,k);
    return res;
}

double solve(){
    int n,x,y;
    scanf("%d %d %d", &n, &x, &y);
    x = abs(x);

    int level = (x+y)/2;
    if(stones(level) <= n){
        return 1.;
    }
    if(x==0) return 0.;
    n -= stones(level-1);

    int need = y+1;
    if(n < need) return 0.;

    int side = level*2;

    int bad = n - need + 1;

    //cout << endl;
    //show(need);
    //cout << "x: " << x << ", y: " << y << ", level: " << level << endl;
    //cout << "bad: " << bad << ", n = " << n << endl;
    if(bad > side) return 1.;

    return 1.-sums(n,bad);
}

int main(int argc,char *argv[]) {
    /*
    for(int i=0;;i++){
        printf("%d) %d\n", i, stones(i));
        if(stones(i)>1000000) return 0;
    }
    */
    REP(i,L)REP(j,L)M[i][j]=MS[i][j] = -1;
    int T; scanf("%d", &T);
    for(int t=1; t<=T; t++){
        printf("Case #%d: ", t);
        printf("%.10lf\n", solve());
    }
}
