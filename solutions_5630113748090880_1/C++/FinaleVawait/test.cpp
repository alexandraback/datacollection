/*
 * Author:  vawait
 * Created Time:  2016/4/16 9:53:13
 * Problem: test.cpp
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long lint;
int n , sum[5000] , a[1000];

void init()
{
    int x;
    clr( sum , 0 );
    scanf("%d",&n);
    rep(i,1,2*n-1)
        rep(j,1,n) {
            scanf("%d",&x);
            sum[x] ++;
        }
}

void work()
{
    int s = 0;
    rep(i,0,3000) if ( sum[i] & 1 ) a[++s] = i;
    rep(i,1,n) printf(" %d",a[i]);
    puts("");
}

int main()
{
    //freopen("a.out","w",stdout);
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d:",i);
        init();
        work();
    }
    return 0;
}
