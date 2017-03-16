#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define PB push_back
#define MP make_pair
#define INF 0x7fffffff
using namespace std;
typedef long long LL;

int main()
{
         freopen("D-small-attempt0.in","r",stdin);
         freopen("D-small-attempt0.out","w",stdout);
         int T,ca=0;
         scanf("%d",&T);
         while(T--){
                  int X,R,C;
                  cin>>X>>R>>C;
                  if(R<C) swap(R,C);
                  printf("Case #%d: ",++ca);
                  if((R*C)%X!=0) puts("RICHARD");
                  else {
                           if(X==3&&C==1) puts("RICHARD");
                           else if(X==4&&(C==1||C==2)) puts("RICHARD");
                           else puts("GABRIEL");
                  }
         }
         return 0;
}
