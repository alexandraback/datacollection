#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int ttt, t;

int n,k,x,b[210],i,j,mask,bits,ok;
int T[210];
int K[210];
int C[210];
int Q[1 << 21][22];
int c[210][210];
int E[1<<21];

int main()
{
    freopen("d1.in","r",stdin);
    freopen("d1.out","w",stdout);    
    cin >> t;
       
    for (ttt = 1; ttt <= t; ttt++){
        printf("Case #%d: ",ttt);
    
        cin >> k >> n;
        memset(b,0,sizeof(b));
        for (i=0;i<k;i++){
            cin >> x;
            b[x]++;
        }
        
        for (i=0;i<n;i++){
            cin >> T[i] >> K[i];
            for (j=0;j<K[i];j++) cin >> c[i][j];
        }
        
        for (mask = 0; mask < (1 << n); mask++){
            E[mask] = 0;
            Q[mask][1] = 1000;
        }
        
        E[0] = 1;
        for (mask = 0; mask < (1 << n); mask++)
            if (E[mask] == 1){
                for (i=1;i<=200;i++)
                    C[i] = b[i];
                for (i=0;i<n;i++)
                    if (mask & (1 << i)){
                       C[T[i]]--;
                       for (j=0;j<K[i];j++)
                           C[c[i][j]]++;
                    }
                    
                bits = 0;
                for (i=0;i<n;i++)
                    if (mask & (1 << i)) bits++;

                for (i=0;i<n;i++)
                    if ((mask & (1 << i)) == 0)
                       if (C[T[i]] > 0){
                          Q[mask][bits+1] = i+1;
                          ok = 0;
                          for (j=1;j<=bits+1;j++)
                              if (Q[mask][j]<Q[mask | (1 << i)][j]) ok = 1; else 
                              if (Q[mask][j]>Q[mask | (1 << i)][j]) break;
                          
                          if (ok)
                             for (j=1;j<=bits+1;j++)
                                 Q[mask | (1 << i)][j] = Q[mask][j];
                          E[mask | (1 << i)] = 1;                          
                       }
                    
            }
            
        if (E[(1 << n)-1] == 0) cout << "IMPOSSIBLE\n"; else {
           for (i=1;i<n;i++)
               cout << Q[(1 << n)-1][i] << " ";
           cout << Q[(1 << n)-1][n] << endl;
        }
    }
    return 0;
}
