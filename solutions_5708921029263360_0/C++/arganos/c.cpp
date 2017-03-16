#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int t, J, P, S, K;

int dp[4][4][4][20];
string sol[4][4][4][20][30];



int sum(int n) {
    int u = 0;
    
    while (n > 0) {
        u += n%2;    
        n >>= 1;
    }
    return u;
}


inline void check(int l) {
    int o[4][4][4];
    int h1[4][4];
    int h2[4][4];
    int h3[4][4];
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) 
                o[i][j][k] = h1[i][j] = h2[i][j] = h3[i][j] = 0;
     
    for (int i = 0; i < J; i++)
        for (int j = 0; j < P; j++)
            for (int k = 0; k < S; k++) {
                int u = k + S*j + S*P*i;
                o[i][j][k] = (l & (1<<(u)));
               if (o[i][j][k]) { 
                h1[i][j]++;
                h2[i][k]++;
                h3[j][k]++;
                }
                

         } 

     for (int v = 1; v <= 2; v++) {
            int ok1 = 1, ok2 = 1, ok3 = 1;
            for (int i = 0; i < J; i++)
                for (int j = 0; j < P; j++)
                    if (h1[i][j] > v)
                        ok1 = 0;    
            for (int i = 0; i < J; i++)
                for (int k = 0; k < S; k++)
                    if (h2[i][k] > v)
                        ok2 = 0;    
            for (int k = 0; k < S; k++)
                for (int j = 0; j < P; j++)
                    if (h3[j][k] > v)
                        ok3 = 0;              
            
        if ((ok1 && ok2 && ok3) && (sum(l) >dp[J][P][S][v])) {
                        dp[J][P][S][v] = sum(l);

                        int cnt = 0;
                         for (int i = 0; i < J; i++)
                            for (int j = 0; j < P; j++)
                                for (int k = 0; k < S; k++) {
                                     int uu = k + S*j + S*P*i;
                                    if ((l & (1<<(uu)))) 
                                        sol[J][P][S][v][cnt++] = to_string(i+1)+" "+to_string(j+1)+" "+to_string(k+1);         
                                }    
                    }   
                }
}

int rec(int l, int pos, int left) {
    if (left == 0 || pos >= S*P*J) {
        check(l);
        return 0;
    }
    for (int i = pos; i < S*P*J; i++) {
        rec(l | (1<<i), i+1, left-1);
    }

    return 0;
}

int main() {
    cin >> t;

    for (int j = 0; j < 4;j++)
            for (int p = 0; p < 4; p++)
                for (int s = 0; s < 4; s++) 
                    for (int k = 0; k < 11; k++) {
                dp[j][p][s][k] = -1;
        } 
    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<": ";
    

        cin >> J >> P >> S >> K;
        
        if (K > 2) {
            cout << J*P*S << endl;
             for (int j = 1; j <= J;j++)
                for (int p = 1; p <= P; p++)
                    for (int s = 1; s <= S; s++) 
                        cout << j << " " <<p << " "<<s << endl;

            continue;
        }

    
        if (dp[J][P][S][K] != -1) {
             cout << dp[J][P][S][K] << endl;

            for (int k = 0; k < dp[J][P][S][K]; k++)
                cout << sol[J][P][S][K][k]<<endl;
            continue;
        }
            

        rec(0, 0, 27);

       /* 
        for (int l = ((1LL<<(J*P*S)))-1; l >= 0; l--) {
            int u = 0;
            for (int z = 1; z <= 2; z++)
                u = min(u, dp[J][P][S][z]);
            if (sum(l) <= u)
                continue;
           if (sum(l) >= 20)
                continue; 
            check(l);        
    
          //  if (check(l) && (sum(lm) < sum(l))) {
           //     lm = l;
           // }
        }
        */
        cout << dp[J][P][S][K] << endl;

        for (int k = 0; k < dp[J][P][S][K]; k++)
            cout << sol[J][P][S][K][k]<<endl;
        
//        cout << endl;
    }

    return 0;
}
