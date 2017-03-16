// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: 

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define D(x) 

int main() {
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++) {
        int A, N;
        cin >> A >> N;

        vector<int> sizes(N);
        for (int i = 0; i < N; i++) {
            cin >> sizes[i];
        }

        sort(sizes.begin(), sizes.end());
        int minOps = N;

        for (int end = 1; end <= N; end++) {
            int size = A;
            int ops = 0;
            bool feasible = true;

            for (int i = 0; i < end; i++) {
                D(cerr << "i=" << i << endl);
                int target = sizes[i];

                while (size <= target) {
                    if (size <= 1) {
                        feasible = false; break;
                    }
                    size += size-1;
                    ops++;
                }
                if (!feasible) break;
                size += target;
            }
            if (!feasible) continue;

            ops += N-end; // delete remaining

            minOps = min(ops, minOps);
        }

        cout << "Case #" << testCase << ": ";
        cout << minOps;
        cout << endl;
    }
}
