#include <iostream>
#include <string> 
using namespace std;

char ch;
int n, N;

//char google[30] = "ynficwlbkuomxsevzpdrjgthaq";
char google[30] = "yhesocvxduiglbkrztnwjpfmaq";
string s;

int main() {
	cin >> N;
	getline(cin,s);
	cin >> noskipws;
	for (int i=0; i<N; ++i) {
		cout << "Case #" << (i+1) << ": ";
		getline(cin,s);
		for (int j=0; j < s.length(); ++j){
			ch = s[j];
			n = int(ch);
			if (n >= 97 && n <= 122)
			{
				n -= int('a');
				ch = google[n];
				cout << ch;
			}
			else
				cout << ch;
		}
		cout << endl;
	}
}
