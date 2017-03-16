#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{	
	
	int n; 
	cin >> n;
	for (int tc = 0; tc < n; ++tc) {
		int l; cin >> l;
		vector<int> first(l, 0), second(l, 0);
		for (int lvl = 0; lvl < l; ++lvl) {
			cin >> first[lvl] >> second[lvl];			
		}
		sort(first.begin(), first.end());
		sort(second.begin(), second.end());
		int cur_stars = 0;

		int f = 0, s = 0;
		bool flag = true;
		while(cur_stars < l * 2 && flag) {
			flag = false;
			while (s < l && cur_stars >= second[s]) {
				cur_stars += 2;
				++s;
				flag = true;
			}
			while (s!= l && f < l && cur_stars >= first[f] && cur_stars < second[s]) {
				++cur_stars;
				++f;
				flag = true;
			}
		}

		cout << "Case #" << tc +1 << ": ";
		if (s == l) cout << f + s;
		else cout << "Too Bad";
		if (tc < n -1) cout << endl;
	}
}