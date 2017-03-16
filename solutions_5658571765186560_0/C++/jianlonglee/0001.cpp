#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>

#define ll long long
#define maxn 10005*26
#define inf 0x3f3f3f3f
#define bug puts("here")

using namespace std;

int T,L,n,m,x,y;

int main()
{
   freopen("D-small-attempt0.in","r",stdin);
   freopen("D-small.out","w",stdout);
   cin>>T;
   int kase=1;
   while(T--){
    scanf("%d %d %d",&n,&x,&y);
    if(x>y)
        swap(x,y);
    m=0;
    if(n==1){
        m=1;
    }
    else if(n==2){
        if(x%2==0||y%2==0)
            m=1;
    }
    else if(n==3){
        if(x==2&&y==3)
            m=1;
        if(x==3&&y==3)
            m=1;
        if(x==3&&y==4)
            m=1;
    }
    else{
        if(x==3&&y==4)
            m=1;
        if(x==4&&y==4)
            m=1;
    }
    if(m)
        printf("Case #%d: GABRIEL\n",kase++);
    else printf("Case #%d: RICHARD\n",kase++);
   }
}
