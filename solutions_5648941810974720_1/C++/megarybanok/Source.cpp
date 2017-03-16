#include <iostream>
#include <vector>
#include <string>

using namespace std;


void main() {

	FILE *str, *abc;
	freopen_s(&str, "input.txt", "r", stdin);
	freopen_s(&abc, "out.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int tt = 0; tt < t; tt++) {
		cout << "Case #" << tt + 1 << ": ";
		
		string s;
		cin >> s;

		int a0=0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;
		vector <int> ss(1000, 0);


		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'Z') a0++;
			if (s[i] == 'W') a2++;
			if (s[i] == 'U') a4++;
			if (s[i] == 'X') a6++;
			if (s[i] == 'G') a8++;

			ss[(int)s[i]]++;
		}
		
		ss[(int)'Z'] -= a0; ss[(int)'E'] -= a0; ss[(int)'R'] -= a0; ss[(int)'O'] -= a0;
		ss[(int)'T'] -= a2; ss[(int)'W'] -= a2; ss[(int)'O'] -= a2;
		ss[(int)'F'] -= a4; ss[(int)'O'] -= a4; ss[(int)'U'] -= a4; ss[(int)'R'] -= a4;
		//ss[(int)'F'] -= a5; ss[(int)'I'] -= a5; ss[(int)'V'] -= a5; ss[(int)'E'] -= a5;
		ss[(int)'S'] -= a6; ss[(int)'I'] -= a6; ss[(int)'X'] -= a6;
		ss[(int)'E'] -= a8; ss[(int)'I'] -= a8; ss[(int)'G'] -= a8; ss[(int)'H'] -= a8; ss[(int)'T'] -= a8;

		a5 = ss[(int)'F'];
		ss[(int)'F'] -= a5; ss[(int)'I'] -= a5; ss[(int)'V'] -= a5; ss[(int)'E'] -= a5;

		a9 = ss[(int)'I']; 
		ss[(int)'N'] -= a9; ss[(int)'I'] -= a9; ss[(int)'N'] -= a9; ss[(int)'E'] -= a9;

		a3 = ss[(int)'R'];
		ss[(int)'T'] -= a3; ss[(int)'H'] -= a3; ss[(int)'R'] -= a3; ss[(int)'E'] -= a3; ss[(int)'E'] -= a3;

		a7 = ss[(int)'S'];
		ss[(int)'S'] -= a7; ss[(int)'E'] -= a7; ss[(int)'V'] -= a7; ss[(int)'E'] -= a7; ss[(int)'N'] -= a7;

		a1 = ss[(int)'O'];
		

		for (int i = 0; i < a0; i++) cout << 0;
		for (int i = 0; i < a1; i++) cout << 1;
		for (int i = 0; i < a2; i++) cout << 2;
		for (int i = 0; i < a3; i++) cout << 3;
		for (int i = 0; i < a4; i++) cout << 4;
		for (int i = 0; i < a5; i++) cout << 5;
		for (int i = 0; i < a6; i++) cout << 6;
		for (int i = 0; i < a7; i++) cout << 7;
		for (int i = 0; i < a8; i++) cout << 8;
		for (int i = 0; i < a9; i++) cout << 9;
		cout << endl;
	}
		
}