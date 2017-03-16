#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    ifstream cin("input");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int answer = 0;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
            {
                if ((i & j) >= 0 && (i & j) < k)
                {
                    ++answer;
                    // cout << i << " " << j << endl;
                }
            }
        cout << "Case #" << q + 1 << ": " << answer << endl;
    }
}