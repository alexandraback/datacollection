#include <iostream>
#include <cstring> 
#define MAXN 12
using namespace std;

int n, nn, result, bff[MAXN], p[MAXN], choose[MAXN];

/*void find(int depth)
{
	int i, b;
	if (depth > n + 1)
		return;
	if (depth == 1) {
		for (i = 1; i <= n; i++)
			if (choose[i] == 0) {
				p[1] = i;
				choose[i] = 1;
				find(depth + 1);
				choose[i] = 0;
				p[1] = 0;
			}
		return;
	}
	b = bff[depth - 1];
	if (choose[b] == 0) {
		p[depth] = b;
		choose[b] = 1;
		find(depth + 1);
		choose[b] = 0;
		p[depth] = 0;
		return;
	}
	if (bff[depth - 2] == b) {
		fill(depth);
	}
	if (bff[1] == b) {
		if (max < depth - 1)
			max = depth - 1;
		return;
	}
	
}*/

void find(int depth)
{
	if (depth > nn) {
		if (bff[p[1]] != p[2] && bff[p[1]] != p[nn])
			return;
		if (bff[p[nn]] != p[1] && bff[p[1]] != p[nn - 1])
			return;
		for (int i = 2; i < nn; i++)
			if (bff[p[i]] != p[i - 1] && bff[p[i]] != p[i + 1])
				return;
		result = depth - 1;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (choose[i] == 0) {
			p[depth] = i;
			choose[i] = 1;
			find(depth + 1);
			choose[i] = 0;
			p[depth] = 0;
		}
}

int main()
{
	int t;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	cin >> t;
	for (int times = 1; times <= t; times++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> bff[i];
		result = 0;
		memset(p, 0, sizeof(p));
		memset(choose, 0, sizeof(choose));
		for (nn = n; nn >= 1; nn--) {
			find(1);
			if (result > 0)
				break;
		}
		cout << "Case #" << times << ": " << result << endl;
	}
	return 0;
}
