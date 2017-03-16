#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	const char code[] = "yhesocvxduiglbkrztnwjpfmaq";
	int T;
	char G[101];
	
	cin >> T;
	cin.getline(G, 101);
	for(int tno = 0; tno < T; tno++) {
		cin.getline(G, 101);
		cout << "Case #" << (tno + 1) << ": ";
		for(char* p = G; *p != '\0'; p++) {
			if(*p == ' ')
				cout.put(' ');
			else
				cout.put(code[(*p) - 'a']);
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}
