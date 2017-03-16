#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;


    ofstream out("s.txt");

void solve(string s)
{
    int c[30] = {0};
    for(int i=0; i<s.size(); i++)
        c[s[i]-'A']++;
    vector <int> r;

    while(c['X'-'A'])
    {
        r.push_back(6);
        c['S'-'A']--;
        c['I'-'A']--;
        c['X'-'A']--;
    }
    while(c['Z'-'A'])
    {
        r.push_back(0);
        c['Z'-'A']--;
        c['E'-'A']--;
        c['R'-'A']--;
        c['O'-'A']--;
    }
    while(c['W'-'A'])
    {
        r.push_back(2);
        c['T'-'A']--;
        c['W'-'A']--;
        c['O'-'A']--;
    }
    while(c['U'-'A'])
    {
        r.push_back(4);
        c['F'-'A']--;
        c['O'-'A']--;
        c['U'-'A']--;
        c['R'-'A']--;
    }
    while(c['O'-'A'])
    {
        r.push_back(1);
        c['O'-'A']--;
        c['N'-'A']--;
        c['E'-'A']--;
    }
    while(c['S'-'A'])
    {
        r.push_back(7);
        c['S'-'A']--;
        c['E'-'A']--;
        c['V'-'A']--;
        c['E'-'A']--;
        c['N'-'A']--;
    }
    while(c['F'-'A'])
    {
        r.push_back(5);
        c['F'-'A']--;
        c['I'-'A']--;
        c['V'-'A']--;
        c['E'-'A']--;
    }
    while(c['N'-'A'])
    {
        r.push_back(9);
        c['N'-'A']--;
        c['I'-'A']--;
        c['N'-'A']--;
        c['E'-'A']--;
    }
    while(c['G'-'A'])
    {
        r.push_back(8);
        c['E'-'A']--;
        c['I'-'A']--;
        c['G'-'A']--;
        c['H'-'A']--;
        c['T'-'A']--;
    }
    while(c['T'-'A'])
    {
        r.push_back(3);
        c['T'-'A']--;
        c['H'-'A']--;
        c['R'-'A']--;
        c['E'-'A']--;
        c['E'-'A']--;
    }

    sort(r.begin(), r.end());
    for(int i=0; i<r.size(); i++)
        out << r[i];
    out << endl;

}

int main()
{
    ifstream in("in.in");
    int tc;
    in >> tc;
    for(int w = 1; w<=tc; w++)
    {
        string s;
        in >> s;

        out << "Case #" << w << ": ";
        solve(s);

    }
    return 0;
}
