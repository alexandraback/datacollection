
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef long long int lli;

int cnt [2501];

int main() {

    ifstream fin ("input.txt");
    ofstream fout ("ans.txt");
    
    lli T; fin >> T;
    for (lli t = 0; t < T; t++) {
        
        memset(cnt, 0, sizeof(cnt));
        vector<int>ans;
        
        int N; fin >> N;
        for (int i = 0; i < 2*N-1; i++)
        {
            for (int k = 0; k < N; k++) {
                int b; fin >> b;
                cnt[b] ++;
            }
        }
        
        for (int i = 0; i < 2501; i++) {
            if (cnt[i] % 2 != 0)
                ans.push_back(i);
        }
        
        sort(ans.begin(), ans.end());
        
        fout << "Case #" << t+1 << ":" ;
        for (int i = 0; i < N; i++)
            fout <<  " " << ans[i];
        fout << "\n";
    }
    
    return 0;
}

