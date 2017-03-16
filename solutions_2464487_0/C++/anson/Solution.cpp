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
    int solveCase() {
        long long r, t;
        cin >> r >> t;
        
        int res = 0;
        long long a = 0;
        while (true) {
            t -= (2*(a+r)+1);
            if (t < 0) break;
            a += 2;
            res++;
        }

        return res;
    }

    
    FILE * input;
    FILE * output;
};

int main() {
    Solution sol;
    sol.solve();
}
