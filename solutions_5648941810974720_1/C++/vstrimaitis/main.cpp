#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <climits>
#include <set>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;

#define PI 3.1415926535897932384626433
#define INF ((1<<30)-1)*2+1
#define mp(a, b) make_pair((a), (b))
#define pb push_back
#define MOD 1000000007
#define MAX_N 100000
using namespace std;

string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void repl(string &s, char c){
    for(int i = 0; i < s.length(); i++)
        if(s[i] == c){
            s[i] = '.';
            return;
        }
}

void solve(string s){
    string tmp = s;
    int occ[10] = {0};
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'Z'){
            occ[0]++;
            s[i] = '.';
            repl(s, 'E');
            repl(s, 'R');
            repl(s, 'O');

        }
        if(s[i] == 'W'){
            occ[2]++;
            s[i] = '.';
            repl(s, 'T');
            repl(s, 'O');
        }
        if(s[i] == 'U'){
            occ[4]++;
            s[i] = '.';
            repl(s, 'R');
            repl(s, 'F');
            repl(s, 'O');
        }
        if(s[i] == 'X'){
            occ[6]++;
            s[i] = '.';
            repl(s, 'S');
            repl(s, 'I');
        }
        if(s[i] == 'G'){
            occ[8]++;
            s[i] = '.';
            repl(s, 'E');
            repl(s, 'I');
            repl(s, 'H');
            repl(s, 'T');
        }
    }

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'R'){
            occ[3]++;
            s[i] = '.';
            repl(s, 'E');
            repl(s, 'E');
            repl(s, 'T');
            repl(s, 'H');
        }

        if(s[i] == 'F'){
            occ[5]++;
            s[i] = '.';
            repl(s, 'I');
            repl(s, 'V');
            repl(s, 'E');
        }
        if(s[i] == 'S'){
            occ[7]++;
            s[i] = '.';
            repl(s, 'E');
            repl(s, 'V');
            repl(s, 'E');
            repl(s, 'N');
        }
    }

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'O'){
            occ[1]++;
            s[i] = '.';
            repl(s, 'N');
            repl(s, 'E');
        }

        if(s[i] == 'I'){
            occ[9]++;
            s[i] = '.';
            repl(s, 'N');
            repl(s, 'E');
            repl(s, 'N');
        }
    }

    vector<int> ans;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < occ[i]; j++){
            ans.pb(i);
            cout << i;
        }
    }



    string test = "";
    for(int i = 0; i < ans.size(); i++)
        test += nums[ans[i]];

    sort(test.begin(), test.end());
    sort(tmp.begin(), tmp.end());
    if(test != tmp)
        cout << tmp;




}

int main()
{
    freopen("../A-large.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int T;
    string s;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> s;
        cout << "Case #" << t << ": ";
        solve(s);
        cout << endl;
    }

    return 0;
}
