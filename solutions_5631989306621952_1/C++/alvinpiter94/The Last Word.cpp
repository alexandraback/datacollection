#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int T, N;
string S, ans;

int main(void)
{
     freopen("A-large.in","r",stdin);
     freopen("A-large.out","w",stdout);
     
     cin >> T;
     for (int cases = 1; cases <= T; cases++) {
         cin >> S;
         N = S.length();
         
         ans = "";
         for (int i = 0; i < S.length(); i++) {
             string depan = S[i] + ans;
             string belakang = ans + S[i];
             
             if (depan > belakang)
                ans = depan;
             else
                ans = belakang; 
         }
         
         cout << "Case #" << cases << ": " << ans << endl;
     }


}
