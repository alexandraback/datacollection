#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int T, N, bff[12][12], ans;

int main(void)
{
     freopen("C-small-attempt2.in","r",stdin);
     freopen("C-small-attempt2.out","w",stdout);
     
     cin >> T;
     for (int cases = 1; cases <= T; cases++) {
         cin >> N;
         
         memset(bff, 0, sizeof(bff));
         for (int i = 0; i < N; i++) {
             int temp;
             cin >> temp;
             temp--;
             
             bff[i][temp] = 1;
         }
     
         
         ans = 0;
         for (int mask = 7; mask < (1 << N); mask++) {
             vector<int> circle;
             int sz = 0;
             for (int i = 0; i < N; i++) {
                 if (mask & (1 << i)) {
                    circle.push_back(i);
                    sz++;   
                 }
             }
             
             //pruning
             if (sz == ans)
                 continue;
             
             bool can = false;
             do {
                 //check
                 bool valid = true;
                 for (int i = 0; i < sz; i++) {
                     int left = circle[(i - 1 + sz)%sz];
                     int right = circle[(i + 1)%sz];
                     int now = circle[i];
                     
                     if (bff[now][left] == 0 && bff[now][right] == 0) {
                        valid = false;
                        break;                   
                     }
                 } 
                 
                 if (valid) {
                     can = true;
                     break;           
                 }
             } while (next_permutation(circle.begin(), circle.end()));  
             
             if (can)
                 ans = max(ans, sz);
         }
         
         cout << "Case #" << cases << ": " << ans << endl;
     }
}
