#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int result;

void dfs(vector<int> a, vector<int>& visit, int v, vector<int>& group) {
    for (int i(0); i<a.size(); i++){
        if (visit[i] == 0) {
            if ((a[v] == i) || (a[i] == v)) {
                visit[i] = 1;
                group.push_back(i);
                dfs(a, visit, i, group);
                if (group.size() > result) {
                    bool flag = true;
                    for (int j(0); j<group.size(); j++) {
                        int val = group[j];
                        int x = j - 1;
                        if (x < 0) {
                            x = group.size() - 1;
                        }
                        int y = j + 1;
                        if (y >= group.size()) {
                            y = 0;
                        }
                        if ((a[val] != group[x]) && (a[val] != group[y])) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        result = group.size();
                    }
                }
                group.pop_back();
                visit[i] = 0;
            }
        }
    }
}

int main() {
    ifstream fi("c.in");
    ofstream fo("c.out");
    
    int t;
    fi >> t;
    
    for (int i(0); i<t; i++) {
        int n;
        fi >> n;
        
        vector<int> a(n, 0);
        for (int j(0); j<n; j++) {
            int x;
            fi >> x;
            a[j] = x - 1;
        }
        
        
        result = 0;
        
        for (int j(0); j<n; j++) {
            vector<int> group;
            vector<int> visit(n, 0);
            visit[j] = 1;
            group.push_back(j);
            dfs(a, visit, j, group);
            if (result == n) {
                break;
            }
        }
        fo << "Case #" << i + 1 << ": " << result << endl;
        
        
   }
    
    fi.close();
    fo.close();
    return 0;
}