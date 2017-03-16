#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

queue <pair<pair<int, int>,int> > Q;
map <pair<int, int>, string> M;
void init(){
    M.clear();
    M[make_pair(0,0)] = "";
    Q.push(make_pair(make_pair(0,0),0));
    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int deep = Q.front().second+1;
        Q.pop();
        if (abs(x) > 200 || abs(y) > 200) continue;
        int x_new, y_new;
        x_new = x-deep;
        y_new = y;
        map <pair<int, int>, string>::iterator it = M.find(make_pair(x_new,y_new));
        if (it == M.end()) {
            M[make_pair(x_new,y_new)] = M[make_pair(x,y)] + "W";
            Q.push(make_pair(make_pair(x_new,y_new),deep));
        }
        x_new = x+deep;
        y_new = y;
        it = M.find(make_pair(x_new,y_new));
        if (it == M.end()) {
            M[make_pair(x_new,y_new)] = M[make_pair(x,y)] + "E";
            Q.push(make_pair(make_pair(x_new,y_new),deep));
        }
        x_new = x;
        y_new = y-deep;
        it = M.find(make_pair(x_new,y_new));
        if (it == M.end()) {
            M[make_pair(x_new,y_new)] = M[make_pair(x,y)] + "S";
            Q.push(make_pair(make_pair(x_new,y_new),deep));
        }
        x_new = x;
        y_new = y+deep;
        it = M.find(make_pair(x_new,y_new));
        if (it == M.end()) {
            M[make_pair(x_new,y_new)] = M[make_pair(x,y)] + "N";
            Q.push(make_pair(make_pair(x_new,y_new),deep));
        }
    }
}

int main() {
    int T, c;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
    init();
    scanf("%d", &T);
    for (c =  1 ; c <= T; ++ c) {
        int x, y, ans;
        cin>>x>>y;
        printf("Case #%d: ", c);
        cout << M[make_pair(x,y)]<<endl;
    }
    return 0;
}
