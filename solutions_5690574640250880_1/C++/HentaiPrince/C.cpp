#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define N 1000005
#define M 25
#define Mod 1000000007
#define INF 2000000007
typedef long long LL;
int n , m , p;
char a[55][55];
int cases = 0;
void Solve(){
     int i , j , k , l;
     cin >> n >> m >> p;
     for (i=1;i<=n;++i)
         for (j=1;j<=m;++j) a[i][j] = '*';
     p = n*m - p;
     printf("Case #%d:\n",++cases);
     if (n == 1){
           printf("c");
           for (i=1;i<p;++i) printf(".");
           for (i=1;i<=m-p;++i) printf("*");
           puts("");
           return;
     } else
     if (m == 1){
           printf("c\n");
           for (i=1;i<p;++i) printf(".\n");
           for (i=1;i<=n-p;++i) printf("*\n");
           return;
     } else 
     if (p == 1){
           printf("c");
           for (i=1;i<m;++i) printf("*"); puts("");
           for (i=1;i<n;++i){
               for (j=1;j<=m;++j) printf("*");
               puts("");
           }
           return;
     } else 
     if (p == n*m){
           printf("c");
           for (i=1;i<m;++i) printf("."); puts("");
           for (i=1;i<n;++i){
               for (j=1;j<=m;++j) printf(".");
               puts("");
           }
           return;
     } else {
            for (i=2;i<=n;++i)
                for (j=2;j<=m;++j){
                    k = p - i*j;
                    if (((k < i && j != m) || (k < j && i != n) || (i != n && j != m && k <= i+j)) && k != 1 && k >= 0){
                           if (k < i && j != m){
                                 for (int ii=1;ii<=i;++ii)
                                     for (int jj=1;jj<=j;++jj) a[ii][jj] = '.';
                                 for (int ii=1;ii<=k;++ii) a[ii][j+1] = '.';
                                 a[1][1] = 'c';
                                 for (int ii=1;ii<=n;++ii){
                                     for (int jj=1;jj<=m;++jj) printf("%c",a[ii][jj]);
                                     puts("");
                                 }
                                 return;
                           }
                           if (k < j && i != n){
                                 for (int ii=1;ii<=i;++ii)
                                     for (int jj=1;jj<=j;++jj) a[ii][jj] = '.';
                                 for (int ii=1;ii<=k;++ii) a[i+1][ii] = '.';
                                 a[1][1] = 'c';
                                 for (int ii=1;ii<=n;++ii){
                                     for (int jj=1;jj<=m;++jj) printf("%c",a[ii][jj]);
                                     puts("");
                                 }
                                 return;
                           }
                           if (k <= i+j && i != n && j != m){
                                 int tt = -1 , kk;
                                 for (kk=0;kk<=i;++kk)
                                     if (kk != 1 && k-kk != 1 && k - kk <= j && k - kk >= 0){
                                            tt = k - kk;
                                            break;
                                     }
                                 if (tt == -1) continue;
                                 for (int ii=1;ii<=i;++ii)
                                     for (int jj=1;jj<=j;++jj) a[ii][jj] = '.';
                                 for (int ii=1;ii<=tt;++ii) a[i+1][ii] = '.';
                                 for (int ii=1;ii<=kk;++ii) a[ii][j+1] = '.';
                                 a[1][1] = 'c';
                                 for (int ii=1;ii<=n;++ii){
                                     for (int jj=1;jj<=m;++jj) printf("%c",a[ii][jj]);
                                     puts("");
                                 }
                                 return;
                           }
                    }
                }
     }
     puts("Impossible");
}

int main(){
    freopen("C-large.in","r",stdin);
    freopen("2.txt","w",stdout);
    int test;
    cin >> test;
    while (test--) Solve();
    return 0;
}
