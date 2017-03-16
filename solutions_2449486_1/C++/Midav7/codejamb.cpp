// created by Marchecnko Vadim [midav7]
// I did it just for fun =)
// v 0.7

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cmath>
#include <map>
#include <set>
#include <climits>

#define foread freopen("input.txt","r",stdin)
#define fowrite freopen("output.txt","w",stdout)
#define pi 3.141592

using namespace std;
int _map[200][200];
int maxx[200],maxy[200];
int main(){
  foread;
  fowrite;
  int t,n,m,flag;
  scanf("%d",&t);
  for (int kk=1; kk<=t; ++kk) {
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i) 
      for (int j=1; j<=m; ++j)
        scanf("%d",&_map[i][j]);
    printf("Case #%d: ",kk);  
    flag=0;
    for (int j=1; j<=m; ++j) maxy[j]=-1;
    for (int j=1; j<=m; ++j)
      for (int i=1; i<=n; ++i)
        maxy[j]=max(maxy[j],_map[i][j]);
    for (int i=1; i<=n; ++i) maxx[i]=-1;
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
        maxx[i]=max(maxx[i],_map[i][j]);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
        if (_map[i][j]<maxx[i] && _map[i][j]<maxy[j]) flag=1;
    if (flag==1) printf("NO\n");
    else printf("YES\n");
   }
return 0;
}