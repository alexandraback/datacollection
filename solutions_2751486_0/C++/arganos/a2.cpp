/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

fstream out;
int t;
int n;
string s;
bool iscons[1000];
int cnt[1000001];

bool ok(string w) {
    int cur = 0;
    //cout << w << endl;
    for (int i = 0; i < w.length(); i++) {
        if (!iscons[w[i]])
            cur++;
        else
            cur = 0;
        if (cur >= n)
            return 1;
    }
    return 0;
}

int getres() {
    int res = 0;
    
    for (int i = 0; i < s.length(); i++)
        for (int j = i; j < s.length(); j++)
            res += ok(s.substr(i, j-i+1));
    
    return res;
    
}

int main()
{
    cin >> t;
    
    iscons['a'] = 1;
    iscons['i'] = 1;
    iscons['u'] = 1;
    iscons['e'] = 1;
    iscons['o'] = 1;
    
    for (int i = 0; i < t; i++) {
        cin >> s >> n;
        cout << "Case #" << i+1 << ": " << getres() << endl;
     }
}

