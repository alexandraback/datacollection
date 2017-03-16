#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] = nums[i] - 1;
    }
    
    int maxRes = 1;
    
    vector<unordered_set<int>> loved(n);
    for (int i = 0; i < n; i++) {
        loved[nums[i]].insert(i);
    }
    
    // non circle case.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == j && nums[j] == i) {
                int level = 0;
                unordered_set<int> st;
                queue<int> q;
                q.push(i);
                st.insert(i);
                st.insert(j);
                while (!q.empty()) {
                    level++;
                    int t = q.size();
                    for (int j = 0; j < t; j++) {
                        int node = q.front();
                        q.pop();
                        for (auto nn : loved[node]) {
                            if (st.find(nn) == st.end()) {
                                st.insert(nn);
                                q.push(nn);
                            }
                        }
                    }
                }
                int depthi = level;
                level = 0;
                st.clear();
                q.push(j);
                st.insert(i);
                st.insert(j);
                while (!q.empty()) {
                    level++;
                    int t = q.size();
                    for (int j = 0; j < t; j++) {
                        int node = q.front();
                        q.pop();
                        for (auto nn : loved[node]) {
                            if (st.find(nn) == st.end()) {
                                st.insert(nn);
                                q.push(nn);
                            }
                        }
                    }
                }
                maxRes = max(maxRes, depthi + level);
            }
        }
    }
    
    // circle case.
    for (int i = 0; i < n; i++) {
        vector<int> res;
        unordered_set<int> st;
        st.insert(i);
        res.push_back(i);
        bool flag = true;
        while (nums[res.back()] != i) {
            if (st.find(nums[res.back()]) != st.end()) {
                flag = false;
                break;
            } else {
                int temp = nums[res.back()];
                st.insert(temp);
                res.push_back(temp);
            }
        }
        
        if (flag) {
            maxRes = max(maxRes, (int)res.size());
        }
    }
    
    cout << maxRes << endl;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }
    return 0;
}

