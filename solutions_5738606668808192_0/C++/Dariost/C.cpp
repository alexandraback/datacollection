#include <bits/stdc++.h>

using namespace std;

long long int first_factor(long long int i)
{
    if(i % 2 == 0)
        return 2;
    long long int sq = sqrt(i) + 4;
    for(int j = 3; j < sq; j++)
    {
        if(i % j == 0)
            return j;
    }
    return i;
}

int main()
{
    const long long int n = 16;
    long long int j = 50;
    size_t dummy;
    long long int num = (1LL << (n - 1)) + 1;
    vector<long long int> sol;
    while(sol.size() / 10 < j)
    {
        vector<long long int> v(9, 0);
        bitset<n> b(num);
        for(long long int i = 2; i <= 10; i++)
        {
            long long int local_num = stoll(b.to_string(), &dummy, i);
            auto ret = first_factor(local_num);
            if(ret == local_num)
                v[i - 2] = 0;
            else
                v[i - 2] = ret;
        }
        if(count(v.begin(), v.end(), 0) == 0)
        {
            sol.push_back(num);
            for(auto& i: v)
                sol.push_back(i);
        }
        cerr << "Found " << sol.size() / 10 << "/" << j << endl;
        num += 2;
    }
    cout << "Case #1:" << endl;
    for(long long int i = 0; i < (long long int)sol.size() / 10; i++)
    {
        bitset<n> b(sol[i * 10]);
        cout << b.to_string() << " ";
        for(long long int j = (i * 10) + 1; j < (i + 1) * 10; j++)
            cout << sol[j] << " ";
        cout << endl;
    }
    return 0;
}
