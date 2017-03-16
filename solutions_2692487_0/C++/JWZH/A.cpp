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
const int size = 1000000 + 5;
int mote[size];

int cal(int cur,int k,int n)
{
   int i;
   int ans = 0;
   for(i = k; i < n; i++){
      if(mote[i] >= cur){
        int t = 0,tA = cur;
        if(tA == 1) break;
        while(tA <= mote[i]){
            tA += tA-1;
            t++;
        }
        tA += mote[i];
        t += cal(tA,i+1,n);
        if(t < n-i) {
            return t;
        } 
        else break;
      }
      else cur += mote[i];
   }
   ans += n-i;
   return ans;
}
int main()
{
    int T;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    sf(T);
    for(int nc = 1; nc <= T; nc++){
       int A,N; 
       sf2(A,N);
       for(int i = 0; i < N; i++)
           sf(mote[i]);
       sort(mote,mote+N);
       printf("Case #%d: %d\n",nc,cal(A,0,N));
    }

}

