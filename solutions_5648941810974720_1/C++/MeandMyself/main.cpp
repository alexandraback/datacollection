#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;


// "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

vector < int > solve (const string &s) {
    vector < int > ans (10 , 0);
    vector < int > al (30, 0);
    for (int i = 0; i < s.size(); ++i) {
        al[s[i] - 'A']++;
    }
    ans[0] += al['Z' - 'A'];
    al['Z' - 'A'] -= ans[0];
    al['E' - 'A'] -= ans[0];
    al['R' - 'A'] -= ans[0];
    al['O' - 'A'] -= ans[0];
    ans[2] += al['W' - 'A'];
    al['T' - 'A'] -= ans[2];
    al['W' - 'A'] -= ans[2];
    al['O' - 'A'] -= ans[2];
    ans[6] += al['X' - 'A'];
    al['S' - 'A'] -= ans[6];
    al['I' - 'A'] -= ans[6];
    al['X' - 'A'] -= ans[6];
    ans[7] += al['S' - 'A'];
    al['S' - 'A'] -= ans[7];
    al['E' - 'A'] -= ans[7];
    al['V' - 'A'] -= ans[7];
    al['E' - 'A'] -= ans[7];
    al['N' - 'A'] -= ans[7];
    ans[5] += al['V' - 'A'];
    al['F' - 'A'] -= ans[5];
    al['I' - 'A'] -= ans[5];
    al['V' - 'A'] -= ans[5];
    al['E' - 'A'] -= ans[5];
    ans[4] += al['F' - 'A'];
    al['F' - 'A'] -= ans[4];
    al['O' - 'A'] -= ans[4];
    al['U' - 'A'] -= ans[4];
    al['R' - 'A'] -= ans[4];
    ans[8] += al['G' - 'A'];
    al['E' - 'A'] -= ans[8];
    al['I' - 'A'] -= ans[8];
    al['G' - 'A'] -= ans[8];
    al['H' - 'A'] -= ans[8];
    al['T' - 'A'] -= ans[8];
    ans[1] += al['O' - 'A'];
    al['O' - 'A'] -= ans[1];
    al['N' - 'A'] -= ans[1];
    al['E' - 'A'] -= ans[1];
    ans[3] += al['R' - 'A'];
    al['T' - 'A'] -= ans[3];
    al['H' - 'A'] -= ans[3];
    al['R' - 'A'] -= ans[3];
    al['R' - 'A'] -= ans[3];
    al['E' - 'A'] -= ans[3];
    ans[9] += al['I' - 'A'];
    al['N' - 'A'] -= ans[9];
    al['I' - 'A'] -= ans[9];
    al['N' - 'A'] -= ans[9];
    al['E' - 'A'] -= ans[9];
    return ans;

}


int main()
{
    ifstream cin ("/Users/Roman/ClionProjects/Calculations/input.txt");
    ofstream cout ("/Users/Roman/ClionProjects/Calculations/output.txt");

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout.setf(ios_base::fixed);
    cout.precision(28);

    int tt;
    cin >> tt;
    //cout << tt;
    for (int t = 0; t < tt; ++t) {
        string s;
        cin >> s;
        auto p = solve(s);
        cout << "Case #" << t + 1 << ": ";
        for (int i = 0; i < p.size(); ++i) {
            while (p[i] != 0) {
                cout << char('0' + i);
                p[i]--;
            }
        }
        cout << endl;
    }
    return 0;
}