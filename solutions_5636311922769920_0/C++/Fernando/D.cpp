#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int T, K, C, S;

int main()
{
    ifstream cin("D-small-attempt0.in");
    ofstream cout("D.out");
    
    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        cout << "Case #" << casenum << ":";
        cin >> K >> C >> S;
        for (int i = 1; i <= K; i++) cout << " " << i;
        cout << endl;
    }
    
    return 0;
}
