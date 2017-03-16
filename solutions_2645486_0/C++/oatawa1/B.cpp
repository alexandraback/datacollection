/*
LANG: C++
TASK: xxx
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<sstream>

using namespace std;
#define x first
#define y second

#define FOR(i,a,b) for(__typeof(b)i = a; i < b;i++)
#define FORE(i,a,b) for(__typeof(b)i = a; i <= b;i++)
#define FOR_R(i,a,b) for(__typeof(b)i = a; i > b;i--)
#define FORE_R(i,a,b) for(__typeof(b)i = a; i >= b;i--)
#define TR(it , c) for(__typeof((c).end())it = (c).begin(); it != (c).end();it++)
int tCase;
int e,r,n;
int v[20];
int ans ;
void gen(int p , int ene , int res)
{

    if(p == n)
    {
        ans = max(ans , res);
        return;
    }
    FORE(i , 0 , ene)
    {
        //printf("%d %d %d >> %d\n",p,ene,res,i);
        gen(p+1 , min(e , ene-i+r) , res+(i*v[p]));
    }
}

void solve(int tt)
{
    ans = -1;
    printf("Case #%d: ",tt);
    scanf("%d %d %d",&e,&r,&n);
    FOR(i , 0 , n)
        scanf("%d",&v[i]);
    gen(0 , e , 0);
    printf("%d\n",ans);
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    cin >> tCase;
    FOR(tt , 0 , tCase)
    {
        solve(tt+1);
    }
    return 0;
}


