#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define mp(a,b) make_pair((a),(b))
#define eq ==

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

// →↑←↓
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};


const double EPS = 1e-9;

struct State{
    int y,x;
    string jump;
    State(int y,int x,string jump) : y(y),x(x),jump(jump) {};
};

string solve(int X,int Y){
    set<pair<ll,ll> > ALR;
    queue<State> Q;
    Q.push(State(0,0,""));
    string ret = "";
    for(int turn=1;;turn++){
        queue<State> New;
        while(not Q.empty()){
            State s = Q.front();
            Q.pop();
            if(ALR.find(make_pair(s.y,s.x)) != ALR.end()) continue;
            ALR.insert(make_pair(s.y,s.x));
            if(s.y == Y and s.x == X){
                ret = s.jump;
                goto end;
            }
            for(int i=0;i<4;i++){
                string ns = s.jump;
                if(i == 0) ns += 'E';
                if(i == 1) ns += 'S';
                if(i == 2) ns += 'W';
                if(i == 3) ns += 'N';
                New.push(State(s.y+turn*dy[i],s.x+turn*dx[i],ns));
            }
        }
        Q = New;
    }
 end:
    return ret;
}

void go(string s){
    int y=0,x=0;
    for(int i=0;i<s.length();i++){
        int move = i+1;
        if(s[i] == 'E') x += move;
        if(s[i] == 'W') x -= move;
        if(s[i] == 'S') y -= move;
        if(s[i] == 'N') y += move;
    }
    cerr << x << y << endl;
}
int main(){
    int T;
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++){
        int X,Y;
        cin >> X >> Y;
        cout << "Case #" << testcase << ": " << solve(X,Y) << endl;
    }
    return 0;
}
