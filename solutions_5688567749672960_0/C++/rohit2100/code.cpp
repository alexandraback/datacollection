#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li vis[9999999];
li dp[9999999];

li rev(li i)
{
    li temp = 0;
    while(i != 0){
        temp = (temp * 10) + i % 10;
        i /= 10;
    }
    return temp;
}

li fun()
{
    memset(vis, 0, sizeof vis);
    queue <pair <li, li> > q;
    q.push(make_pair(1, 1));
    while(1){
        pair <li , li> fr = q.front();
        q.pop();
        if(fr.first > 10000000 || fr.second > 1000000){
            return 0;
        }
        if(vis[fr.first] == 1) continue;
        //cout << fr.first << " " << fr.second << "\n";
        vis[fr.first] = 1;
        dp[fr.first] = fr.second;
        q.push(make_pair(fr.first + 1, fr.second + 1));
        li temp = rev(fr.first);
        q.push(make_pair(temp, fr.second + 1));
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cout << "Hello World\n";

    //cout << rev(100234);

    fun();
    li t, cnt = 0, n;
    cin >> t;
    while(t--){
        cin >> n;
        printf("Case #%lld: %lld\n", ++cnt, dp[n]);
    }

    return 0;
}
