#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream cin("/Users/mac/topcoder/B-large.in.txt");
    ofstream cout("/Users/mac/topcoder/res.txt");
    
    int N;
    cin >> N;
    
    for (int CT = 0; CT < N; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        int N, M;
        cin >> N >> M;
        
        vector<vector<int> > a(N);
        
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < M; j ++) {
                int t;
                cin >> t;
                a[i].push_back(t);
            }
        
        bool possible = true;
        for (int c = 0; c < N + M; c ++) {
            int mi = 0, mj = 0;
            
            for (int i = 0; i < N; i ++)
                for (int j = 0; j < M; j ++)
                    if (a[i][j] < a[mi][mj]) {
                        mi = i;
                        mj = j;
                    }
            
            bool isHoriz = true;
            for (int j = 0; j < M; j ++)
                if (a[mi][j] != a[mi][mj] && a[mi][j] != 101) {
                    isHoriz = false;
                    break;
                }
            
            bool isVert = true;
            for (int i = 0; i < N; i ++)
                if (a[i][mj] != a[mi][mj] && a[i][mj] != 101) {
                    isVert = false;
                    break;
                }
            
            if (!isVert && !isHoriz) {
                possible = false;
                break;
            }
            
            if (isHoriz) {
                for (int j = 0; j < M; j ++)
                    a[mi][j] = 101;
            } else {
                for (int i = 0; i < N; i ++)
                    a[i][mj] = 101;
            }
        }
        
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}