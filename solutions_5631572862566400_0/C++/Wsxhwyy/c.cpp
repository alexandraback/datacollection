#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int b[11];
int N;

int perm(int pos)  
{
	int res = 0;
	if (pos > N)
	{
		int i = 1;
		int maxvalid = 0;
		for (; i <= N; i++)
		{
			if (a[b[i]] == b[i - 1] || a[b[i]] == b[1])
				maxvalid = i;
			if (!(a[b[i]] == b[i - 1] || a[b[i]] == b[i % N + 1]))
				break;
		}
		return maxvalid;
	}
	else
	{
		for (int i = pos; i <= N; i++)
		{
			swap(b[i], b[pos]);
			res = max(res, perm(pos + 1));
			swap(b[i], b[pos]);
		}
	}
	return res;
} 

int main()
{
	int c;
	cin >> c;
	for (int cc = 1; cc <= c; cc++)
	{
		cin >> N;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= N; i++)
		{
			cin >> a[i];
			b[i] = i;
		}
		cout << "Case #" << cc << ": " << perm(1) << endl;
	}
}