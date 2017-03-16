//
//  main.cpp
//  Codejam2013_1C
//
//  Created by Petro Boychuk on 5/12/13.
//  Copyright (c) 2013 Petro Boychuk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State {
    int x,y;
    int l;
    string s;
    State() {
        x = 0;
        y = 0;
        l = 0;
        s = "";
    }
    State(int x, int y, int l, string s): x(x), y(y), l(l), s(s) {
        
    }
    
    State(State const &st) {
        x = st.x;
        y = st.y;
        l = st.l;
        s = st.s;
    }
    
};

bool was[210][210][510];

void solve() {
   
    
    
    
    int x,y;
    cin >> x >> y;
    
    for (int i=0; i<210; i++) {
        for (int j=0; j<210; j++) {
            for (int k=0; k<510; k++) {
                was[i][j][k] = false;
            }
        }
    }
    
    queue<State> q;
    
    State start(0,0,0,"");
    
    q.push(start);
    
    while (q.size() > 0) {
        State st = q.front();
        
        if(st.x == x && st.y == y) {
            cout << st.s << endl;
            return;
        }
        q.pop();
        
        if(abs(st.x) > 102 || abs(st.y) > 102)
            continue;
        
        if(was[st.x + 102][st.y + 102][st.l]) {
            continue;
        }
        
        int l = st.l;
        l++;
        string ss = st.s;
        
        State n(st);
        n.y += l;
        n.l = l;
        n.s += "N";
        
        
        State w(st);
        w.x -= l;
        w.l = l;
        w.s += "W";        
        
        State s(st);
        s.y -= l;
        s.l = l;
        s.s += "S";
        
        State e(st);
        e.x += l;
        e.l = l;
        e.s += "E";
        
        q.push(n);
        q.push(w);
        q.push(e);
        q.push(s);
        
        was[st.x + 102][st.y + 102][st.l] = true;
        
    }
    
    
}

int main(int argc, const char * argv[])
{

    freopen("inputB.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);
    
    int tests;
    cin >> tests;
    
    for (int t =0; t < tests; t++) {
        cout << "Case #" << t+1 << ": ";
        solve();
    }
    
    
    return 0;
}

