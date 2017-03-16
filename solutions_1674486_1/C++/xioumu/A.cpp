
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

const int MAXINT = -1u>>1;
const int maxn = 1007;
struct node{
       int ad, ne;
       }e[100007];
int en = 0, n;
int g[maxn];
void add(int r, int w){
     e[++en].ad = w;
     e[en].ne = g[r];
     g[r] = en;     
}
void init(){
     int i,j,k,r;
     scanf("%d",&n);
     en = 0;
     memset(g, 0, sizeof(g));
     for(int i = 1; i<=n; i++){
             int m,r,w;
             scanf("%d",&m);
             for(int j = 1;j <=m; j++){
                     scanf("%d",&r);
                     add(i, r);
             }
     }
}
int tim[maxn];
void gao(int w, int h){
     tim[w]++;
     if(tim[w] > 1) return;
     //if(h > n + 1) return ;
     for(int p = g[w]; p; p = e[p].ne){
             gao(e[p].ad, h+1);
     }
}
int main() {
	int t;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1; i<=t; i++){
            printf("Case #%d: ",i);
            init();
            int ok = 0, j;
            for(j = 1; j<=n; j++){
                    memset(tim, 0, sizeof(tim));
                    gao(j, 1);
                    for(int k = 1; k <= n; k++)
                            if(tim[k] > 1){
                                       ok = 1;
                                       goto end;
                            }
            }
 end:;
            if(j <= n)
                 printf("Yes\n");
            else printf("No\n");
    }
    //while(1);
    return 0;
}

