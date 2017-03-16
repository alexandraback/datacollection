#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

string process(int x, int y) {
    queue<pair<int, int> > q;
    queue<string> path;
    string s="";
    int unit = 1;
    int pLength = 0;
    string route;
    bool flagMatrix[1001][1001];
    for (int i=0; i<=1000; i++)
        for(int j=0; j<=1000; j++)
            flagMatrix[i][j]=false;
    int bias=500;
    flagMatrix[bias][bias]=true;
    q.push(make_pair(0, 0));
    path.push("");
    while(true) {
        pair<int, int> p;
        p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;        
        route = path.front();
        if (pLength < route.size()) {
            pLength = route.size();
            unit++;
        }
        path.pop();
        if (a == x && b == y) {
            break;
        }      
        if (a + unit == x && b == y){
            route = route + "E";
            break;
        } else {
            if (a != x) {
                int xx = a+unit;
                int yy = b;
                if (flagMatrix[bias+xx][bias+yy] == false) {
                    flagMatrix[bias+xx][bias+yy]=true;
                q.push(make_pair(xx, yy));
                path.push(route+"E"); }
            }
        }
        if (a - unit == x && b == y){
            route = route + "W";
            break;
        } else {
            if (a != x) {
                int xx = a-unit;
                int yy = b;
                if (flagMatrix[bias+xx][bias+yy] == false) {
                flagMatrix[bias+xx][bias+yy]=true;
                q.push(make_pair(a-unit, b));
                path.push(route+"W"); }
            }
        }
        if (a == x && b+unit == y){
            route = route + "N";
            break;
        } else {
            if (b != y) {
                int xx = a;
                int yy = b+unit;
                if (flagMatrix[bias+xx][bias+yy] == false) {
                flagMatrix[bias+xx][bias+yy]=true;
                q.push(make_pair(a, b+unit));
                path.push(route+"N"); }
            }
        }        
        if (a == x && b-unit == y){
            route =route + "S";
            break;
        } else {
            if (b!=y) {
                int xx = a;
                int yy = b-unit;
                if (flagMatrix[bias+xx][bias+yy] == false) {
                                flagMatrix[bias+xx][bias+yy]=true;
                q.push(make_pair(a, b-unit));
                path.push(route+"S"); }
            }

        }
    }
    while (q.empty() == false)
        q.pop();
    while (path.empty() == false)
        path.pop();
    return route;    
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; i++) {
        int x,y;
        cin>>x>>y;
        cout<<"Case #"<<i<<": "<<process(x, y)<<endl;
    }
}
