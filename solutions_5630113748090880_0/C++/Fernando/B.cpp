#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int T, N;

int main()
{
    ifstream cin("B-small-attempt0.in");
    ofstream cout("B-small.out");
    
    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        cin >> N;
        VVI rc(2*N-1);
        VI occ(3000);
        for (int i = 0; i < 2*N-1; i++)
        {
            rc[i].resize(N);
            for (int j = 0; j < N; j++) 
            {
                cin >> rc[i][j];
                occ[rc[i][j]]++;
            }
        }
        
        cout << "Case #" << casenum << ":";
        for (int k = 0; k < 3000; k++) 
            if (occ[k] % 2 > 0) cout << " " << k;
        cout << endl;
    }
    
    return 0;
}
