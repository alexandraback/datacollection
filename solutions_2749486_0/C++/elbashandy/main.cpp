/* 
 * File:   main.cpp
 * Author: absho
 *
 * Created on May 12, 2013, 11:44 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
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
#include <numeric>
 
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
 
#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)
 
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define trailingZeros(S) __builtin_ctz(S)
#define leadingZeros(S) __builtin_clz(S)
 
using namespace std;

/*
 * 
 */

map< pair<int, int>, int > m;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

struct node{
    int x; 
    int y;
    string dir;
    int steps;
    node(int i, int j, string s, int st){
        x = i;
        y = j;
        dir = s;
        steps = st;
    }
    
};

string bfs(int x, int y){
    queue<node> q;
    
    q.push(node(0, 0, "", 1));
    
    while(!q.empty()){
        node f = q.front();
        q.pop();
        
        if(m[make_pair(f.x, f.y)])
            continue;
        
        m[make_pair(f.x, f.y)] = 1;
        
        if(f.x == x && f.y == y) return f.dir;
        
        if(f.steps > 500) break;
        
        q.push(node(f.x + (dx[0] * f.steps), f.y + (dy[0] * f.steps), f.dir + 'E', f.steps + 1));
        q.push(node(f.x + (dx[1] * f.steps), f.y + (dy[1] * f.steps), f.dir + 'N', f.steps + 1));
        q.push(node(f.x + (dx[2] * f.steps), f.y + (dy[2] * f.steps), f.dir + 'W', f.steps + 1));
        q.push(node(f.x + (dx[3] * f.steps), f.y + (dy[3] * f.steps), f.dir + 'S', f.steps + 1));
    }
    
    return "";
}

int main(int argc, char** argv) {
    Read("B-small-attempt0.in");
    Write("file.out");
    int T; cin>>T;
    int cases = 1;
    while(T--){
        int x, y;
        cin>>x>>y;
        m.clear();
        string ans = bfs(x, y);
        
        cout<<"Case #"<<cases++<<": "<<ans<<endl;
    }
    return 0;
}

