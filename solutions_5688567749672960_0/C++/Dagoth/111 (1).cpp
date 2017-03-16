#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

int inf = 1e9;

int rev(int r)
{
    string s = "";
    while(r)
    {
        char c = (r % 10) + '0';
        s = c + s;
        r /= 10;
    }
    reverse(all(s));
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        ans *= 10;
        ans += (s[i] - '0');
    }
    return ans;
}

signed main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    int fix = 0;
    int n = 1000010;
        vector<int> used(n + 1000, 0), tr(n + 1000, inf);
        deque<pair<int, int> > dd;
        dd.push_back({1, 1});
        while(!dd.empty())
        {
            int turn = dd[0].second, num = dd[0].first;
            dd.pop_front();
            if(used[num])
                continue;
            tr[num] = turn;
            used[num] = 1;
            int revs = rev(num);
            if(revs <= n && used[revs] == 0)
                dd.push_back({revs, turn + 1});
            if(num + 1 <= n && used[num + 1] == 0)
                dd.push_back({num + 1, turn + 1});
        }
       // cout << "Case #" << fix << ": " << tr[n] << '\n';
    fix = 0;
    while(T--)
    {
        fix++;
        cin >> n;
        cout << "Case #" << fix << ": " << tr[n] << '\n';
    }
    return 0;
}
