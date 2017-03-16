#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
char a[100][100],b[100][100];
int m,n,k;
bool isImpossible = false;
void solve() {
    FOR(i,1,m) FOR(j,1,n) a[i][j] = '.';
    if (m == 1) { //MAJOR CASE 1
        a[1][1] = 'c';
        FOR(i,n-k+1,n) a[1][i] = '*';
        return;
    }
    if (m == 2) { //MAJOR CASE 2
        if (k % 2 == 0) 
        {
            int remain = n - k / 2;
            if (remain < 2) {
                isImpossible = true;
            } else {
                a[1][1] = 'c';
                FOR(i,1,m)
                FOR(j,n-k/2+1,n) a[i][j] = '*';
            }
        } 
        else {
            if (k != m*n-1) {
                isImpossible = true;
            } else {
                FOR(i,1,m) FOR(j,1,n) a[i][j] = '*';
                a[1][1] = 'c';
            }
        }
        return;
    }
    
    isImpossible = true;
    FOR(fullRow,0,m-2) {
        int k_save = k - n * fullRow;
        int nRow = m - fullRow;
        if (k_save < 0) return;
        FOR(fullcol,0,n-2) {
            int k_left = k_save - fullcol * nRow;
            if (k_left < 0) break;
            int col = fullcol+1, canPut = nRow-2;
//            cout << "START " << fullRow << " " << fullcol << " " << k_left << " " << canPut << endl;
//            cout << "nrow = " << nRow << endl;
            while (col <= n-2 && canPut > 0)
            {
              //  cout << col << " " << canPut << endl;
                if (k_left <= canPut) {
                    isImpossible = false;
                    FOR(i,1,m) FOR(j,1,n) a[i][j] = '.';
                    FOR(i,1,fullRow) 
                    FOR(j,1,n) a[i][j] = '*';
                    
                    FOR(i,1,m)
                    FOR(j,1,fullcol) a[i][j] = '*';
                    int canFill = nRow - 2;
                    FOR(j,fullcol+1,col-1) {
                        FOR(i,fullRow+1,fullRow+canFill) a[i][j] = '*';
                        canFill --;
                    }
                    FOR(i,fullRow+1,fullRow+k_left) a[i][col] = '*';
                    a[m][n] = 'c';
                    return;
                }
                col++;
                k_left -= canPut;
                canPut -- ;
            }
        }
    }
}
bool handle_special_case() {
    FOR(i,2,m) 
    FOR(j,2,n)
    if (i * j == m*n-k) {
        FOR(i1,1,m) FOR(j1,1,n) a[i1][j1] = '*';
        FOR(i1,1,i) FOR(j1,1,j) a[i1][j1] = '.';
        a[1][1] = 'c';
        return true;
    }
    if (k == m*n-1) {
        FOR(i,1,m) FOR(j,1,n) a[i][j] = '*';
        a[1][1] = 'c';
        return true;
    }
    return false;
}
int main() 
{
    freopen("C-large.in","r",stdin);
    freopen("C.out","w",stdout);
    int ntest;
    cin >> ntest;
    int T = 0;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ":" << endl;
        cin >> m >> n >> k;
        bool isSwap = false;
        isImpossible = false;
        if (m > n) {
            swap(m,n);
            isSwap = true;
        }
        if (!handle_special_case()) {
            solve();
            if (isImpossible) {
                isImpossible = false;
                swap(m,n);
                isSwap = !isSwap;
                solve();
            }
        }
        if (isSwap) {
            FOR(i,1,m)
            FOR(j,1,n) b[j][i] = a[i][j];
            
            swap(m,n);
            FOR(i,1,m) FOR(j,1,n) a[i][j] = b[i][j];
        }
        if (isImpossible) cout << "Impossible" << endl;
        else {
            T++;
            FOR(i,1,m) {
                FOR(j,1,n) cout << a[i][j];
                cout << endl;
            }
        }
    }
    //cout << "nImpossible = " << ntest - T << endl;
    //cout << "sol " << T << endl;
    return 0;
}
