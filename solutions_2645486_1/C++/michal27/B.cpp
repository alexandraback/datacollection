#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;

vector<ll> A;
ll e,r,n;

ll rek(int zac, int kon, ll mam, ll chcem) {
    if(kon<=zac) return 0;
    ll kde=zac;
    for(int i=zac; i<kon; i++) if(A[kde]<A[i]) kde=i;
    ll zaloha=mam;
    mam+=(kde-zac)*r;
    mam=min(mam,e);
    ll ziskat=(kon-kde)*r;
    ziskat=min(ziskat,e);
    ll mozem;
    if(ziskat>=chcem) mozem=mam;
    else mozem=mam-(chcem-ziskat);
    return mozem*A[kde] + rek(zac,kde,zaloha,mam) + rek(kde+1,kon,min(e,r+mam-mozem),chcem);
}

int main() {
    int t1;
    scanf("%d",&t1);
    For(i1,t1) {
        scanf(" %lld %lld %lld",&e,&r,&n);
        A.clear(); A.resize(n);
        For(i,n) scanf(" %lld",&A[i]);
        printf("Case #%d: %lld\n",i1+1,rek(0,n,e,0));
    }
return 0;
}
