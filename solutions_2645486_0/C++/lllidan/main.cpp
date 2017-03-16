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

#define N 11000
#define M 500005
#define INT_MAX 100000000

#define inf 1<<25

#define maxe 50000
#define maxn 250

int e,r,n,v[N];
LL Max;

void ser(int w,LL c,int en)
{
    if (w>n)
    {
        if (c>Max) Max=c;
        return ;
    }
    FOR(i,0,en) ser(w+1,c+v[w]*i,min(en-i+r,e));
}

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);freopen("Bs.out","w",stdout);
    //freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);

    int T;
    read(T);
    FOR(kk,1,T)
    {
        printf("Case #%d: ",kk);
        scanf("%d%d%d",&e,&r,&n);
        FOR(i,1,n) read(v[i]);
        Max=0;
        ser(1,0,e);
        printf("%lld\n",Max);
    }

    return 0;
}
