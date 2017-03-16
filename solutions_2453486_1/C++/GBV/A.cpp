#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

char A[4][4];

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, k;
    bool hasX = false, hasO = false, ch[8], hasP = false;
    for(i = 0; i < 4; ++i)
        for(j = 0; j < 4; ++j) cin >> A[i][j];
    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 8; ++j) ch[j] = true;
        for(j = 0; j < 4; ++j)
        {
            if(A[i][j] == '.') hasP = true;
            if(A[i][j] != 'X' && A[i][j] != 'T') ch[0] = false; // !X has the row
            if(A[j][i] != 'X' && A[j][i] != 'T') ch[1] = false; // !X has the column
            if(A[i][j] != 'O' && A[i][j] != 'T') ch[2] = false; // !O has the row
            if(A[j][i] != 'O' && A[j][i] != 'T') ch[3] = false; // !O has the column
            if(A[j][j] != 'X' && A[j][j] != 'T') ch[4] = false; // !X has main diag
            if(A[j][3 - j] != 'X' && A[j][3 - j] != 'T') ch[5] = false; // !X has sec diag
            if(A[j][j] != 'O' && A[j][j] != 'T') ch[6] = false; // !O has main diag
            if(A[j][3 - j] != 'O' && A[j][3 - j] != 'T') ch[7] = false; // !O has sec diag
        }
        hasX |= (ch[0] || ch[1] || ch[4] || ch[5]);
        hasO |= (ch[2] || ch[3] || ch[6] || ch[7]);
    }
    if(hasX) printf("X won\n");
    else if(hasO) printf("O won\n");
    else if(hasP) printf("Game has not completed\n");
    else printf("Draw\n");
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
