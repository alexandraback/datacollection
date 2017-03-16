#include <iostream>

using namespace std;

#define max 1010
#define REP(i,n) for(int i=0; i<n; i++)

int main() {
    int numTest;
    cin >> numTest;
    //cout << numTest << endl;
    int test = 0;
    while (test++ < numTest) {
          int N;
          cin >> N;
          //cout << N << endl;
                    
          int D[N+1], C[N+1][N+1], T[N+1][N+1];
          
          REP(i,N) {
              cin >> C[i+1][0];
              //cout << C[i+1][0] << endl;
              REP(j,C[i+1][0]) {
                   cin >> C[i+1][j+1];
                   //cout << C[i+1][j+1] << " ";
              }
              //cout << endl;
              
          }
          
          bool ans = true;
          REP(i,N) 
          {
              REP(j,N+1) D[j] = 0;
              int l = 0, r = 0; 
              int Q[N]; Q[0] = i+1;
              while (l <= r) {
                   int s = Q[l];
                   REP(j,C[s][0]) {
                        int t = C[s][j+1];
                        if (D[t] == 1) ans = false;
                        if (!ans) break;
                        D[t] = 1;   
                        Q[++r] = t;       
                   }
                   l++;
                   if (!ans) break;                   
              }     
              if (!ans) break;              
          }
          
          if ( !ans ) cout << "Case #" << test <<": Yes" << endl;
          else cout << "Case #" << test <<": No" << endl;
    }
    //    system( "pause");
    return 0;
}
