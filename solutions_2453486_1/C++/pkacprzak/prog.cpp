#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>
#include <ctime>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
inline void pisz(int n) { printf("%d\n",n); }
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

char board[4][5];
char player[2] = {'X', 'O'};
int cnt_row[4];
int cnt_col[4];
int cnt_diag;
int current_test;

void output(string msg, int mode = 0)
{
    if(mode)
        cout << "Case #" << current_test << ": " << msg << " won\n";
    else
        cout << "Case #" << current_test << ": " << msg << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    for(current_test = 1; current_test <= t; current_test++)
    {
        int dot = 0;
        FOR(i, 4) 
        {
            cin.getline(board[i], 5);
            FOR(j, 4) if(board[i][j] == '.') dot = 1;
        }
        cin.ignore();
        int winner = -1;
        FOR(p, 2)
        {
            memset(cnt_row, 0, 4 * sizeof(int));
            memset(cnt_col, 0, 4 * sizeof(int));
            FOR(i, 4)
            {
                FOR(j, 4)
                {
                    if(board[i][j] == player[p] || board[i][j] == 'T')
                    {
                        cnt_row[i]++;
                        cnt_col[j]++;
                        if(cnt_row[i] == 4 || cnt_col[j] == 4) winner = p;
                    }
                }
            }
            cnt_diag = 0;
            FOR(i, 4) if(board[i][i] == player[p] || board[i][i] == 'T') cnt_diag++;
            if(cnt_diag == 4) winner = p;
            cnt_diag = 0;
            FOR(i, 4) if(board[3 - i][i] == player[p] || board[3 - i][i] == 'T') cnt_diag++;
            if(cnt_diag == 4) winner = p;
        }
        if(winner >= 0) 
        {
            string out;
            out += player[winner];
            output(out, 1);
        }
        else if(dot == 0) output("Draw");
        else output("Game has not completed");
    }
    return 0;
}
