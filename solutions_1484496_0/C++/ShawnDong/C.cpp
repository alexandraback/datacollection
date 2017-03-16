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
//#include <stdbool.h>
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
using namespace std;
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
int n,m,T;
const int M=1<<20;
int a[20],b[M+1];
vector<int> c[2000000];
void gao(int x){
     int xx=x;
     for (int i=0;i<n;++i){
         if (xx & 1) b[x]+=a[i];
         xx>>=1;
     }
}
int main(){
    freopen("C-small-attempt0 (2).in","r",stdin);
    freopen("C.out","w",stdout);
    cin>>T;
    for (int icase=1;icase<=T;++icase){
        cin>>n;
        for (int i=0;i<n;++i) cin>>a[i];
        CLR(b);
        for (int i=1;i<=2000000;++i) c[i].clear();
        m=1<<n;
        for (int i=0;i<(m);++i) gao(i);
        for (int i=1;i<m;++i)
            c[b[i]].push_back(i);
        int p=-1,q=-1;
        for (int i=1;i<=2000000;++i)
            if (p<0)
            for (vector<int>::iterator iter=c[i].begin();iter!=c[i].end();++iter)
                if (p<0)
                for (vector<int>::iterator iiter=iter+1;iiter!=c[i].end();++iiter)
                    if((*iter) & (*iiter));
                    else{
                         p=*iter;
                         q=*iiter;
                    }
        printf("Case #%d:\n",icase);
        bool f=false;
        for (int i=0;i<n;++i){
            if (p & 1){
                  if (!f) f=true;
                  else printf(" ");
                  printf("%d",a[i]);
            }
            p>>=1;
        }
        printf("\n");
        f=false;
        for (int i=0;i<n;++i){
            if (q & 1){
                  if (!f) f=true;
                  else printf(" ");
                  printf("%d",a[i]);
            }
            q>>=1;
        }
        printf("\n");
    }   
}
