#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(int argc, char* argv[])
{
	ifstream in("A-large.in");
	ofstream out("out.txt");
	int t;
	in >> t;
	for (int c=1; c<=t; c++) {
		string w; int n;
		in >> w >> n;
		int curr(0); int last = 0; int total = 0;
		for (int i(0); i < w.length(); ++i) {
			if (i >= n && !vowel(w[i-n])) curr--;
			if (!vowel(w[i])) curr++;
			if (curr == n) {
				total += ((i-n+1)-(last)+1)*(w.length()-i);
				last = i-n+2;
			}
		}

		out << "Case #" << c << ": " << total << endl;
		
		

	}

}//main