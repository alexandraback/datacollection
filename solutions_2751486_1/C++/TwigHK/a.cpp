#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char ** argv){
	ifstream fin (argv[1]);

	size_t T;
	fin >> T;

	for (size_t t = 0; t!= T; t++){
		size_t n;
		string str;
		fin >> str >> n;

		const size_t L = str.size();
		const size_t numsubstrings = (L-n+1)*(1+L-n+1)/2;	
//cout << numsubstrings << endl;

		vector <size_t> vowels;
		vowels.push_back(0);
		for (int i = 0; i != L; i++)
			if 	(  str[i] == 'a'
				|| str[i] == 'e'
				|| str[i] == 'i'
				|| str[i] == 'o'
				|| str[i] == 'u'
				)
				vowels.push_back(i+1);
		vowels.push_back(L+1);
		
//for(int i = 0; i != vowels.size(); cout << vowels[i++]); cout << endl;

		size_t nosubstrings = 0;
		for (int i = 1; i < vowels.size()-1; i++){
			if (vowels[i] - vowels[i-1] > n && vowels[i+1] - vowels[i]> n){
				nosubstrings += n*(1+n)/2;
			} else {
				size_t lower = i,
				       upper = i;
				for (int j=lower; j>0 && vowels[j] - vowels[j-1] <= n; lower = --j);
				for (int j=upper; j<vowels.size()-1 && vowels[j+1] - vowels[j] <= n; upper = ++j);
//	cout << vowels[lower] << vowels[upper] << endl;
				i = upper;

				if (vowels[lower] != 0 && vowels[upper] != L+1){
					nosubstrings += (n+vowels[upper]-vowels[lower])*(1+n+vowels[upper]-vowels[lower])/2;
				} else if (vowels[lower] == 0 && vowels[upper] == L+1){
					nosubstrings = numsubstrings;
			break;
				} else if (vowels[lower] == 0) {
					nosubstrings += vowels[upper]*(1+vowels[upper])/2;
				} else if (vowels[upper] == L+1) {
					nosubstrings += (L+1-vowels[lower])*(1+L+1-vowels[lower])/2;
				}
			}
		}
		cout << "Case #" << t+1 <<": " << numsubstrings - nosubstrings << endl;
	}
	return 0;
}
