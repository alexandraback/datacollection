#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cs;
	cin >> cs;
	for (int cc = 1; cc <= cs; cc++) {
		int c, d, v;
		cin >> c >> d >> v;
		vector<int> b(d);
		for (int i = 0; i < d; i++)
			cin >> b[i];
		vector<bool> p(v + 1);
		p[0] = true;
		for (int i = 0; i < d; i++)
			for (int j = v; j >= 0; j--)
				if (p[j] && b[i] + j <= v)
					p[j + b[i]] = true;
		vector<int> bag;
		for (int i = 0; i <= v; i++)
			if (!p[i]) {
				bag.push_back(i);
				for (int j = v; j >= 0; j--)
					if (p[j] && i + j <= v)
						p[i + j] = true;
			}
		cout << "Case #" << cc << ": " << bag.size() << "\n";
	}
}
