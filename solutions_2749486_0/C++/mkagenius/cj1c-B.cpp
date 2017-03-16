#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool done;
string ans;
int X, Y;
map<pair<pair<int, int>, int>,  int> mm;

void go(int x, int y, string s, int sz){
    if(abs(x) > 500 || abs(y) > 500) return;
    if(mm[make_pair(make_pair(x, y), sz)]) return;

    if(sz >= 30) return;
    if(x == X && y == Y) {
        ans = s;
        return;
    }
    mm[make_pair(make_pair(x, y), sz)] = 1;
    int n = sz + 1;
    go(x + n, y, s + 'E', sz+1);
    go(x - n, y, s + 'W', sz+1);
    go(x, y + n, s + 'N', sz+1);
    go(x, y - n, s + 'S', sz+1);
    return;

}


int main(){
    int T;
    freopen("B2.in", "r", stdin);
    freopen("B22.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++){
        ans = "";
        int x, y;
        string s = "";
        cin >> x >> y;
        for(int i = 0; i < abs(x); i++){
            if(x > 0){
                s += "WE";
            }else s += "EW";
        }
        for(int i = 0; i < abs(y); i++){
            if(y > 0){
                s += "SN";
            }else s += "NS";
        }
        cout << "Case #" << t << ": " << s << endl;
    }
}
