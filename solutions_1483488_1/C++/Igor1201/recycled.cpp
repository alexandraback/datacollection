#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

string itoa2 (int number) {
   stringstream ss;
   ss << number;
   return ss.str();
}

int main () {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int a, b, y = 0;
		cin >> a >> b;

		for (int h = a; h <= b; h++) {
			string H = itoa2(h);
			list<int> foram;

			for (int i = 0; i < H.length()-1; i++) {
				H = H.insert(0, 1, H[H.length()-1]).erase(H.length(), 1);
				if (atoi(H.c_str()) <= b && atoi(H.c_str()) >= a && h < atoi(H.c_str())) {
					for (list<int>::iterator it = foram.begin(); it != foram.end(); it++) {
						if (*it == atoi(H.c_str())) { y--; break; }
					}
					foram.push_back(atoi(H.c_str()));
					y++;
				}
			}
		}

		cout << "Case #" << t+1 << ": " << y << endl;
	}

	return 0;
}