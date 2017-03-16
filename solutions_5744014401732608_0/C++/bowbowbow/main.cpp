#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;
#define FOR(i,n) for(int i=1;i<=n;i++)
#define MAXN 10
int N, M, flag;
int graph[MAXN][MAXN];

int main() {
    freopen("/Users/clsrn1581/Desktop/codejam/B/B-small-attempt6.in", "r", stdin);
    freopen("/Users/clsrn1581/Desktop/codejam/B/B-small-attempt6.out", "w", stdout);
    
    int tn; cin >> tn;
    FOR(t,tn) {
        flag = false;
        cin >> N >> M;
        
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j<= N ; j++){
                graph[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= N-2 ; i++){
            for(int j = i+1; j<= N-1 ; j++){
                graph[i][j] = 1;
            }
        }
        
        printf("Case #%d: ", t);
        if(M > pow(2, N-2) ){
            cout << "IMPOSSIBLE" << endl;
        }else if( M == pow(2, N-2)){
            cout << "POSSIBLE" << endl;
            for(int i = 1; i <= N-1 ; i++){
                graph[i][N] = 1;
            }
            for(int i = 1; i <= N ; i++){
                for(int j =1 ; j<= N ; j++){
                    cout << graph[i][j];
                }
                cout << endl;
            }
        }else{
            cout << "POSSIBLE" << endl;
            graph[1][N] = 1;
            M--;
            for(int i = 2 ; i<= N-1 ; i++){
                graph[i][N] = M%2;
                M /= 2;
            }
            for(int i = 1; i <= N ; i++){
                for(int j =1 ; j<= N ; j++){
                    cout << graph[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
