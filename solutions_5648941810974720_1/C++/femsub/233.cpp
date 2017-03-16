//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
using namespace std;
double esp=1e-11;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define cle(a) while(!a.empty())a.pop()
#define mem(p) memset(p,0,sizeof(p))
#define memf(p) memset(p,0x3f,sizeof(p))
#define memn(p) memset(p,-1,sizeof(p))
#define mp(A, B) make_pair(A, B)
#define pb push_back
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long int LL;
typedef long double LD;
const double PI = acos(-1.0);
const LL INF=0x3f3f3f3f;
const int maxn=3010;
int sum[500];
int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    //map<long long int,int>ma;                 %I64d
    //vector<int>::iterator iter;
    //memset(m,0,sizeof(int));               for(iter=trtr[rt].begin();iter!=trtr[rt].end();iter++)
    //for(int x=1;x<=n;x++)
    //for(int y=1;y<=n;y++)
    //scanf("%d%d",&a,&b);
    //scanf("%d",&n);
    //printf("%d\n",ans);
    int T;
    char s[10000];
    scanf("%d",&T);
    for(int gg=1;gg<=T;gg++)
    {
        scanf("%s",s);
        int len=strlen(s);
        mem(sum);
        for(int x=0;x<len;x++)
            sum[s[x]]++;
        int t;
        printf("Case #%d: ",gg);
        t=sum['Z'];
        for(int x=1;x<=t;x++)printf("%d",0);
        t=sum['O']-sum['Z']-sum['W']-sum['U'];
        for(int x=1;x<=t;x++)printf("%d",1);
        t=sum['W'];
        for(int x=1;x<=t;x++)printf("%d",2);
        t=sum['H']-sum['G'];
        for(int x=1;x<=t;x++)printf("%d",3);
        t=sum['U'];
        for(int x=1;x<=t;x++)printf("%d",4);
        t=sum['F']-sum['U'];
        for(int x=1;x<=t;x++)printf("%d",5);
        t=sum['X'];
        for(int x=1;x<=t;x++)printf("%d",6);
        t=sum['S']-sum['X'];
        for(int x=1;x<=t;x++)printf("%d",7);
        t=sum['G'];
        for(int x=1;x<=t;x++)printf("%d",8);
        t=sum['I']-sum['F']+sum['U']-sum['X']-sum['G'];
        for(int x=1;x<=t;x++)printf("%d",9);
        putchar('\n');
    }
    return 0;
}

