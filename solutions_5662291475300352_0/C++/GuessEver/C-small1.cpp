#include <cstdio>
#include <algorithm>

int n, d[10], h[10], m[10];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		int res = 0;
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &d[i], &h[i], &m[i]);
		if(n == 1)
		{
			if(h[1] == 1) res = 0;
			else{
				int rad = 360 - d[1];
				double t1 = 1.0 * rad / m[1];
				double t2 = 1.0 * (rad + 360) / (m[1] + 1);
				if(t1 > t2) res = 1; else res = 0;
			}
		}
		else { // n == 2
			if(m[1] == m[2]) res = 0;
			else {
				if(d[1] != d[2])
				{
					if(d[1] > d[2])
					{
						std::swap(d[1], d[2]);
						std::swap(m[1], m[2]);
					}
					double t1 = (360.0 - d[1]) / m[1];
					double t2 = (360.0 - d[2]) / m[2];
					if(t1 > t2) res = 1; else res = 0;
				}
				else {
					if(m[1] > m[2])
					{
						std::swap(d[1], d[2]);
						std::swap(m[1], m[2]);
					}
					double t1 = (360.0 - d[1]) / m[1];
					double t2 = (360.0 - d[2] + 360) / m[2];
					if(t1 > t2) res = 1; else res = 0;
				}
			}
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
