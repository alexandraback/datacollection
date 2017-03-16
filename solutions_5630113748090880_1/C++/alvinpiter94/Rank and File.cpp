#include<iostream>
#include<stdio.h>
using namespace std;

int T, occ[2555], N, num;

int main(void)
{
     freopen("B-large.in","r",stdin);
     freopen("B-large.out","w",stdout);
     
     cin >> T;
     for (int cases = 1; cases <= T; cases++) {
         cin >> N;
         
         memset(occ, 0, sizeof(occ));
         for (int j = 1; j <= 2 * N - 1; j++) {
             for (int i = 1; i <= N; i++) {
                 cin >> num;
                 occ[num]++;
             }
         }
         
         cout << "Case #" << cases <<":";
         for (int i = 0; i < 2555; i++) {
             if (occ[i] % 2 == 1) 
                cout << " " << i;
         }
         cout << endl;
     }

}
