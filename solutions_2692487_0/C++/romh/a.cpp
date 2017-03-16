#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
    freopen("a.in.txt", "r", stdin);
    freopen("a.out.txt", "w", stdout);
    
    int T;
    cin >> T;
    vector<long long> results;
    for (int curr = 1; curr <= T; curr++) {
        printf("Case #%d: ", curr);
        priority_queue<long long, vector<long long>, greater<long long>> motes;
        
        long A, N;
        cin >> A >> N;
        int count = 0;
        long long mote;
        for (int i = 0; i < N; i++) {
            cin >> mote;
            motes.push(mote);
        }
        
        results.clear();
        while (!motes.empty()) {
            mote = motes.top();
            motes.pop();
            
            if (A > mote) {
                A += mote;
            }
            else {
                results.push_back(count + motes.size() + 1);
                if (A == 1) {
                    count += motes.size() + 1;
                    break;
                }
                while (A <= mote) {
                    A += A-1;
                    count++;
                }
                A += mote;
            }
        }
        
        results.push_back(count);
        cout << *min_element(results.begin(), results.end()) << endl;
    }
    
    return 0;
}

