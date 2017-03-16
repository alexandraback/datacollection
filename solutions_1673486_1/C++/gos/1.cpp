#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
int T, Tidx = 1;
int arr[100000];
double pos[1000000], ans, t1, t2;
double flag[1000000];
int A, B;
int main()
{
	freopen("e:\\A-large.in", "r", stdin);
	freopen("e:\\A-large.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> A >> B;
		for(int i = 0; i < A; i++)
		{
			cin >> pos[i];
			if(i)
				flag[i] = flag[i - 1] * pos[i];
			else
				flag[i] = pos[i];
		}
		ans = 2 + B;
		for(int i = 0; i <= A; i++)
		{
			t1 = 1;
			if(i < A)
				t1 = flag[A - i - 1];
			t2 = t1 * (B - A + 1 + 2 * i) + (1 - t1) * (B - A + 1 + 2 * i + B + 1);
			if(t2 < ans)
				ans = t2;
		}
		cout << "Case #" << Tidx++ << ": ";
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}