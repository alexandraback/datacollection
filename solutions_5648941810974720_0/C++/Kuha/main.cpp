#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ull unsigned long long
#define uint unsigned int
#define ll long long
#define INF 999999999
#define LINF 999999999999999999
#define M 1000000007
#define E 0.0000001
#define N (1<<17)

using namespace std;

int main() {
    ifstream in("google.in");
    ofstream out("google.out");

    int n;
    in>>n;

    for (int c = 1; c <= n; c++) {
        vector<int> v;

        string s;
        in>>s;

        unordered_map<char, int> m;

        for (char x : s) m[x]++;

        while (m['Z']) {
            m['Z']--;
            m['E']--;
            m['R']--;
            m['O']--;
            v.push_back(0);
        }
        while (m['X']) {
            m['S']--;
            m['I']--;
            m['X']--;
            v.push_back(6);
        }
        while (m['W']) {
            m['T']--;
            m['W']--;
            m['O']--;
            v.push_back(2);
        }
        while (m['G']) {
            m['E']--;
            m['I']--;
            m['G']--;
            m['H']--;
            m['T']--;
            v.push_back(8);
        }
        while (m['S']) {
            m['S']--;
            m['E']--;
            m['V']--;
            m['E']--;
            m['N']--;
            v.push_back(7);
        }
        while (m['V']) {
            m['F']--;
            m['I']--;
            m['V']--;
            m['E']--;
            v.push_back(5);
        }
        while (m['F']) {
            m['F']--;
            m['O']--;
            m['U']--;
            m['R']--;
            v.push_back(4);
        }
        while (m['O']) {
            m['O']--;
            m['N']--;
            m['E']--;
            v.push_back(1);
        }
        while (m['T']) {
            m['T']--;
            m['H']--;
            m['R']--;
            m['E']--;
            m['E']--;
            v.push_back(3);
        }
        while (m['N']) {
            m['N']--;
            m['I']--;
            m['N']--;
            m['E']--;
            v.push_back(9);
        }

        sort(v.begin(), v.end());
        out<<"Case #"<<c<<": ";
        for (int i : v) out<<i;
        out<<endl;
    }

    out.close();
    return 0;
}
