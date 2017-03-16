#include<bits/stdc++.h>

#define SZ(x) ((int(x.size())))

typedef long long ll;
typedef long double ld;

using namespace std;

int T, t[26], x;
string s;
vector <int> ans;

int main()
{
    ios::sync_with_stdio(0);
    ifstream in;
    ofstream out;
    in.open ("A-small-attempt2.in", ios::in);
    out.open ("A-small-attempt2.out", ios::out);
    in >> T;
    for (int q = 0; q < T; q++)
    {
        in >> s;
        memset (t, 0, sizeof t);
        ans.clear();
        for (int j = 0; j < s.length(); j++)
            t[s[j] - 'A']++;
        x = t['Z' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (0);
        t['Z' - 'A'] -= x;
        t['E' - 'A'] -= x;
        t['R' - 'A'] -= x;
        t['O' - 'A'] -= x;
        x = t['U' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (4);
        t['F' - 'A'] -= x;
        t['O' - 'A'] -= x;
        t['U' - 'A'] -= x;
        t['R' - 'A'] -= x;
        x = t['X' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (6);
        t['S' - 'A'] -= x;
        t['I' - 'A'] -= x;
        t['X' - 'A'] -= x;
        x = t['F' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (5);
        t['F' - 'A'] -= x;
        t['I' - 'A'] -= x;
        t['V' - 'A'] -= x;
        t['E' - 'A'] -= x;
        x = t['R' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (3);
        t['T' - 'A'] -= x;
        t['H' - 'A'] -= x;
        t['R' - 'A'] -= x;
        t['E' - 'A'] -= 2 * x;
        x = t['W' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (2);
        t['T' - 'A'] -= x;
        t['W' - 'A'] -= x;
        t['O' - 'A'] -= x;
        x = t['O' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (1);
        t['O' - 'A'] -= x;
        t['N' - 'A'] -= x;
        t['E' - 'A'] -= x;
        x = t['V' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (7);
        t['S' - 'A'] -= x;
        t['E' - 'A'] -= 2 * x;
        t['V' - 'A'] -= x;
        t['N' - 'A'] -= x;
        x = t['G' - 'A'];
        for (int i = 0; i < x; i++)
            ans.push_back (8);
        t['E' - 'A'] -= x;
        t['I' - 'A'] -= x;
        t['G' - 'A'] -= x;
        t['H' - 'A'] -= x;
        t['T' - 'A'] -= x;
        x = t['N' - 'A'] / 2;
        for (int i = 0; i < x; i++)
            ans.push_back (9);
        t['N' - 'A'] -= 2 * x;
        t['E' - 'A'] -= x;
        t['I' - 'A'] -= x;
        sort (ans.begin(), ans.end());
        out << "Case #" << q + 1 << ": ";
        for (int i = 0; i < SZ(ans); i++)
            out << ans[i];
        out << endl;
    }
    in.close();
    out.close();
	return 0;
}
