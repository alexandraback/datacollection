/*******************************************************************
** AUTHOR   : Wenzheng jiang
** EMAIL    : jwzh.hi@gmail.com 
** OS       : ArchLinux 
** EDITER   : VIM
******************************************************************/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define pf(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,k)printf("%d %d %d %d\n",x,y,z,k)
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,k) scanf("%d%d%d%d",&x,&y,&z,&k)
typedef long long ll;
double const eps = 1e-6;
const int inf = 0x3fffffff;
const int size = 100000 + 5;

int v[size];
int E,R,N;	
int ans = 0;
void dfs(int cur,int rm,int gain)
{
    if(rm > E) rm = E;
   if(cur == N+1){
       ans = max(gain,ans); 
       return ;
   }
   for(int i = 0; i <= rm; i++){
      dfs(cur+1,rm-i+R,gain+v[cur]*i); 
   } 
}
int main()
{
    int T;
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    sf(T);
    for(int nc = 1; nc <= T; nc++){
        sf3(E,R,N);
        ans = 0;
        for(int i = 1; i <= N; i++)
            sf(v[i]);
        dfs(1,E,0);
        printf("Case #%d: %d\n",nc,ans);
    }
}

