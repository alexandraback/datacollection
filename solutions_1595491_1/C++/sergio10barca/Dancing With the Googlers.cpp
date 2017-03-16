#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 102
#define MOD 1000000007
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;
int tabla[31][5][3];
int len[31];
int P, v[MAX];
int memo[MAX][MAX];

void genera(int n){
    int i, j, k, med = n/3;
    for(i = max(0, med-2); i <= (med+2); i++){
        for(j = i; j <= min((i+2), 10); j++){
            for(k = j; k <= min((i+2), 10); k++)
                if((i+j+k)==n){
                    tabla[n][len[n]][0] = i;
                    tabla[n][len[n]][1] = j; 
                    tabla[n][len[n]][2] = k; 
                    len[n]++;
                }
        }
    }
    return;
}

int rec(int n, int s){
    int a = 0, b = 0;
//    cout << n << " " << s << endl;
    if(memo[n][s] == (-1)){
        if(n == 0 && s == 0)
            return memo[n][s] = 0;
        if((n-1)>=s){
            a = rec(n-1, s);
            if(tabla[v[n-1]][1][2]>=P)
                a++;
        }
        if(n>0 && s>0){
            b = rec(n-1, s-1);
            if(tabla[v[n-1]][0][2]>=P)
                b++;
        }
        memo[n][s] = max(a, b);
    }
    return memo[n][s];
}

int main(){
    int i, j, k, n, T, S;
    for(i = 0; i <= 30; i++){
        len[i] = 0;
        genera(i);
/*      cout << i << endl;
        for(j = 0; j < len[i]; j++){
            for(k = 0; k < 3; k++)
                cout << "\t" << tabla[i][j][k];
            cout << endl;
            if(j == 1 && (tabla[i][j][2]-tabla[i][j][0])>=2)
                cout << "ERROR\n";
            if(j == 0 && (tabla[i][j][2]-tabla[i][j][0])!=2)
                cout << "ERROR\n";
        }//*/
    }
    genera(0);
    genera(1);
    genera(29);
    genera(30);
    cin >> T;
    for(k = 1; k <= T; k++){
        cin >> n >> S >> P;
        for(i = 0; i < n; i++)
            cin >> v[i];
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                memo[i][j] = -1;
        cout << "Case #"<<k<<": " << rec(n, S)<<endl;
    }
    return 0;
}
