#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int K = 200;
const int M = 105;

int wys[2*K+5],z,i,j,k,wys2[2*K+5],day0,numAt,w,e,s,dday,dp,ds,N,res,d,kol[M],day[M],west[M],east[M],strength[M],q,ok;

bool cmp (int a, int b) {
     return day[a] < day[b];
}

int main() {
scanf("%d",&z);
for (q=1;q<=z;q++) {
    for (i=0;i<2*K;i++) wys[i]=0; 
    d=0;
    res=0;
    scanf ("%d",&N);
    for (i=0;i<N;i++) {
        scanf("%d %d %d %d %d %d %d %d",&day0, &numAt, &w, &e, &s, &dday, &dp, &ds);
        w+=K;
        e+=K;
        while (numAt--) {
            kol[d]=d;
            day[d] = day0;
            west[d]=w;
            east[d]=e;
            strength[d] = s;
            day0+=dday;
            w+=dp;
            e+=dp;
            s+=ds;
            d++;
        }
    }
    sort(kol,kol+d,cmp);
    //printf("%d\n",d);
    i=0;
    while (i<d) {
          j = i;
          for (k=0;k<2*K;k++) wys2[k]=wys[k]; 
          while (j < d && day[kol[j]] == day[kol[i]]) {
                w = kol[j];
                ok = 0;
                for (k=west[w];k<east[w];k++) if (wys[k] < strength[w]) {
                    ok = 1;
                    wys2[k] = max(wys2[k],strength[w]);
                }
                if (ok) res++;
                j++;
          }
          for (k=0;k<2*K;k++) wys[k]=wys2[k]; 
          i=j;
    }
    
    printf("Case #%d: %d\n",q,res);
}
return 0;
}
