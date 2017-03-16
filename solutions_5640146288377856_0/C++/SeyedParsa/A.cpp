//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool mark[50][50];
int mem[50][50], lst[50][50];

int One(int c, int w)
{
	if (c < w) return mem[c][w] = 0;
	if (mark[c][w])
	   	return mem[c][w];
	mark[c][w] = true;
	lst[c][w] = c;
	int ans = One(c/2, w) + One((c-1)/2, w) + 1;
	if (c/2 >= w) lst[c][w] = lst[c/2][w];
	if ((c-1)/2 >= w) lst[c][w] = min(lst[c][w], lst[(c-1)/2][w]);
	return mem[c][w] = ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int it = 1; it <= t; it++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		int ans = One(c, w)*r;
		if (lst[c][w] > w) ans++;
		ans += w-1;
		cout << "Case #" << it << ": " << (c/w + w - (c%w == 0)) << endl;
	}
    return 0;
}
