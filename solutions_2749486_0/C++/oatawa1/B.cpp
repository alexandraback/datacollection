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
#define pii pair<int , int>
#define pis pair<int , string>
#define pisii pair<pis , pii>
//set<pisii> q;
int a,b;

void solve()
{
    scanf("%d %d",&a,&b);
    if(a < 0)
        FOR(i , 0 , -a)
            printf("EW");
    else
        FOR(i , 0 , a)
            printf("WE");
    if(b < 0)
        FOR(i , 0 , -b)
            printf("NS");
    else
        FOR(i , 0 , b)
            printf("SN");
    printf("\n");
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B.out","w",stdout);
    cin >> tCase;
    FOR(tt , 0 , tCase)
    {
        printf("Case #%d: ",tt+1);
        solve();
    }
    return 0;
}


