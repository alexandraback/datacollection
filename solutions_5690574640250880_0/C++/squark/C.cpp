#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

char s[100][100];

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i0 = 1;
    int T;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        int i, j;
        int n, m, q;
        bool imp = false;
        scanf("%d%d%d", &n, &m, &q);
        q = n*m-q;
        
        if(q == 1){
            memset(s, '*', sizeof s);
            s[0][0] = 'c';
        }
        else if(n == 1 || m == 1){
            memset(s, '.', sizeof s);
            s[n-1][m-1] = 'c';
            for(i = 0; i < n*m-q; i++)
                s[0][i] = s[i][0] = '*';
        }
        else if(q < 4){
            imp = true;
        }
        else if((n == 2 || m == 2) && q%2 == 1){
            imp = true;
        }
        else if(q%2 == 1 && q < 9){
            imp = true;
        }
        else{
            memset(s, '*', sizeof s);
            for(i = 0; i < 2; i++)
                for(j = 0; j < 2; j++)
                    s[i][j] = '.';
            s[0][0] = 'c';
            q -= 4;
            i = j = 2;
            while(q >= 2 && (i < n || j < m)){
                if(j != 2 && i < n){
                    s[i][0] = s[i][1] = '.';
                    i++;
                    q -= 2;
                }
                else{
                    s[0][j] = s[1][j] = '.';
                    j++;
                    q -= 2;
                }
            }
            for(i = 2; i < n; i++)
                for(j = 2; j < m; j++)
                    if(q > 0){
                        q--;
                        s[i][j] = '.';
                    }
        }
        
        
        printf("Case #%d:\n", i0);
        if(imp)
            puts("Impossible");
        else{
            for(i = 0; i < n; i++){
                s[i][m] = '\0';
                puts(s[i]);
            }
        }
    }
    return 0;
}
