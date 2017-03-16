#include <iostream>
#include <vector>

using namespace std;

vector <int> noms;

bool check(vector <int> two, int v) {
	vector <bool> can(v + 1, false);
	can[0] = true;
	int used = 0;
	for (auto now : noms)
		for (int j = v - now; j >= 0; j--)
			if (can[j] && !(can[j + now])) {
				can[j + now] = true;
				used++;
			}
	for (auto now : two)
		for (int j = v - now; j >= 0; j--)
			if (can[j] && !(can[j + now])) {
				can[j + now] = true;
				used++;
			}
	return used == v;
}

bool isin(int nom) {
	for (int i = 0; i < noms.size(); i++)
		if (nom == noms[i])
			return true;
	return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int c, d, v;
		cin >> c >> d >> v;
		int ans = 5;
		noms.clear();
		for (int j = 0; j < d; j++) {
			int tmp;
			cin >> tmp;
			noms.push_back(tmp);
		}
		vector <int> two;
		if (check(two, v))
			ans = 0;
		if (ans == 5)
			for (int i1 = 1; i1 <= v; i1++)
				if (!isin(i1))
					if (check(vector < int > {i1}, v))
						ans = 1;
		if (ans == 5)
			for (int i1 = 1; i1 <= v; i1++)
				for (int i2 = i1 + 1; i2 <= v; i2++)
					if (!isin(i1) && !isin(i2))
						if (check(vector < int > {i1, i2}, v))
							ans = 2;
		if (ans == 5)
			for (int i1 = 1; i1 <= v; i1++)
				for (int i2 = i1 + 1; i2 <= v; i2++)
					for (int i3 = i2 + 1; i3 <= v; i3++)
						if (!isin(i1) && !isin(i2) && !isin(i3))
							if (check(vector < int > {i1, i2, i3}, v))
								ans = 3;
		if (ans == 5)
			for (int i1 = 1; i1 <= v; i1++)
				for (int i2 = i1 + 1; i2 <= v; i2++)
					for (int i3 = i2 + 1; i3 <= v; i3++)
						for (int i4 = i3 + 1; i4 <= v; i4++)
							if (!isin(i1) && !isin(i2) && !isin(i3) && !isin(i3))
							if (check(vector < int > {i1, i2, i3, i4}, v))
								ans = 4;
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}