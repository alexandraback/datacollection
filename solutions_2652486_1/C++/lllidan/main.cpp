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

int num[20],r,n,m,k,a[20];
bool ans[20];
bool ff;

bool check()
{
    clr(ans,false);
    //FOR(i,1,k)
    FOR(j,0,(1<<n)-1)
    {
        int b=1;
        int jj=j;
        FOR(co,1,n)
        {
            if (jj%2==1) b*=a[co];
            jj>>=1;
        }
        FOR(kk,1,k) if (b==num[kk]) ans[kk]=true;
    }

    FOR(i,1,k) if (!ans[i]) return false;
    return true;
}

void print()
{
    FOR(i,1,n) printf("%d",a[i]);
    puts("");
}

void ser(int w)
{
    if (ff) return;

    if (w==n)
    {
        if (check())
        {
            print();
            ff=true;
        }
        return;
    }

    FOR(i,2,m)
    {
        a[w+1]=i;
        ser(w+1);
    }
}

int main()
{
    //freopen("C-small-2-attempt0.in","r",stdin);freopen("Cs2.out","w",stdout);
    //freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);

    int T;
    read(T);
    puts("Case #1:");

    scanf("%d%d%d%d",&r,&n,&m,&k);
    FOR(kk,1,r)
    {
        ff=false;
        FOR(i,1,k) read(num[i]);
        ser(0);
        if (!ff)
        {
            FOR(i,1,n) printf("2");
            puts("");
        }
    }

    return 0;
}
