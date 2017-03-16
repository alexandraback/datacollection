#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define FOR(i,s,e) for(int i=(s); i<(e); ++(i))
#define FORE(i,s,e) for(int i=(s); i<=(e); ++(i))
#define fs first
#define se second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
int gcd(int a,int b){if(b==0)return a; if(b>a) return gcd(b,a); return gcd(b,a%b);}

const int X = -1;
const int O = 1;
const int NONE = 0;
const string XWON = "X won";
const string DRAW = "Draw";
const string OWON = "O won";
const string NOTC = "Game has not completed";

string in[4];

int rowWin(int rowIdx)
{
    int result = NONE;
    char prev = in[rowIdx][0];
    if(prev=='.')return NONE;
    int cnt = 1;
    FOR(i,1,4){
        char token = in[rowIdx][i];
        if(token != '.')
        {
            if(token == prev || token == 'T' || prev == 'T') {
                if(prev == 'T') prev = token;
                cnt++;
            }
            else break;
        }
        else break;
    }
    if(cnt == 4) return (prev=='X')?X:O;
    return NONE;
}

int colWin(int colIdx)
{
    int result = NONE;
    char prev = in[0][colIdx];
    if(prev=='.')return NONE;
    int cnt = 1;
    FOR(i,1,4){
        char token = in[i][colIdx];
        if(token != '.')
        {
            if(token == prev || token == 'T' || prev == 'T') {
                if(prev == 'T') prev = token;
                cnt++;
            }
            else break;
        }
        else break;
    }
    if(cnt == 4) return (prev=='X')?X:O;
    return NONE;
}

int diagLeftWin()
{
    int result = NONE;
    char prev = in[0][0];
    if(prev=='.')return NONE;
    int cnt = 1;
    FOR(i,1,4){
        char token = in[i][i];
        if(token != '.')
        {
            if(token == prev || token == 'T' || prev == 'T') {
                if(prev == 'T') prev = token;
                cnt++;
            }
            else break;
        }
        else break;
    }
    if(cnt == 4) return (prev=='X')?X:O;
    return NONE;
}

int diagRightWin()
{
    int result = NONE;
    char prev = in[3][0];
    if(prev=='.')return NONE;
    int cnt = 1;
    FOR(i,1,4){
        char token = in[3-i][i];
        if(token != '.')
        {
            if(token == prev || token == 'T' || prev == 'T') {
                if(prev == 'T') prev = token;
                cnt++;
            }
            else break;
        }
        else break;
    }
    if(cnt == 4) return (prev=='X')?X:O;
    return NONE;
}

int solve()
{
    FOR(i,0,4) cin >> in[i];
    int winner = 0;
    FOR(i,0,4) {
        winner = rowWin(i);
        if(winner) break;
    }
    if(!winner) FOR(i,0,4) {
        winner = colWin(i);
        if(winner) break;
    }
    if(!winner) winner = diagLeftWin();
    if(!winner) winner = diagRightWin();

    if(!winner) {
        bool isCompleted = true;
        FOR(i,0,4) {
            FOR(j,0,4) {
                if(in[i][j]=='.') {
                    isCompleted = false;
                    break;
                }
            }
            if(!isCompleted) break;
        }
        if(!isCompleted) cout << NOTC << endl;
        else cout << DRAW << endl;
    }
    else
        cout << ((winner==X)?XWON:OWON) << endl;
	return 0;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int test;
	scanf("%d",&test);
	for(int i = 0; i < test; ++i)
	{
	    printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
