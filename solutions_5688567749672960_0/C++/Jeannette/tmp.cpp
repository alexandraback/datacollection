#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <set>
#include <queue>
using namespace std;

int const maxn = 10000000;
int ans[maxn];

long long reverse(long long n)
{
	long long res = 0;
	while (n > 0)
	{
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return res;
}

void precalc()
{
    queue<int> q;
    ans[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int next = x + 1;
        if (next < maxn && ans[next] == 0)
        {
            ans[next] = ans[x] + 1;
            q.push(next);
        }
        next = reverse(x);
        if (next < maxn && ans[next] == 0)
        {
            ans[next] = ans[x] + 1;
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	cin>>t;
	precalc();
	for (int j = 0; j < t; ++j)
	{
		int cur = 0;
        cin >> cur;
		cout<<"Case #"<<j + 1<<": "<<ans[cur]<<endl;
	}
    return 0;
}
