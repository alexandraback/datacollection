#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<int> letter(26, 0);
vector<int> digit(10, 0);


int f(int d, string s, char c) {
	digit[d] = letter[alp.find(c)];
	for (int i = 0; i < s.length(); i++) {
		letter[alp.find(s[i])] -= digit[d];
	}
	return digit[d];
}

int T;
int main() {		
	fin >> T;
	cout << T << endl;

	for (int t = 1; t <= T;t++) {
		string s;
		fin >> s;
		//string s = "WEIGHFOXTOURIST";

		for (int i = 0; i < s.length(); i++) {
			letter[alp.find(s[i])]++;
		}

		for (int i = 0; i < 26; i++)
			cout << alp[i] << ":\t" << letter[i] << endl;
		cout << endl;

		f(0, "ZERO", 'Z');
		f(2, "TWO", 'W');
		f(4, "FOUR", 'U');
		f(6, "SIX", 'X');
		f(5, "FIVE", 'F');
		f(7, "SEVEN", 'V');
		f(8, "EIGHT", 'G');
		f(3, "THREE", 'T');
		f(1, "ONE", 'O');
		f(9, "NINE", 'E');

		for (int i = 0; i < 26; i++)
			cout << alp[i] << ":\t" << letter[i] << endl;
		cout << endl;

		string u = "";
		for (int i = 0; i < 10; i++) {
			cout << i << ":\t" << digit[i] << endl;
			for (int j = 0; j < digit[i]; j++)
				u += to_string(i);
		}

		cout << u << endl;
		fout << "Case #" << t << ": " << u << endl;
	}
}