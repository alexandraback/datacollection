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

const int maxn=10000+5;

int l,x;
int f[maxn];
char s[maxn];
int F[10][10];

void init(){
    F[0][0]=0,  F[0][1]=1,  F[0][2]=2,  F[0][3]=3;
    F[1][0]=1,  F[1][1]=4,  F[1][2]=3,  F[1][3]=6;
    F[2][0]=2,  F[2][1]=7,  F[2][2]=4,  F[2][3]=1;
    F[3][0]=3,  F[3][1]=2,  F[3][2]=5,  F[3][3]=4;
    for(int i=4;i<8;i++)
    for(int j=0;j<4;j++)
        F[i][j]=(F[i-4][j]+4)%8;
    for(int i=0;i<4;i++)
    for(int j=4;j<8;j++)
        F[i][j]=(F[i][j-4]+4)%8;
    for(int i=4;i<8;i++)
    for(int j=4;j<8;j++)
        F[i][j]=F[i-4][j-4];/*
    string str[8];
    str[0]="  1",str[1]="  i",str[2]="  j",str[3]="  k";
    for(int i=4;i<8;i++){
        str[i]=str[i-4];
        str[i][1]='-';
    }
    cout<<"   ";
    for(int j=0;j<8;j++)
        cout<<str[j];
    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<str[i];
        for(int j=0;j<8;j++)
            cout<<str[F[i][j]];
        cout<<endl;
    }//*/
}

int vis[8];
bool get(int &a,int &b,int r){
    memset(vis,-1,sizeof(vis));
    int now=0,tmp=-1;
    for(;a<x;b++){
        //printf("%d,%d:%d\n",a,b,now);
        if(now==r)return true;
        if(b==l)a++,b=0;
        if(b==0){
            if(tmp!=-1)vis[tmp]=now;
            tmp=now;
            if(vis[tmp]!=-1)return false;
        }
        now=F[now][f[b]];
    }
    if(now==r)return true;
    else return false;
}

bool solve(){
    int now=0;
    for(int i=0;i<l;i++)
        now=F[now][f[i]];
    //printf("(%d)\n",now);
    if(now==0)return false;
    if(now==4)return (x%2==1);
    return (x%4==2);
}

bool work(){
    if(!solve())return false;
    int a=0,b=0;
    if(!get(a,b,1))return false;
    if(!get(a,b,2))return false;
    return true;
}

int main(){
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    init();
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        scanf("%d%d",&l,&x);
        scanf("%s",s);
        for(int i=0;i<l;i++)
            if(f[i]=='1')f[i]=0;
            else if(s[i]=='i')f[i]=1;
            else if(s[i]=='j')f[i]=2;
            else if(s[i]=='k')f[i]=3;
            if(!work())printf("Case #%d: NO\n",Cas);
            else printf("Case #%d: YES\n",Cas);
    }
    return 0;
}
