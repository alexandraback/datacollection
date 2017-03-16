# include <stdio.h>
# include <string.h>
# include <iostream>
# include <map>
# include <queue>

typedef long long int lli;
using namespace std;

# define testin freopen("A-small-attempt0.in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
map<lli,int> mp;

lli rev(lli x) {
    lli ret = 0;
    lli t = x;
    while (x) {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}

lli bfs(lli n)
{
    mp.clear();
    if (n == 1) return 1;
    mp[1] = 1;
    queue<lli> Q;
    Q.push(1);
    while (!Q.empty()) {
        lli x = Q.front(); Q.pop();
        lli t = mp[x];
        if (!mp[x+1]) {
            mp[x+1] = t + 1;
            Q.push(x+1);
        }
        lli m = rev(x);
        if (!mp[m]) {
            mp[m] = t + 1;
            Q.push(m);
        }
        if (x+1 == n || m == n) {
            return t + 1;
        }
    }
}

int main()
{
    testin;
    testout;
    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        printf("Case #%d: ", ica);
        lli x;
        cin >> x;
        //printf("%lld\n", bfs(x));
        cout << bfs(x) << endl;
    }

    return 0;
}
