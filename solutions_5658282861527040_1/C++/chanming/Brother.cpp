#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int A[40], B[40], K[40];
long long dp[40][2][2];
long long base2[40];
long long Ans;

long long work(int dep, int flagA, int flagB){
   // cout << dep << " " << flagA << " " << flagB << endl;
    if (dp[dep][flagA][flagB] != -1)
        return dp[dep][flagA][flagB];
    if (dep > 32) return 0;
    dp[dep][flagA][flagB] = 0;
    int i = dep;
    if (K[i] == 1){
        if (A[i] == 1 || flagA)
            if (B[i] == 1 || flagB)
                dp[dep][flagA][flagB] += work(dep + 1, flagA, flagB);
    }else{
        //1 1
        if (A[i] == 1 || flagA){
            if (B[i] == 1 || flagB){
                long long resA = 0;
                long long resB = 0;
                if (flagA){
                    resA = base2[32 - i];
                }else{
                    for (int j = 32; j > i; --j)
                        resA += base2[32 - j] * A[j];
                    resA++;
                }
                if (flagB){
                    resB = base2[32 - i];
                }else{
                    for (int j = 32; j > i; --j)
                        resB += base2[32 - j] * B[j];
                    resB++;
                }
                dp[dep][flagA][flagB] += resA * resB;
                //cout << dp[dep][flagA][flagB] << endl;
            }
        }
        //1 0
        if (A[i] == 1 || flagA){
            if (B[i] || flagB)
                dp[dep][flagA][flagB] += work(i + 1, flagA, flagB | 1);
            else
                dp[dep][flagA][flagB] += work(i + 1, flagA, flagB);
        }
        //0 1
        if (B[i] == 1 || flagB){
            if (A[i] || flagA)
                dp[dep][flagA][flagB] += work(i + 1, flagA | 1, flagB);
            else
                dp[dep][flagA][flagB] += work(i + 1, flagA, flagB);
        }
        //0 0
        dp[dep][flagA][flagB] += work(i + 1, flagA | A[i], flagB | B[i]);
    }
    return dp[dep][flagA][flagB];
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B.txt", "w", stdout);
    base2[0] = 1;
    for (int i = 1; i <= 32; ++i)
        base2[i] = base2[i - 1] * 2;
    int _;
    scanf("%d", &_);
    for (int __ = 1; __ <= _; ++__){
        printf("Case #%d: ",__);
        long long a, b, k;
        cin >> a >> b >> k;
        k = min(a, k);
        k = min(b, k);
        Ans = a * b;
        a--; b--; k--;
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(K, 0, sizeof(K));
        for (int i = 32; i >= 0; --i){
            A[i] = a % 2;
            a /= 2;
            B[i] = b % 2;
            b /= 2;
            K[i] = k % 2;
            k /= 2;
        }
        /*
        for (int i = 0; i <=32; ++i)
            cout << A[i];
        cout << endl;
        for (int i = 0; i <=32; ++i)
            cout << B[i];
        cout << endl;
        for (int i = 0; i <=32; ++i)
            cout << K[i];
        cout << endl;
        */
        memset(dp, -1, sizeof(dp));
        work(0, 0, 0);
        Ans -= dp[0][0][0];
        cout << Ans << endl;
    }
}
