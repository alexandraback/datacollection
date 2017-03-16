#include <iostream>
#include <cstdio>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOWN(i, a, b) for(int i=a; i>=b; i--)
#define maxn 105

int n, m, A[maxn], B[maxn], test;
long long a[maxn], b[maxn];

int solve(int t)
{
    printf("Case #%d: ", t);
    if ((n==3)&&(A[1]==A[2])) {
                              n=2;
                              a[1]+=a[2];
                              A[2]=A[3];
                              a[2]=a[3];
                              }
    if ((n==3)&&(A[2]==A[3])) {
                              n=2;
                              a[2]+=a[3];
                              }
    if ((n==2)&&(A[1]==A[2])) {
                              n=1;
                              a[1]+=a[2];
                              }
    
    
    if (n==1) {
              long long sum=0;
              FOR(i, 1, m) if (B[i]==A[1]) sum+=b[i];
              cout << min(sum, a[1]) << endl;
              return 0;
              }
    if (n==2) {
              long long res=0;
              FOR(i, 0, m) {
                     long long sum1=0, sum2=0;
                     FOR(j, 1, i) if (B[j]==A[1]) sum1+=b[j];
                     FOR(j, i+1, m) if (B[j]==A[2]) sum2+=b[j];
                     res=max(res, min(sum1, a[1])+min(sum2, a[2]));
                     }
              cout << res << endl;
              return 0;
              }
    if (n==3) {
              
                              long long res=0;
                              FOR(i, 0, m)
                                FOR(j, i+1, m) {
                                       long long sum1=0, sum2=0, sum3=0;
                                       FOR(k, 1, i) if (B[k]==A[1]) sum1+=b[k];
                                       FOR(k, i+1, j) if (B[k]==A[2]) sum2+=b[k];
                                       FOR(k, j+1, m) if (B[k]==A[3]) sum3+=b[k];
                                       res=max(res, min(sum1, a[1])+min(sum2, a[2])+min(sum3, a[3]));
                                       }
              if (A[1]!=A[3]) {
                              cout << res << endl;
                              return 0;
                              }        
              long long res2=0;
              a[1]+=a[3];
              long long sum=0;
              FOR(i, 1, m) if (B[i]==A[1]) sum+=b[i];
              res2=min(a[1], sum);
              cout << max(res, res2) << endl;       
              }
}

int main()
{
    freopen("test3.inp", "r", stdin);
    freopen("test3.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
           cin >> n >> m;
           FOR(i, 1, n) scanf("%I64d%d", &a[i], &A[i]);
           FOR(i, 1, m) scanf("%I64d%d", &b[i], &B[i]);
           solve(t);
           }
    return 0;
}
