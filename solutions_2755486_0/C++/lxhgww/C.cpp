#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1000;

struct Attack
{
	int d, w, e, s;
	Attack(){}
	Attack(int _d, int _w, int _e, int _s)
	{
		d = _d;
		w = _w;
		e = _e;
		s = _s;
	}
	bool operator <(const Attack& b) const
	{
		return d < b.d;
	}
};

Attack a[MAXN];
int n;
map<int, int> snow, anow;

int main()
{
	int totCas;
	cin >> totCas;
	for (int cas = 1; cas <= totCas; cas++)
	{
		cin >> n;
		int totA = 0;
		for (int i = 0; i < n; i++)
		{
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
			wi *= 2;
			ei *= 2;
			delta_pi *= 2;
			for (int j = 0; j < ni; j++)
				a[totA++] = Attack(di + j * delta_di, 
						wi + j * delta_pi, 
						ei + j * delta_pi, 
						si + j * delta_si);
		}
		sort(a, a + totA);
		snow.clear();
		anow.clear();
		int ans = 0;
		for (int i = 0; i < totA; i++)
		{
//			printf("d = %d, w = %d, e = %d, s = %d\n", a[i].d, a[i].w, a[i].e, a[i].s);
			if (i > 0 && a[i].d != a[i - 1].d)
			{
				for (map<int, int>::iterator it = anow.begin(); it != anow.end(); it++)
					snow[it->first] = max(snow[it->first], it->second);
			}
			bool flag = false;
			for (int j = a[i].w; j <= a[i].e; j++)
			{
				if (a[i].s > snow[j])
					flag = true;
				anow[j] = max(anow[j], a[i].s);
			}
			if (flag)
				ans++;
//			printf("ans = %d\n", ans);
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}

