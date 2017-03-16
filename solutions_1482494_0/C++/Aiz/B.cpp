#include <iostream>
#include <algorithm>

using namespace std;

int a[101], b[101];
int ind1[101], ind2[101];
int used[1010];

int main()
{
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
			used[i] = 0;
		}
		int i = 0, j = 0, cnt = 0, res=0;
		while (cnt < 2 * n)
		{
			int j = -1;
			for (int i = 0; i < n; i++)
			{
				if (b[i] <= cnt && used[i] < 2)
				{
					j = i;
					break;
				}
			}
			if (j >= 0)
			{
				cnt += 2 - used[j];
				res++;
				used[j] = 2;
				continue;
			}
			j = -1;
			for (int i = 0; i < n; i++)
			{
				if (a[i] <= cnt && used[i] < 1)
				{
					if (j < 0 || b[i] > b[j])
						j = i;
				}
			}
			if (j >= 0)
			{
				cnt++;
				res++;
				used[j] = 1;
				continue;
			}
			break;
		}
		if (cnt == 2 * n)
			cout << res;
		else cout << "Too Bad";
    cout << endl;
  }
  return 0;
}