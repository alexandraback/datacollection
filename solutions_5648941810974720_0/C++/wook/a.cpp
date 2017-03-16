#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

string a;
int freq[26];
int letters = 0;

const char* words[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
    "SIX", "SEVEN", "EIGHT", "NINE", "TEN"
};

bool able(int i) {
    const string w = words[i];
    for(char x : w) {
        if(not ('A' <= x && x <= 'Z')) continue;
        if( freq[x - 'A'] <= 0 ) return false;
    }
    return true;
}
void subtract(int i) {
    const string w = words[i];
    for(char x : w) {
        if(not ('A' <= x && x <= 'Z')) continue;
        freq[x - 'A'] --;
        letters--;
    }
}

string go()
{
    string ans;

    memset(freq, 0, sizeof freq);
    letters = 0;
    for(char x : a) {
        if('A' <= x && x <= 'Z') {
            freq[x - 'A']++;
            letters ++;
        }
    }

    map<char, int> fix;
    fix['W'] = 2;
    fix['X'] = 6;
    fix['G'] = 8;
    fix['U'] = 4;
    fix['Z'] = 0;

    auto go = [&]() {
        while(true)
        {
            bool hit = false;
            char x; int y;
            for(auto &it : fix) {
                x = it.first; y = it.second;
                if(freq[x - 'A'] == 0) continue;
                hit = true; break;
            }
            if(!hit) break;
            subtract(y);
            ans += string(1, '0' + y);
        }
    };
    go();

    fix.clear();
    fix['R'] = 3;
    fix['H'] = 3;
    fix['T'] = 3;
    fix['S'] = 7;
    fix['F'] = 5;
    go();

    fix.clear();
    fix['O'] = 1;
    fix['I'] = 9;
    go();

    fix.clear();
    fix['E'] = 0;
    go();

    //printf("%s %d\n", ans.c_str(), letters);
    assert (letters == 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    /*
    set<int> invmap[26];
    for(int i=0; i<=9; ++i) {
        for(char x : string(words[i])) {
            if(not ('A' <= x && x <= 'Z')) continue;
            invmap[x - 'A'].insert(i);
        }
    }
    for(char x = 'A'; x <= 'Z'; ++ x) {
        cout << x << " : ";
        for(int i : invmap[x - 'A']) {
            cout << i << ' ';
        }
        cout << endl;
    }*/

    int T;
    int kase = 0;
    cin >> T;
    while(T-- > 0) {
        cin >> a;
        sort(a.begin(), a.end());
        cout << "Case #" << ++kase << ": ";
        cout << go() << endl;
    }
    return 0;
}

