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
    ifstream cin("B-large.in");
    ofstream cout("B.out");
    
    cin >> T;
    for (int c = 0; c < T; c++)
    {
        cout << "Case #" << c+1 << ": ";
        cin >> S;
        
        int ans = 0;
        for (int i = 0; i < S.length()-1; i++)
            if (S[i] != S[i+1]) ans++;
        if (S[S.length()-1] == '-') ans++;
        
        cout << ans << endl;
    }
    
    return 0;
}
