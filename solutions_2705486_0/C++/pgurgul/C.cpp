#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define L 4005
#define MAX_CHANGES 10000000
using namespace std;
vector<string> words;

int changes[L];

int count_changes(const string & word, const string & S, int offset) {
	int last_diff = -1000;
	int changes = 0;
	for (int i = 0; i < word.size(); ++ i) {
		if (word[i] != S[i + offset]) {
			if (i - last_diff < 5) {
				return -1;
			} else {
				last_diff = i;
				++ changes;
			}
		}
	}
//	if (changes == 0) {
//		cout << word << endl;
//	}
	return changes;
}
int main() {

	string line;
    ifstream myfile ("garbled_email_dictionary.txt");
    if (myfile.is_open()) {
		 while ( myfile.good() ) {
			  getline (myfile,line);
			  if (line != "")
				  words.push_back(line);
		 }
		 myfile.close();						
	}
//	cout << words.size() << endl;

	int cases;
	cin >> cases;

	string S;
	for(int z = 1; z <= cases; ++ z) {
		for (int i = 0; i < L; ++ i) {
			changes[i] = MAX_CHANGES;
		}
		cin >> S;
		changes[0] = 0;
		for (int i = 0; i < S.size(); ++ i) {
			if (changes[i] < MAX_CHANGES) {
				for (int j = 0; j < words.size(); ++ j) {
					if (i + words[j].size() <= S.size()) {
						int k = count_changes(words[j], S, i);
				
						if (k != -1 && changes[i] + k < changes[i + words[j].size()]) {
							changes[i + words[j].size()] = changes[i] + k;
						}
					}
				}
			}
		}
//		for (int i = 0; i < S.size(); ++ i) {
//			cout << changes[i] << " ";
//		}
//		cout << endl;
		cout << "Case #" << z << ": " << changes[S.size()] << endl;

	}
								    
	return 0;
}
