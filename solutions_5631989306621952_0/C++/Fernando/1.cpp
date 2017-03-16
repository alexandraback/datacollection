#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int T;
string S;

int main()
{
    ifstream cin("A-small-attempt0.in");
    ofstream cout("A-small.out");
    
    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        cin >> S;
        string LS = "";
        for (int i = 0; i < S.length(); i++)
        {
            char c = S[i];
            int j = 0;
            while (j < i && LS[j] == c) j++;
            if (j < i && LS[j] < c)
                LS = c + LS;
            else
                LS = LS + c;
        }
        cout << "Case #" << casenum << ": " << LS << endl;
    }
  
    return 0;

}
