#include<iostream>

using namespace std;

const unsigned SAMPLENUM = 3;
const unsigned LETTERS = 26;

string sampleIn[3] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

string sampleOut[3] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

// rules[char1 - 97] = char2
// where char1 in Googlerese and char2 is it's English counterpart
char rules[LETTERS] = { 0 };


void addRule(char from, char to) {
	// check for errors!
	if (rules[from-97] != 0) {
		if (rules[from-97] != to)
			cout << "PROBLEMO!" << endl;
	} else {
		// just set it
		rules[from-97] = to;
	}
}


void transform(string & line) {
	for (unsigned k = 0; k < line.length(); ++k) {
		if (rules[line[k]-97] == 0) {
			cout << "I DON'T KNOW WHAT TO DO!" << endl;
		}
		line[k] = rules[line[k]-97];
	}
}

int main() {
	
	// given
	addRule('y', 'a');
	addRule('e', 'o');
	addRule('q', 'z');
// from input
	addRule('z', 'q');
		
	// now fill up the rest based on each sample
	for (unsigned i = 0; i < 3; ++i) {
		for (unsigned k = 0; k < sampleIn[i].length(); ++k) {
			addRule(sampleIn[i][k], sampleOut[i][k]);
		}
	}
	
	// now handle actual input
	unsigned cases;
	cin >> cases;
	string line;
	getline(cin, line); // finish the line with cases in it
	for (unsigned c = 0; c < cases; ++c) {
		getline(cin, line);
		transform(line);
		cout << "Case #" << c+1 << ": " << line;
		if (c != cases - 1)
			cout << endl;
	}
	
	return 0;
}

