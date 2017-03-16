#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int done[1000001] = {0};
int main()
{
    freopen("stuff.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, rev = 0, buf = 0;
    queue <int> q;
    cin >> t;
    fill(done, done + 1000001, 99999999);
    done[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        if(x > 1000000)
        {
            q.pop();
            continue;
        }
        if(done[x + 1] > done[x] + 1)
        {
            done[x + 1] = done[x] + 1;
            q.push(x + 1);
        }
        rev = 0;
        while(x != 0)
        {
            buf = x % 10;
            x /= 10;
            rev *= 10;
            rev += buf;
        }
        if(done[rev] > done[q.front()] + 1)
        {
            done[rev] = done[q.front()] + 1;
            q.push(rev);
        }
        q.pop();
    }
    for(int z = 1; z <= t; z++)
    {
        cin >> n;
        cout << "Case #" << z << ": " << done[n] << "\n";
    }
    return 0;
}
