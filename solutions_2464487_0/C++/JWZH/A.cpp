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

int main()
{
    int  T;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    sf(T);    
    for(int nc = 1; nc <= T; nc++){
        int r,t,cnt = 0,ans = 0;
        sf2(r,t);
        for(; ; r += 2){
            if(cnt+(r+1)*(r+1)-r*r > t) break;
            cnt += (r+1)*(r+1)-r*r ;
            ans++;
        }
        printf("Case #%d: %d\n",nc,ans);
    }
}

