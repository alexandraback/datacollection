#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

std::unordered_map<int, std::vector<int>> numbers;

int norm(int x) {
    int s10 = 1;
    int cnt = 0;
    while (s10 * 10 <= x) {
        s10 *= 10;
        ++cnt;
    }
    int ans = x;
    for(int i = 0; i < cnt; ++i) {
        int last = x % 10;
        x = x / 10 + last * s10;
        if (last != 0) ans = max(ans, x);
    }
    return ans;
}

void precalc(int max = 2000001)
{
    for(int i = 1; i < max; ++i) {
        numbers[norm(i)].push_back(i);
    }
    for(auto& value : numbers) {
        sort(value.second.begin(), value.second.end());
    }
}

int number(int a, int b)
{
    int ans = 0;
    for(auto& value : numbers) {
        std::vector<int>& q = value.second;
        int cnt = (upper_bound(q.begin(), q.end(), b) - lower_bound(q.begin(), q.end(), a));
        ans += cnt * (cnt - 1) / 2;
    }
    return ans;
}

int main()
{
    precalc();
    int tst;
    cin >> tst;
    for(int iter = 0; iter < tst; ++iter) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << iter + 1 << ": " << number(a, b) << endl;
    }
    return 0;
}
