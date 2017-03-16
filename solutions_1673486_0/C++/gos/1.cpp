#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
int T, Tidx = 1;
int arr[5];
double pos[5], ans, t1, t2;
int A, B;
int flag[32] = {1, 2, 4, 8};
int main()
{
	freopen("e:\\A-small-attempt0.in", "r", stdin);
	freopen("e:\\A-small-attempt0.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> A >> B;
		for(int i = 0; i < A; i++)
			cin >> pos[i];
		ans = 2 + B;
		for(int i = 0; i <= A; i++)
		{
			t1 = 1;
			for(int j = 0; j < A - i; j++)
			{
				t1 *= pos[j];
			}
			t2 = t1 * (B - A + 1 + 2 * i) + (1 - t1) * (B - A + 1 + 2 * i + B + 1);
			if(t2 < ans)
				ans = t2;
		}
		cout << "Case #" << Tidx++ << ": ";
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}