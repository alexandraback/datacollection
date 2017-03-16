#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char kb[100], m[100], e[100];
int k,l,s, tp = 0, tq = 0, mx = 0;

void isrRight()
{
    tq++;
    int cnt=0;
    for(int i = 0; i + l <= s; i++)
    {
        int flag = 1;
        for(int j = 0; j < l; j++)
        {
            if(e[j] != m[i + j])
                flag = 0;
        }
        cnt += flag;
    }
    tp += cnt;
    mx = max(mx, cnt);
}

void dfs(int dp)
{
    if(dp == s)
    {
        isrRight();
        return;
    }
    for(int i = 0; i < k; i++)
    {
        m[dp] = kb[i];
        dfs(dp + 1);
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("bsout.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> k >> l >> s;
		cin >> kb >> e;
		tp = 0, tq = 0, mx = 0;
		dfs(0);
		cout << "Case #" << i << ": ";
		double rst = (mx * tq - tp) * 1.0 / tq * 1.0;
		printf("%.8f\n", rst);
    }
    return 0;
}
