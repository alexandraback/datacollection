#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=(int)1e6+5;

int vis[maxn];
int pre[maxn];

int fan(int x){
    int ans=0;
    while(x){
        ans=ans*10+x%10;
        x=x/10;
    }
    return ans;
}
/*
int check(int x){
    int tmp=0,y=x;
    while(y){
        tmp++;
        y=y/10;
    }
    tmp=(tmp+1)/2;
    y=x;
    for(int i=0;i<tmp;i++)
        y=y/10;
    for(int i=0;i<tmp;i++)
        y=y*10;
    y++;
    if(y<=20)return x;
    return check(fan(y))+1+x-y;
}*/

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.ans","w",stdout);
    vis[1]=1;
    pre[1]=0;
    for(int i=1;i<maxn;i++){
        vis[i]=vis[i-1]+1,pre[i]=i-1;
        if(i%10==0)continue;
        if(fan(i)<i && vis[fan(i)]+1<vis[i]){
            vis[i]=vis[fan(i)]+1;
            pre[i]=fan(i);
        }
    }
    int n,t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d",&n);
        printf("Case #%d: %d\n",cas,vis[n]);/*
        while(pre[n]){
            if(pre[n]!=n-1)printf("%d,%d\n",n,pre[n]);
            n=pre[n];
        }*/
    }
    return 0;
}
