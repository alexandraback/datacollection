#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char * const argv[]) {
	string input1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string input2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string input3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	string output1 = "our language is impossible to understand";
	string output2 = "there are twenty six factorial possibilities";
	string output3 = "so it is okay if you want to just give up";
	
	char translation[26];
	int asciiA = (int)'a';
	
	translation[asciiA - asciiA] = 'y';
	translation[(int)'o' - asciiA] = 'e';
	translation[(int)'z' - asciiA] = 'q';
	
	// process the sample and produce the complete translation
	for (int i = 0; i < input1.size(); i++) {
		translation[(int)input1.at(i) - asciiA] = output1.at(i);
	}
	for (int i = 0; i < input2.size(); i++) {
		translation[(int)input2.at(i) - asciiA] = output2.at(i);
	}
	for (int i = 0; i < input3.size(); i++) {
		translation[(int)input3.at(i) - asciiA] = output3.at(i);
	}
	
	// go through the translation to see if there is any missing letter
	for (int i = 0; i < 26; i++) {
		if (translation[i] == '\0') {
			// check which letter is not yet used
			for (char test = 'a'; test <= 'z'; test++) {
				bool used = false;
				for (int j = 0; j < 26; j++) {
					if (test == translation[j]) {
						used = true;
						break;
					}
				}				
				
				if (!used) {
					translation[i] = test;
					break;
				}
			}
			
			break;
		}
	}
	
	// output the translation
	cout << "Translation: " << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(asciiA + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < 26; i++) {
		if (translation[i] == '\0') {
			cout << "? ";
			continue;
		}
		cout << translation[i] << " ";
	}
	cout << endl;
	
//	ifstream in("..//..//sample.in.txt");
	ifstream in("..//..//A-small-attempt0.in.txt");
	
	if(!in) {
		cout << "Input file cannot be opened";
		return 1;
	}
	
	ofstream out("output.txt");
	if (!out) {
		cout << "Output file cannot be opened";
		in.close();
		return 1;
	}
	
	int T;
	in >> T;
	string line;
	getline(in, line);
	
	for (int t = 0; t < T; t++) {		
		getline(in, line);
		
		// read each character
		for (int l = 0; l < line.size(); l++) {
			line[l] = translation[(int)line[l] - asciiA];
		}
		
		out << "Case #" << (t + 1) << ": " << line << endl;
	}
	
	in.close();
	out.close();

    return 0;
}
