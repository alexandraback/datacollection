#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    int N;
    cin >> T;
    for (int i = 1; i <= T; i ++)
    {
        cout << "Case #" << i << ": ";
        cin >> N;
        int a;
        unordered_map<int, int> count;
        for (int j = 0; j < 2*N-1; j ++)
        {
            for (int k = 0; k < N; k ++)
            {
                cin >> a;
                count[a] ++;
            }
        }
        vector<int> ret;
        for (auto &s : count)
            if (s.second % 2 == 1)
                ret.push_back(s.first);
        sort(ret.begin(), ret.end());
        for (int j = 0; j < ret.size(); j ++)
            cout << ret[j] << ' ';
        cout << endl;
    }
    return 0;
}
