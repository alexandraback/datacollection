//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
// Verdict: 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

char a[10][10];
char X[10][10];
char O[10][10];
int n;

int main()
{
    
    read(n);
    fr(t,1,n)
    {
        printf("Case #%d: ",t);
        
        rep(i,4) scanf(" %s ",&a[i]);
        
        int ans = 0;
        
        rep(i,4) rep(j,4)
        {
            if(a[i][j] == 'T')
            {
                X[i][j] = 'X';
                O[i][j] = 'O';
                continue;
            }
            if(a[i][j] == '.') ans = -1;
            X[i][j] = O[i][j] = a[i][j];
        }
        
        rep(k,4)
        {
            if(X[0][k] == 'X' && X[0][k] == X[1][k] && X[1][k] == X[2][k] && X[2][k] == X[3][k])
            {
                ans = 1;
                break;
            }
            
            if(X[k][0] == 'X' && X[k][0] == X[k][1] && X[k][1] == X[k][2] && X[k][2] == X[k][3])
            {
                ans = 1;
                break;
            }
            
            if(O[0][k] == 'O' && O[0][k] == O[1][k] && O[1][k] == O[2][k] && O[2][k] == O[3][k])
            {
                ans = 2;
                break;
            }
            
            if(O[k][0] == 'O' && O[k][0] == O[k][1] && O[k][1] == O[k][2] && O[k][2] == O[k][3])
            {
                ans = 2;
                break;
            }
        }
        
        if(X[0][0] == 'X' && X[0][0] == X[1][1] && X[1][1] == X[2][2] && X[2][2] == X[3][3])
            ans = 1;
        else if(X[0][3] == 'X' && X[0][3] == X[1][2] && X[1][2] == X[2][1] && X[2][1] == X[3][0])
            ans = 1;
        else if(O[0][0] == 'O' && O[0][0] == O[1][1] && O[1][1] == O[2][2] && O[2][2] == O[3][3])
            ans = 2;
        else if(O[0][3] == 'O' && O[0][3] == O[1][2] && O[1][2] == O[2][1] && O[2][1] == O[3][0])
            ans = 2;
        
        if(ans == 1) puts("X won");
        else if(ans == 2) puts("O won");
        else if(ans == -1) puts("Game has not completed");
        else puts("Draw");
        
    }

    return 0;
}