#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define eps 1e-6
int T, N, M;
struct Node {
       int id;
       long long num;
       void input() {
            cin>>num>>id;
       } 
}A[110],B[110];
long long dp[110][110];
long long sumb[110][110],ans;
int a[4];
void DFS(int n, int now) {
     if (n == N) {
        a[n] = M;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += min(A[i].num,sumb[A[i].id][a[i + 1] - 1] - sumb[A[i].id][a[i] - 1]);
        }
        //cout <<ans<<endl;
        ans = max(ans, sum);
        return;
     }
     for (int i = now; i <= M; i++) {
         a[n] = i;
         DFS(n + 1, i);
     }
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
       scanf("%d%d",&N, &M);
       memset(sumb, 0, sizeof(sumb));
       ans = 0;
       for (int i = 0; i < N; i++) {
           A[i].input();
       }
       for (int i = 1; i <= M; i++) {
           B[i].input();
           for (int j = 1; j <= 100; j++) {
               if (j == B[i].id) sumb[j][i] = sumb[j][i - 1] + B[i].num;
               else              sumb[j][i] = sumb[j][i - 1];
           }
       }
       DFS(0,1);
       cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}
