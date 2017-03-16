// a.cpp
//

#include <iostream>
#include <string>
using namespace std;

const int MAX_L = 100;
const string v = "aeiou";

int main()
{
	int T, n;
	string name;
	int ans;

	cin >> T;
	for (int t = 1 ; t <= T ; t++) {
		if (t > 1)
			getchar();
		cin >> name;
		cin >> n;
		ans  = 0;
		
		int len = name.length();
		for (int l = n ; l <= len  ; l++) {
			for (int b = 0 ; b+l <= len ; b++) {
				string sub = name.substr(b, l);

				for (int s = 0 ; s+n <= l ; s++) {
					string sub2 = sub.substr(s, n);
					bool able = true;
					for (int i = 0 ; i < n ; i++) {
						for (int j = 0 ; j < v.length() ; j++) {
							if (sub2[i] == v[j]) {
								able = false;
								break;
							}
						}
					}
					if (able) {
						ans++;
						break;
					}
				}
			}
		}
		
		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}