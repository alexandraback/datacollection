#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

class Solution {
public:
    Solution() {
        input = freopen("data.in" , "r" , stdin);
        output = freopen("data.out" , "w" , stdout);
    }
    
    ~Solution() {
        fclose(input);
        fclose(output);
    }
    void solve() {
        int T;
        cin >> T;
        for(int i = 1; i <= T; i++)  {
            cout << "Case #" << i << ": " << solveCase() << endl;
        }
    }

private:
    long long solveCase() {
        int E, R, N;
        cin >> E >> R >> N;
        vector<int> vs;
        for (int i = 0; i < N; i++) {
            int v;
            cin >> v;
            vs.push_back(v);
        }

        long long res = 0;
        if (E <= R) {
            for (int i = 0; i < N; i++)
                res += vs[i];
            return E*res;
        }
        
        long long sum = 0;
        solveHelper(vs, 0, E, E, R, sum, res);
        return res;
    }

    void solveHelper(vector<int> & vs, size_t i, int e, int E, int R, long long sum, long long & res) {
        if (i == vs.size()) {
            if (sum > res) res = sum;
            return;
        }
        
        for (int j = 0; j <= e; j++) {
            solveHelper(vs, i+1, (e-j+R > E) ? E : e-j+R, E, R, sum+vs[i]*j, res);
        } 
    }

    
    FILE * input;
    FILE * output;
};

int main() {
    Solution sol;
    sol.solve();
}
