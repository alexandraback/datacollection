#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

typedef long long int ll;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ll n;
        cin >> n;
        vector<int> steps(n + 1, n + 1);
        steps[1] = 1;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            if (p + 1 < n + 1 && steps[p + 1] > steps[p] + 1)
            {
                steps[p + 1] = steps[p] + 1;
                q.push(p + 1);
            }

            string s;
            stringstream ss;
            ss << p;
            ss >> s;
            reverse(s.begin(), s.end());
            int nxt = atoi(s.c_str());

            if (nxt < n + 1 && steps[nxt] > steps[p] + 1)
            {
                steps[nxt] = steps[p] + 1;
                q.push(nxt);
            }
        }

        cout << "Case #" << i + 1 << ": " << steps[n] << endl;
    }

    return 0;
}
