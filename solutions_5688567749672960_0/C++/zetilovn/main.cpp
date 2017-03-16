#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
long long sw(long long x)
{
    vector<long long> v;
    long long c = x;
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    long long r = 0, i;
    for (i = 0; i < v.size(); ++i)
    {
        r *= 10;
        r += v[i];
    }
    return r;
}
int main()
{
    ifstream cin("///Users/Zetilov/Downloads/A-small-attempt0.in-3.txt");
    //ofstream cout("///Users/Zetilov/Documents/programs/test/test/outfile.txt");
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int t, z;
    cin >> t;
    for (z = 0; z < t; ++z)
    {
        long long n, i = 0, b = 0, r = 1;
        cin >> n;
        vector<long long> q(1, 1);
        map<long long, bool> us;
        while (i < q.size())
        {
            //cout << q[i] << " " << r << endl;
            if (q[i] == n)
            {
                break;
            }
            if (!us[q[i]])
            {
                us[q[i]] = 1;
                q.push_back(q[i] + 1);
                q.push_back(sw(q[i]));
            }
            if (i == b)
            {
                b = q.size() - 1;
                ++r;
            }
            ++i;
        }
        cout << "Case #" << z + 1 << ": " << r << "\n";
    }
    return 0;
}