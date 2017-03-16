#include <functional>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cmath>
#include <ctime>

#include <numeric>
#include <iomanip>
#include <complex>
#include <float.h>
#include <cfloat>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdio>

#include <cstring>
#include <string>

#include <iterator>
#include <vector>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int kOfTest;

    cin >> kOfTest;

    for(int iTest = 1; iTest <= kOfTest; ++iTest) {
        int N;
        cin >> N;

        vector<int> S(N);
        int allSum = 0;

        for(int i = 0; i < N; ++i) {
            cin >> S[i];
            allSum += S[i];
        }

        cout << "Case #" << iTest << ":";

        for(int i = 0; i < N; ++i) {
            double left = 0, right = 100;
            while(right - left > 1e-7) {
                double middle = (left + right) / 2.0;
                double curSum = middle;
                for(int j = 0; j < N; ++j)
                    if(i != j) {
                        double value = (allSum * middle / 100 + S[i] - S[j] + 0.0) / (allSum) * 100;
                        if(value < 0)
                            value = 0;
                        curSum += value;
                    }
                if(curSum < 100)
                    left = middle; else
                    right = middle;
            }
            cout << fixed << setprecision(5) << " " << left;
        }

        cout << endl;
    }
 
    return 0;
}

