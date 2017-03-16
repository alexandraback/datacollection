#include <iostream>
#include <set>

using namespace std;

int war(const set<float> &n, set<float> k)
{
	set<float>::const_iterator ni;
	for (ni = n.begin(); ni != n.end(); ni++) {
		set<float>::iterator ki = k.upper_bound(*ni);
		if (ki == k.end())		break;
		k.erase(ki);
	}
	return distance(ni, n.end());
}

int deceitfulWar(const set<float> &n, set<float> k)
{
	int win = 0;
	for (set<float>::const_iterator ni = n.begin(); ni != n.end(); ni++) {
		if (*ni < *k.begin()) {
			k.erase(std::prev(k.end()));
		} else {
			win++;
			k.erase(k.begin());
		}
	}
	return win;
}

int main(void)
{
	int T, N;
	set<float> b[2];

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		b[0].clear();
		b[1].clear();
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < N; k++) {
				float w;
				cin >> w;
				b[j].insert(w);
			}
		cout << "Case #" << i + 1 << ": " << deceitfulWar(b[0], b[1]) << ' ' << war(b[0], b[1]) << endl;
	}
	return 0;
}
