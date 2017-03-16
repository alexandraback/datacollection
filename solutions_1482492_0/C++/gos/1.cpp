#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int N, A, T, tmp, tmp2;
double D, ar[255];
double ti[2005], xi[2005];
double v0, t, ans, a, s;
double solve(double a, double b, double c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}
int main()
{
	freopen("e:\\B-small-attempt3.in", "r", stdin);
	freopen("e:\\B-small-attempt3.out", "w", stdout);
	cin >> T;
	for(int Tidx = 1; Tidx <= T; Tidx++)
	{
		cin >> D >> N >> A;
		//printf("%lf %d %d\n", D, N, A);
		ti[0] = xi[0] = 0;
		for(int i = 1; i <= N; i++)
		{
			cin >> ti[i] >> xi[i];
			//printf("%lf %lf\n", ti[i], xi[i]);
		}
		for(int i = 1; i <= N; i++)
		{
			if(i > 1 && xi[i] >= D)
			{
				ti[i] = ti[i - 1] + (D - xi[i - 1]) / ((xi[i] - xi[i - 1]) / (ti[i] - ti[i - 1]));
				xi[i] = D;
				N = i;
				break;
			}
		}
		for(int i = 0; i < A; i++)
		{
			cin >> ar[i];
			//printf("%lf\n", ar[i]);
		}
		cout << "Case #" << Tidx << ":" << endl; 
		for(int i = 0; i < A; i++)
		{
			ans = 0;
			v0 = 0;
			t = 0;
			a = ar[i];
			for(int j = 1; j <= N; j++)
			{
				s = xi[j] - xi[j - 1];
				t = solve(a / 2, v0, -s);
				if(ans + t >= ti[j])
				{
					ans += t;
					v0 = v0 + t * a;
					//cout << "1: " << t << endl;
				}
				else
				{
					t = ti[j] - ans;
					ans = ti[j];
					if(a / 2 * t * t >= s)
						v0 = sqrt(2 * a * s);
					else
					{
						v0 = (s - a / 2 * t * t) / t;
						v0 = v0 + a * t;
					}
				}
				if(xi[j] >= D)
					break;
			}
			cout << fixed << setprecision(7) << ans << endl;
		}
	}
	return 0;
}

