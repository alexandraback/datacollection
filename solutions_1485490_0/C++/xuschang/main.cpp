#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MAXN = 110;

int n, m;
pair <long long, long long> A[MAXN];
pair <long long, long long> B[MAXN];
long long dp[MAXN][MAXN];

int main(){
freopen("in.in","r",stdin);
freopen("out.txt","w",stdout);
int T;
scanf("%d", &T);
for(int t = 1; t <= T; t ++){
scanf("%d%d", &n, &m);
for(int i = 1; i <= n; i ++){
scanf("%I64d%I64d", &A[i].second, &A[i].first);
}

for(int i = 1; i <= m; i ++){
scanf("%I64d%I64d", &B[i].second, &B[i].first);
}

memset(dp, 0, sizeof(dp));

for(int i = 1; i <= n; i ++){
for(int j = 1; j <= m; j ++){
long long temp = 0;
if(A[i].first == B[j].first){
temp = max(temp, dp[i - 1][j - 1] + min(A[i].second, B[j].second));

for(int i2 = i; i2 >= 1; i2 --){
for(int j2 = j; j2 >= 1; j2 --){
long long temp_A = A[i].second;
long long temp_B = B[j].second;
for(int k = i2; k < i; k ++){
if(A[i].first == A[k].first){
temp_A += A[k].second;
}
}
for(int k = j2; k < j; k ++){
if(B[j].first == B[k].first){
temp_B += B[k].second;
}
}
temp = max(temp, dp[i2 - 1][j2 - 1] + min(temp_A, temp_B));
}
}
}
temp = max(temp, dp[i - 1][j]);
temp = max(temp, dp[i][j - 1]);
dp[i][j] = temp;
}
}

printf("Case #%d: %I64d\n", t, dp[n][m]);
}
}
