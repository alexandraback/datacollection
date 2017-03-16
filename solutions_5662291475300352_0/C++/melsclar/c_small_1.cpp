#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int d[1024], h[1024], m[1024];

int main () {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int t, n;
	double pi = acos(-1);
	cin >> t;
	vector< pair<int, long double> > hikers;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		hikers.clear();
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> h[i] >> m[i];
			for (int j = 0; j < h[i]; j++) {
				long double d_rad = d[i] * 2 * pi/360.0;
				hikers.push_back(make_pair(m[i]+j, d_rad));
				//cout << "PAR " << m[i]+j << " " << d_rad << endl;
			}
		}
		sort(hikers.begin(), hikers.end());
		reverse(hikers.begin(), hikers.end());
		
		if (hikers.size() < 2) {
			cout << "Case #" << tc << ": " << 0 << endl;
			continue;
		}
		
		if (hikers[0].first == hikers[1].first) {
			// van a igual velocidad
			cout << "Case #" << tc << ": " << 0 << endl;	
			continue;
		}
		
		// ultimo tiempo a considerar
		long double ultimoTiempo = 0.0;
		for (int i = 0; i < 2; i++) {
			long double d_rad = hikers[i].second;
			ultimoTiempo = max(ultimoTiempo, (2*pi-d_rad) * hikers[i].first/(2*pi));
		}
		// aca se que van a distinta velocidad y hay 2, y el ultimo tiempo
		// que me importa mirar. Entonces me fijo si existe un choque
		// entre [0..ultimoTiempo]
		
		//long long double numer = hikers[0].second - hikers[1].second;
		//long long double denom = (2*pi)/hikers[1].first - (2*pi)/hikers[0].first;
		
		long double numer = hikers[0].second - hikers[1].second;
		long double denom = 2*pi*hikers[0].first - 2*pi*hikers[1].first;
		
		//cout << denom << " " << ultimoTiempo << endl;
		bool hayChoque = false;
		for (int k = 0; ; k++) {
			long double aux = (numer - 2*pi*k)*hikers[0].first*hikers[1].first;
			if (0.0 < aux && aux <= ultimoTiempo * denom) {
				hayChoque = true;
				break;
			}
			if (aux > ultimoTiempo * denom)
				break;
			
			aux = (numer + 2*pi*k)*hikers[0].first*hikers[1].first;
			if (0 < aux && aux <= ultimoTiempo * denom) {
				hayChoque = true;
				break;
			}
			if (aux > ultimoTiempo * denom)
				break;
		}
		
		cout << "Case #" << tc << ": " << hayChoque << endl;
	}
	return 0;
}
