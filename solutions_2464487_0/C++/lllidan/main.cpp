/*
ID: zhqy462
LANG: C++
TASK: preface
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <fstream>
#include <bitset>
#include <iomanip>
using namespace std;
#define INF 0x7ffffff
#define eps 1e-8
#define pi 3.14159265358979626
#define LL long long
#define clr(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define exch(a,b) {int t111=a;a=b;b=t111;}
#define sp struct point
#define sl struct line
#define zero(x) (((x)>0?(x):-(x))<eps)
#define read(a) scanf("%d",&a);

#define N 550
#define M 500005
#define INT_MAX 100000000

#define inf 1<<25

#define maxe 50000
#define maxn 250

LL r,t;

bool Less(LL a,LL b)
{
    LL hh;
    long double aa=a;
    long double rr=r;
    long double h=2*aa*(aa+1)+(2*rr+1)*aa;
    //if (h<0) cout<<"********";
    if (h>3e18) return false;
    else
    {
        hh=2*a*(a+1)+(2*r+1)*a;
        return hh<=b;
    }
}

LL bs(LL l,LL h)
{
    LL m;
    while(l<h)
    {
        m=(l+h)>>1;
        if (Less(m,t)) l=m+1;
        else h=m;
    }
    return l;
}

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);freopen("As.out","w",stdout);
    //freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);

    int T;
    read(T);
    FOR(kk,1,T)
    {
        printf("Case #%d: ",kk);
        scanf("%lld%lld",&r,&t);
        t-=2*r+1;

        LL a,b,m;
        a=1;
        b=sqrt(t);//(LL)sqrt(t/(r+2))+1;
        //printf("%lld\n",bs(a,b));
        cout<<bs(a,b)<<endl;
    }

    return 0;
}
