#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

bool check(vector<string> &v, char c) {

    bool good;
    for(int i = 0; i < 4; i++) {
        good = true;
        for(int j = 0; j < 4; j++) {
            good &= (v[i][j] == c || v[i][j] == 'T');
        }
        if(good) return true;
    }

    for(int i = 0; i < 4; i++) {
        good = true;
        for(int j = 0; j < 4; j++) {
            good &= (v[j][i] == c || v[j][i] == 'T');
        }
        if(good) return true;
    }

    good = true;
    for(int i = 0; i < 4; i++) {
        good &= (v[i][i] == c || v[i][i] == 'T');

    }

    if(good) return true;

    good = true;
    for(int i = 0; i < 4; i++) {
        good &= (v[i][3-i] == c || v[i][3-i] == 'T');

    }

    if(good) return true;



    return false;
}
void run(int t) {
    vector<string> v(4);
    for(int i =0; i < 4;i++) cin>>v[i];

    int dot_count = 0;
    for(int i = 0; i < 4; i++) {

        for(int j = 0; j < 4; j++) {
            if(v[i][j] == '.') dot_count++;
        }
    }

    cout << "Case #" << t << ": ";
    if(check(v, 'X')) {
        cout << "X won" << endl;
    } else if(check(v, 'O')) {
        cout << "O won" << endl;
    } else if(dot_count > 0) {
        cout << "Game has not completed" << endl;
    } else {
        cout << "Draw" << endl;
    }


}

int main() {

    ifstream in("A-small-attempt0.in");
    int t;
    cin>>t;
    for(int i = 0; i < t ; i++) {

        run(i+1);
    }


}
