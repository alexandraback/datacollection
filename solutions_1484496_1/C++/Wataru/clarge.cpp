#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;


long long a[501];
int n;



int pack(int a, int b, int c)
{
	return (a << 18) | (b << 9) | c;
}

void unpack(int x, int &a, int &b, int &c) 
{
	a = x >> 18;
	b = (x >> 9) & 511;
	c = x & 511;
}

map <long long, int> was;


void Solve()
{                     
	cin >> n;

	int i;
	
	for (i = 1; i <= n; i++)
		cin >> a[i];

	sort(a, a + n);
	int q, w, e;
	was.clear();
	for (q = 1; q <= n; q++) {
		for (w = q+1; w <= n; w++) {
			for (e = w+1; e <= n; e++) {
				long long sum = a[q] + a[w] + a[e];
				int m = pack(q,w,e);
				if (was.find(sum) != was.end()) {
					int z,x,c;
					unpack(was[sum], z, x, c);
					cout << a[q] << ' ' << a[w] << ' ' << a[e] << "\n";
					cout << a[z] << ' ' << a[x] << ' ' << a[c] << "\n";
					return;
				}
				was[sum] = m;
			}
		}
	}

	vector<bool> ws(512);

	while (true) {
		vector <int> cur;
		long long sum = 0;
		while (cur.size() < 6) {
			i = rand() % n;
			if (ws[i]) continue;
			ws[i] = true;
			cur.push_back(i);
			sum += a[i+1];
		}

		for (q = 1; q <= n; q++) {
			for (w = q+1; w <= n; w++) {
				for (e = w+1; e <= n; e++) {
					if (ws[q-1] && ws[w-1] && ws[e-1]) continue;
					long long sum2 = sum - a[q] - a[w] - a[e];
					if (sum2 < 0) continue;
					if (was.find(sum2) != was.end()) {
						int z,x,c;
						unpack(was[sum2], z, x, c);
						if (z == q || z == w || z == e) continue;
						if (x == q || x == w || x == e) continue;
						if (c == q || c == w || c == e) continue;
						cout << a[q] << ' ' << a[w] << ' ' << a[e] << " ";
						cout << a[z] << ' ' << a[x] << ' ' << a[c] << "\n";
						long long s1 = a[q] + a[w] + a[e] + a[z] + a[x] + a[c];
						long long s2 = 0;
						for (i = 0; i < (int)cur.size(); i++) {
							cout << a[cur[i]+1] << ' ';
							s2 += a[i+1];
						}
						cout << "\n";
						if (s1 != s2) cerr << "botva\n";
						return;
					}
				}
			}
		}	

		for (i = 0; i < (int)cur.size(); i++) {
			ws[cur[i]] = false;
		}

	}

   	cout << "Impossible\n";

}

int main()
{
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ":\n";
		Solve(); 
	}
	return 0;
}
