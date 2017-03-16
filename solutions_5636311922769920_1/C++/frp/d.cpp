#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

vector<int64_t> test()
{
    int64_t k, c, s;
    cin >> k >> c >> s;

    vector<int64_t> result;
    result.reserve(k);

    for (int i = 0; i < k; i += c)
    {
        int64_t position = 0, limit = min(i + c, k);
        //cout << i << k << c << c * i << " " << limit << endl;
        for (int64_t p = i; p < limit; p++)
            position = position * k + p;
        result.push_back(position);
    }

    return result.size() <= s  ? result : vector<int64_t>();
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        auto result = test();
        cout << "Case #" << i + 1 << ":";
        if (result.size() == 0)
            cout << " IMPOSSIBLE\n";
        else
        {
            for (auto student: result)
                cout << " " << student + 1;
            cout << endl;
        }
    }
}
