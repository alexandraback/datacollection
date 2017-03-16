#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
ofstream bug;
const bool DEBUG = true; 
const int MAXN = 100+1;
const char PROBLEM[] = {"3"}; 
char *PROB;

int tests, test; 
long long i, j, k, r, x, y, m, n, ans; 
int S, P; 
long long a[MAXN], b[MAXN], A[MAXN], B[MAXN];
long long sumA[MAXN][MAXN], sumB[MAXN][MAXN]; 
long long f[MAXN][MAXN];
string s; 

template <class T> void debug(T t){ if (DEBUG) bug << "[" << t << "]"; }
template <class T> void debug(T t, T t2){ if (DEBUG) bug << "[" << t << "," << t2 << "]"; }
template <class T> void debug(T t, T t2, T t3){ if (DEBUG) bug << "[" << t << "," << t2 << "," << t3 << "]"; }
bool sort_desc(int a, int b) { return  a > b; }
long long update(long long &a, long long b){
    if (b > a) a = b;     
}

int main(){
if (DEBUG) {
    PROB = new char[10];
    strcpy(PROB, PROBLEM); freopen(strcat(PROB, ".in"), "r", stdin); 
    strcpy(PROB, PROBLEM); freopen(strcat(PROB, ".out"), "w", stdout);
    strcpy(PROB, PROBLEM); bug.open(strcat(PROB, ".txt")); 
}
    
    scanf("%d", &tests);
    
for (test = 1; test <= tests; ++test){
    if (DEBUG) bug << endl << "Case #" << test << ": " << endl; 
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i ) {
        scanf("%ld%ld", &a[i], &A[i]); 
    }
    
     memset(sumA, sizeof(sumA), 0); 
      memset(sumB, sizeof(sumB), 0); 
      
    for (int i = 1; i <= n; ++i )
    for (int j = 1; j <= 100; ++j) {
        sumA[i][j] = sumA[i-1][j]; 
        if (A[i] == j)
            sumA[i][j] += a[i]; 
    }
    
    for (int j = 1; j <= m; ++j ) {
        scanf("%ld%ld", &b[j], &B[j]);     
    }
    for (int i = 1; i <= m; ++i )
    for (int j = 1; j <= 100; ++j) {
        sumB[i][j] = sumB[i-1][j]; 
        if (B[i] == j)
            sumB[i][j] += b[i]; 
    }
    
    ans = 0; 
    memset(f, sizeof(f), 0); 
    
    for (int i = 1; i <= n; ++i ){
        for (int j = 1; j <= m; ++j ){
           
            f[i][j] = max(f[i-1][j], f[i][j-1]);    
            if (A[i] == B[j]) {
                int ty = A[i]; 
                //f[i][j] = max(f[i][j], f[i-1][j-1] + min(a[i], b[j]));   
                
                for (int ii = 0; ii < i; ++ii){
                    for (int jj = 0; jj < j; ++jj){
                        f[i][j] = max(f[i][j], f[ii][jj] + min(sumA[i][ty] - sumA[ii][ty], sumB[j][ty] - sumB[jj][ty]));   
                    }
                }
            }
            if (f[i][j] > ans) ans = f[i][j];        
        }    
    }
     
    printf("Case #%ld: %ld\n", test, ans); 
    
}   
     
    return 0;  
}
