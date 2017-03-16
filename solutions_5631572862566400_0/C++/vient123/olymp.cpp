#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <bitset>
#include <sstream>
#include <iterator>

using namespace std;

int solve(vector<int> &V, vector<int> now, size_t it)
{
    if (it == V.size())
    {
        if (now.size() < 2)
            return 1;
        do
        {
            bool ok = true;
            for (size_t i = 1; i + 1 < now.size(); ++i)
                ok &= (V[now[i]] == now[i + 1] || V[now[i]] == now[i - 1]);
            ok &= (V[now[0]] == now[1] || V[now[0]] == now.back());
            ok &= (V[now.back()] == now[now.size() - 2] || V[now.back()] == now[0]);
            if (ok)
                return now.size();
        } while (next_permutation(now.begin(), now.end()));
        return -1;
    }
    auto x = solve(V, now, it + 1);
    now.emplace_back(it);
    return max(x, solve(V, now, it + 1));
}

int main() 
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int TESTS;
    in >> TESTS;
    for (auto TEST = 1; TEST <= TESTS; ++TEST)
    {
        out << "Case #" << TEST << ": ";
        size_t n;
        in >> n;
        vector<int> V(n);
        for (auto &x : V)
            in >> x;
        for (auto &x : V)
            --x;
        out << solve(V, vector<int>(), 0);
        out << endl;
    }
}
