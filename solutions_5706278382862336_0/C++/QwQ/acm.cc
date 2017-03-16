
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <string.h>
#include <time.h>
#include <fstream>
#include <set>
#include <stack>
#include <list>
#include <stdlib.h>
using namespace std;

#define READ freopen("acm.in","r",stdin)
#define WRITE freopen("acm.out","w",stdout)
#define ll long long
#define ull unsigned long long 
#define uint unsigned int
#define PII pair<int,int>
#define PDD pair<double,double>
#define fst first
#define sec second
#define MS(x,d) memset(x,d,sizeof(x))
#define INF 0x3f3f3f3f
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MOD 1000000007
#define MAX 2000

bool C(int a,int b)
{
    int c=__gcd(a,b);
    b/=c;
    while(b!=1)
    {
        if(b%2)
            return false;
        b/=2;
    }
    return true;
}

int get(int a,int b,int n)
{
    if(a >= b)
        return n;
    get(a, b/2, n+1);
}

int main()
{
    READ;
    WRITE;
    int cas;
    scanf("%d", &cas);
    for(int T=1;T<=cas;T++)
    {
        int a,b;
        scanf("%d/%d",&a,&b);
        if(C(a,b))
        {
            int g=__gcd(a,b);
            a/=g,b/=g;
            printf("Case #%d: %d\n",T,get(a,b,0));
        }
        else
            printf("Case #%d: impossible\n", T);            
    }
    return 0;
}