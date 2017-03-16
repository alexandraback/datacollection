
#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main() {
	int T = 0;
	long int N = 0;
	vector <string> words;
	ifstream infile;
	ofstream outfile;
	string line;

	infile.open("D:/GoogleCodeJam/A-small.in");
	outfile.open("D:/GoogleCodeJam/A-smallOut.txt");


	if (infile.is_open())
	{
		bool first = true;
		while (getline(infile, line))
		{
			int intVal = atoi(line.c_str());
			if (first == true) {
				T = intVal;
				first = false;
			}
			else  {
				words.push_back(line);
			}

		}
		infile.close();
	}

	else cout << "Unable to open file";

	for (int i = 0; i < words.size(); i++) {

		string word = words[i];

		int len = word.length();

		string lastWord = "";
		lastWord = word[0];
		for (int l = 1; l < len; l++) {

			if (word[l] >= lastWord[0]) {
				lastWord = word[l] + lastWord;
			}
			else {
				lastWord += word[l];
			}
		}

	outfile << "Case #" << i + 1 << ": " << lastWord << endl;


	}

	infile.close();
	outfile.close();
	_getch();
}