/*
 * =====================================================================================
 *
 *         Author:  KissBuaa.DS(AC)
 *        Company:  BUAA-ACMICPC-Group
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define LL long long
#define CLR(x) memset(x,0,sizeof(x))
#define typec double
#define sqr(x) ((x)*(x))
#define abs(x) ((x)<0?(-(x)):(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define inf 100000000
//For C++
#include <cctype>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
int n,m,T,a,b;
int t[10];
LL ans;
set<int> mem;
LL gao(int x){       
     int cnt=0;
     int xx=x;
     mem.clear();
     while (x){
           t[cnt++]=x%10;
           x/=10;
     } 
     for (int i=0;i<cnt/2;++i) swap(t[i],t[cnt-1-i]);
     LL ret=0;
     for (int i=0;i<cnt;++i){
         int res=0;
         for (int j=0;j<cnt;++j)
             res=res*10+t[(i+j)%cnt];
         if (res<xx && a<=res && res<=b && mem.find(res)==mem.end()) {
                    ++ret;
                    mem.insert(res);
         }
     }
     return ret;
}
int main(){
    //freopen("C-large.in","r",stdin);
    //freopen("C.out","w",stdout);
    scanf("%d",&T);
    int icase=0;
    while (T--){
          scanf("%d%d",&a,&b);
          //mem.clear();
          ans=0;
          for (int i=b;i>=a;--i){
              LL tmp=gao(i);
              ans+=tmp;
              //printf("%d %lld\n",i,tmp);
          }
          printf("Case #%d: %lld\n",++icase,ans);
    }
}
