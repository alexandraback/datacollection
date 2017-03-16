#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int tc, i, j, k, l, m;
int n, ns, np, a[100], b[3];  
int ans;

bool yes, surp;
 
inline int abs(int x){
    if (x < 0) return -1*x;
    return x;
}

inline int max(int a, int b){
    if (a >= b) return a;
    return b;
}

int main(void){
    freopen("dancing.in", "r", stdin);
    freopen("dancing.out", "w", stdout);
    
    scanf("%d\n", &tc);
    
    for (i = 1; i <= tc; i++){        
        scanf("%d %d %d", &n, &ns, &np);
        
        ans = 0;
        for (j = 0; j < n; j++){
            scanf("%d", &a[j]);
            
            yes = 0; surp = 1;
            for (k = 0; k <= 10 && !(yes && !surp); k++)
                for (l = 0; l <= 10 && !(yes && !surp); l++){
                    if (k+l > a[j]) break;
                    
                    m = a[j]-k-l;
                    
                    if (max(max(k,m),l) >= np){
                      if (abs(k-m) <= 1 && abs(l-m) <= 1 && abs(k-l) <= 1){
                       yes = 1;
                       surp = 0;
                      }
                    
                      if (abs(k-m) <= 2 && abs(l-m)<= 2 && abs(k-l) <= 2){
                       yes = 1;
                      }
                    }
                }
                
            if (yes && (!surp)){
               ans++;
            } else
            if (yes && surp && (ns > 0)){
               ns--;
               ans++;
            }
        }
            
        printf("Case #%d: %d\n", i, ans);
    }    
    
    fclose(stdin);
    fclose(stdout);
    return 0;   
}
    
