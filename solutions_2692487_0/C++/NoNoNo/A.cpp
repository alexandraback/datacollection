#include<cstdio>
#include<iostream>
#include<cassert>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second

const int MAXN = 110;
int n,a;
int mot[MAXN];

void readData(){
    scanf("%d%d",&a, &n);
    REP(i,n){
        scanf("%d", mot + i);
    }
    sort(mot, mot + n);
}

int getA(int start, int prz){
    if (prz == n) return 0;
    if (start > mot[prz]){
        return getA(start + mot[prz], prz + 1);
    }
    else {
        if (start == 1) return n - prz;
        return min(getA(2*start - 1, prz) + 1, n - prz); //uwaga tu
    }
}

int main(){
    int t;
    scanf("%d",&t);
    REP(i,t){
        readData();
        printf("Case #%d: %d\n",i + 1, getA(a,0));
    }
}

