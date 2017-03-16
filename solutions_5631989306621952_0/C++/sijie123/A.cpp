#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen ("A-small-out.txt","w",stdout);
	int tc;
	cin >> tc;
	char buf;
	scanf("%c", &buf);
	for (int zz = tc; zz > 0; zz--) {
		char c;
		string s = "";
		while (1) {
			scanf("%c", &c);
			if (c == '\n') break;
			if (s.length() == 0) {
				s.insert(s.begin(), c);
			}
			else {
				char b = s.front();
				if (b > c) {
					//Append back
					s.insert(s.end(), c);
				}
				else {
					//b <= c append front
					s.insert(s.begin(), c);
				}
			}
			
		}


		printf("Case #%d: ", 101-zz);
		cout << s << "\n";
	}
}
