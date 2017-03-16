#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int T, N;
	cin >> T;
	for (int t = 0; t != T; ++t) {
		list<pair<int, int> > v;
		list<pair<int, int> > v1;
		cin >> N;
		for (int n = 0; n != N; ++n) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		int st = 0;
		int lv = 0;
		while (!v.empty() || !v1.empty()) {
			for (list<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it) {
				if (it->second <= st) {
					st += 2;
					lv += 1;
					v.erase(it);
					goto __LOOP;
				}
			}
			for (list<pair<int, int> >::iterator it = v1.begin(); it != v1.end(); ++it) {
				if (it->second <= st) {
					st += 1;
					lv += 1;
					v1.erase(it);
					goto __LOOP;
				}
			}
			{
				list<pair<int, int> >::iterator it1 = v.end();
				for (list<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it) {
					if (it->first <= st) {
						if (it1 == v.end()) {
							it1 = it;
						}
						else {
							if (it1->second < it->second)
								it1 = it;
						}
					}
				}
				if (it1 != v.end()) {
					st += 1;
					lv += 1;
					v1.push_back(*it1);
					v.erase(it1);
					goto __LOOP;
				}
				break;
			}
__LOOP: {}
		}

		if (v.empty() && v1.empty()) {
			cout << "Case #" << (t + 1) << ": " << lv << endl;
		}
		else {
			cout << "Case #" << (t + 1) << ": Too Bad" << endl;
		}
	}
	return 0;
}
