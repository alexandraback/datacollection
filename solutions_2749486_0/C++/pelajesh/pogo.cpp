#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

ifstream sf("pogo.in");
ofstream vf("pogo.out");

map<pair<int, int>, char > been;
map<pair<int, int>, int > turn;
vector<pair<int, int> > q;
int t;
int tx, ty, x, y;

string GetPath() {
    int curx = tx, cury = ty;
    string p = "";
    while (1) {
        char c = been[make_pair(curx, cury)];
        int dist = turn[make_pair(curx, cury)];
        if (c == 'N') {
            cury -= dist;
        }
        else if (c == 'S') {
            cury += dist;
        }
        else if (c == 'E') {
            curx -= dist;
        }
        else if (c == 'W') {
            curx += dist;
        }
        else break;
        p += c;
    }
    reverse(p.begin(), p.end());
    return p;
}

int main () {
    sf >> t;
    for (int k = 1; k <= t; k++) {
        turn.clear();
        q.clear();
        been.clear();
        sf >> tx >> ty;
        x = y = 0;
        turn[make_pair(0,0)] = 0;
        been[make_pair(0,0)] = '0';
        q.push_back(make_pair(0,0));
        int c = 0;
        while (x != tx || y != ty) {
            x = q[c].first;
            y = q[c].second; 
            int ct = turn[make_pair(x,y)] + 1;
            if (been.count(make_pair(x+ct,y)) == 0) {
                been[make_pair(x+ct, y)] = 'E';
                turn[make_pair(x+ct, y)] = ct;
                q.push_back(make_pair(x+ct, y));
                if (x+ct == tx && y == ty) break;
            }
            if (been.count(make_pair(x-ct,y)) == 0) {
                been[make_pair(x-ct, y)] = 'W';
                turn[make_pair(x-ct, y)] = ct;
                q.push_back(make_pair(x-ct, y));
                if (x-ct == tx && y == ty) break;
            }
            if (been.count(make_pair(x,y+ct)) == 0) {
                been[make_pair(x, y+ct)] = 'N';
                turn[make_pair(x, y+ct)] = ct;
                q.push_back(make_pair(x, y+ct));
                if (x == tx && y+ct == ty) break;
            }
            if (been.count(make_pair(x,y-ct)) == 0) {
                been[make_pair(x, y-ct)] = 'S';
                turn[make_pair(x, y-ct)] = ct;
                q.push_back(make_pair(x, y-ct));
                if (x == tx && y-ct == ty) break;
            }
            c++;  
        }
        vf << "Case #" << k << ": " << GetPath() << endl;   
    }
}
