#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <iostream>
using namespace std;



int main() {
    //    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        
        int N;
        cin >> N;

        map<int, int> result;
        
        
        for (int i = 0; i < 2*N-1; i++) {
            for (int j = 0; j < N; j++) {
                int x;
                cin >> x;
                if (result.find(x) == result.end())
                    result[x] = 1;
                else
                    result[x]++;
            }
        }
        
        vector<int> output;
        
        for (int i = 1; i < 2500; i++) {
            if (result.find(i) == result.end())
                continue;
            else if (result[i] % 2 == 1)
                output.push_back(i);
        }
        
        sort(output.begin(), output.end());
        
        
        cout << "Case #" << z+1 << ": ";
        
        for (int i = 0; i < output.size(); i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
        
        
        
    }
    

    
    return 0;
}
