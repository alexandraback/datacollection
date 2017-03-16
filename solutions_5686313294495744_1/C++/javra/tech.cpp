#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;

    map<string,int> first;
    map<string,int> second;

    vector<pair<string,string>> pairs;

    for(int i = 0; i < N; i++)
    {
        string a,b;
        cin >> a >> b;

        first[a] += 1;
        second[b] += 1;
        pairs.emplace_back(make_pair(a,b));
    }

    int bestfakes = 0;
    for(int i = 0; i < 5000; i++)
    {
        random_shuffle(pairs.begin(), pairs.end());
        map<string,int> tfirst = first;
        map<string,int> tsecond = second;
        
        int fakes = 0;
        for(auto & p : pairs)
        {
            if(tfirst[p.first] > 1 && tsecond[p.second] > 1)
            {
                fakes += 1;
                tfirst[p.first] -= 1;
                tsecond[p.second] -= 1;
            }
        }
        bestfakes = max(fakes, bestfakes);
    }

    cout << bestfakes;
}

int main()
{
    cout.precision(8);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

