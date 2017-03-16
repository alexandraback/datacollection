/*
 * Author:  vawait
 * Created Time:  2016/4/16 9:13:32
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
int n;
char a[2100] , b[2100];

void init()
{
    scanf("%s",a+1);
    n = strlen( a + 1 );
}

void work()
{
    int l = 1010 , r = l;
    b[l] = a[1];
    rep(i,2,n) if ( a[i] >= b[l] ) {
        b[--l] = a[i];
    } else {
        b[++r] = a[i];
    }
    rep(i,l,r) printf("%c",b[i]);
    puts("");
}

int main()
{
    //freopen("a.out","w",stdout);
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
