#include <string>
#include <sstream>
#include <iostream>

using namespace std;

char ALFA[26] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };

int main () {
	int T;
	cin >> T;

	string h;
	getline(cin, h);

	for (int t = 0; t < T; t++) {
		string G, final;
		getline(cin, G);

		for (int i = 0; i < G.length(); i++) {
			if (G[i] == ' ') final.append(" ");
			else final.append(1, ALFA[G[i]-97]);
		}

		cout << "Case #" << t+1 << ": " << final << endl;
	}

	return 0;
}