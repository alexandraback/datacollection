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
        input = freopen("A-small-attempt2.in" , "r" , stdin);
        output = freopen("A-small-attempt2.out" , "w" , stdout);
    }

    void solve() {
        int T;
        cin >> T;
        for(int i = 1; i <= T; i++)  {
            cout << "Case #" << i << ": " << solveCase2() << endl;
        }
    }

private:
    int solveCase2() {
        long long A;
        int N;
        cin >> A >> N;
        //cout << A << endl;
        vector<int> ms(N, 0);
        for (int i = 0; i < N; ++i)
            cin >> ms[i];
        sort(ms.begin(), ms.end());
        
        //for (int i = 0; i < N; ++i)
            //cout << ms[i] << " ";
        //cout << endl;

        int i = 0;
        while (i < N && ms[i] < A) {
            A += ms[i];
            ++i;
        }
        int res = N-i;
        if (A == 1) return res;

        int step = 0;
        while (i < N) {
            while (A <= ms[i]) {
                if (i == N-1) {
                    ++step;
                    ++i;
                    break;
                }
                A += A-1;
                ++step;
            }
            A += ms[i];
            ++i;
        }
        if (step < res) res = step;
        return res;
    }

    int solveCase1() {
        long long A;
        int N;
        cin >> A >> N;
        cout << A << endl;
        vector<int> ms(N, 0);
        for (int i = 0; i < N; ++i)
            cin >> ms[i];
        sort(ms.begin(), ms.end());
        for (int i = 0; i < N; ++i)
            cout << ms[i] << " ";
        cout << endl;
        int res = N;
        solveHelper(ms, 0, A, 0, res);
        return res;
    }

    void solveHelper(vector<int> & ms, int i, long long A, int step, int & res) {
        if (i == (int)ms.size()) {
            res = min(res, step);
            return;
        }

        if (ms[i] < A) {
            solveHelper(ms, i+1, A+ms[i], step, res);
            return;
        }

        solveHelper(ms, i+1, A, step+1, res);
        if (A == 1) return;

        solveHelper(ms, i, 2*A-1, step+1, res);
    }

    FILE * input;
    FILE * output;
};

int main() {
    Solution sol;
    sol.solve();
}
