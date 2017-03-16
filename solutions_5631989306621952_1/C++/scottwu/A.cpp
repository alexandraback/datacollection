#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.txt");

string S;
vector <char> l, r;

int main()
{
    int T; fin >> T;
    for (int test = 1; test <= T; test++)
    {
    fout << "Case #" << test << ": ";
    
    fin >> S;
    l.clear();
    r.clear();
    for (int i = S.length() - 1; i >= 0; i--)
    {
        bool bad = false;
        for (int j = 0; j < i; j++)
            if (S[j] > S[i])
                bad = true;
        
        if (!bad)
            l.push_back (S[i]);
        else
            r.push_back (S[i]);
    }
    
    reverse (r.begin(), r.end());
    for (int i = 0; i < l.size(); i++)
        fout << l[i];
    for (int i = 0; i < r.size(); i++)
        fout << r[i];
    fout << "\n";
    
    }
    return 0;
}
