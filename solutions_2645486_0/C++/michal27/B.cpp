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

int vys;
vector<int> A;
int e,r,n;

int rek(int zac, int kon, int mam, int chcem) {
    if(kon<=zac) return 0;
    int kde=zac;
    for(int i=zac; i<kon; i++) if(A[kde]<A[i]) kde=i;
    int zaloha=mam;
    mam+=(kde-zac)*r;
    mam=min(mam,e);
    int ziskat=(kon-kde)*r;
    ziskat=min(ziskat,e);
    int mozem;
    if(ziskat>=chcem) mozem=mam;
    else mozem=mam-(chcem-ziskat);
    return mozem*A[kde] + rek(zac,kde,zaloha,mam) + rek(kde+1,kon,min(e,r+mam-mozem),chcem);
}

int main() {
    int t1;
    scanf("%d",&t1);
    For(i1,t1) {
        scanf(" %d %d %d",&e,&r,&n);
        A.clear(); A.resize(n);
        For(i,n) scanf(" %d",&A[i]);
        printf("Case #%d: %d\n",i1+1,rek(0,n,e,0));
    }
return 0;
}
