#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const int INF=1000000000;
typedef pair<int,int> Point;
#define x first
#define y second

string str(const string& s) { return s; }

string str(int x) {
    ostringstream ss;
    ss<<x;
    return ss.str();
}

template<typename T>
string str(const T& v) {
    ostringstream ss;
    ss<<"[";
    FOREACH(x,v) ss<<str(*x)<<",";
    ss<<"]";
    return ss.str();
}

#define valid(a,b) a>=0 && a<R && b>=0 && b<C
int R, C, M;

const int dr[] = {-1,-1,+1,+1, 0, 0,-1,+1};
const int dc[] = {-1,+1,-1,+1,-1,+1, 0, 0};
char board[5][5];
bool visited[5][5];

void transform(int mask) {
    int k=0;
    REP(r, R) REP(c, C) board[r][c] = mask&(1<<k++) ? '*' : '0';
    

    REP(r,R) REP(c,C) if(board[r][c]=='0') REP(dir,8) {
        int rr=r+dr[dir], cc=c+dc[dir];
        if(valid(rr,cc) && board[rr][cc]=='*')
            board[r][c]++;    
    }
    
}

int expand(int r, int c) {
    int res = 1;
    visited[r][c]=true;
    if(board[r][c]=='0') REP(dir,8) {
        int rr=r+dr[dir], cc=c+dc[dir];
        if(valid(rr,cc) && !visited[rr][cc] && board[rr][cc]!='*')
            res += expand(rr,cc);
    }
    return res;
}

bool solvable(int mask, pair<int,int>& solution)
{
    transform(mask);

    const int numBlanks = R*C-M;
    REP(r,R) REP(c,C) 
        if(board[r][c]!='*') { 
            //cerr<<"try "<<r<<","<<c<<endl;
            memset(visited,0,sizeof board);
            if(expand(r,c)==numBlanks) {
                solution.first=r;
                solution.second=c;
                
                return true;
            }
        }

    return false;
}




int main() 
{
    ios_base::sync_with_stdio(false);

    int T; cin>>T;
    REP(_t,T) {
        cin>>R>>C>>M;
        int top=1<<(R*C);
        pair<int,int> sol(-1,-1);
        REP(mask, top)
            if(__builtin_popcount(mask)==M && solvable(mask,sol)) break;

        cout<<"Case #"<<_t+1<<":"<<endl;
        if(sol.first==-1) {
            cout<<"Impossible"<<endl;

        }       
        else {
            REP(r,R) {
                REP(c,C) 
                    if(r==sol.first && c==sol.second)
                        cout<<'c';
                    else if(board[r][c]=='*')
                        cout<<'*';
                    else 
                        cout<<'.';
                cout<<endl;
            }
        }
    }    
}