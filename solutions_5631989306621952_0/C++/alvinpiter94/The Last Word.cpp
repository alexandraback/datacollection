#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int T, N;
string S, ans;

int main(void)
{
     freopen("A-small-attempt0.in","r",stdin);
     freopen("A-small-attempt0.out","w",stdout);
     
     cin >> T;
     for (int cases = 1; cases <= T; cases++) {
         cin >> S;
         N = S.length();
         
         ans = "";
         for (int mask = 0; mask < (1 << N); mask++) {
             string temp = "";
             for (int i = 0; i < N; i++) {
                 if (mask & (1 << i)) 
                    temp = temp + S[i];
                 else
                    temp = S[i] + temp; 
             }
             ans = max(ans, temp);
         }
         
         cout << "Case #" << cases << ": " << ans << endl;
     }


}
