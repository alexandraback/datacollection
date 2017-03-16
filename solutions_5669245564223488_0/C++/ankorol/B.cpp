#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isCorrect(const string& s)
{
    if (s.size() <= 2)
        return true;
    int a[26] = {0};
    for (int i = 0; i < s.size();)
    {
        if (a[s[i] - 'a'] != 0)
            return false;
        a[s[i] - 'a'] = 1;
        int j = i + 1;
        while ((j < s.size()) && (s[i] == s[j])) ++j;
        i = j;
    }
    return true;
}

bool isCorrect(const vector<string>& vs, const vector<int>& per)
{
    string b;
    for (int i = 0; i < per.size(); ++i)
    {
        b.append(vs[per[i]]);
    }
    return isCorrect(b);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        vector<string> p;
        p.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> p[i];
        vector<int> per;
        for (int i = 0; i < N; ++i)
            per.push_back(i);
        int ans = 0;
        while (true)
        {
            if (isCorrect(p, per))
                ans++;
            if (!next_permutation(per.begin(), per.end()))
                break;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}