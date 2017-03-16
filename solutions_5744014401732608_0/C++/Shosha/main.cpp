#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 2000000000

//printf("Case #%d:", z);
int main () {
    FILE* ifile = freopen("B-small-attempt2.in", "r", stdin);
    FILE* ofile = freopen ("ofile.txt", "w", stdout);
    int t;
    cin >> t;
    for (int z=1; z<=t; z++){
        int b, m;
        cin >> b >> m;
        printf("Case #%d: ", z);
        if (m > 1<<(b-2)){
            printf("IMPOSSIBLE");
            cout << endl;
        }
        else {
            int x = 1;
            int A[b+1][b+1];
            for (int i=0; i<=b; i++){
                for (int j=0; j<=b; j++){
                    A[i][j] = 0;
                }
            }
            int it = 0;
            while (x <= m){
                x = x<<1;
                it ++;
            }
            x = x >> 1;
            for (int i=1; i<=it; i++){
                for (int j=i+1; j<=it; j++){
                    A[i][j] = 1;
                }
                A[i][b] = 1;
            }
            m = m-x;
            if (m > 0){
                A[it+1][b] = 1;
            }
            int k = 1;
            while (m>0){
                k++;
                if (m%2 == 1){
                    A[k][it+1] =1;
                }
                m = m >> 1;
            }
            printf("POSSIBLE");
            printf("\n");
            for (int i=1; i<=b; i++){
                for (int j=1; j<=b; j++){
                    cout << A[i][j];
                }
                cout << endl;
            }
        }
        
    }
    
    return 0;
}
