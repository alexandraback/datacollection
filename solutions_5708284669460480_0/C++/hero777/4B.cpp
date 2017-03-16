#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int T;
	ifstream input;
	ofstream output;
	input.open("a.txt");
	output.open("output.txt");
	input >> T;
	forn (i, T){
		int K, L, S;
		printf("Case #");
		printf("%d", i+1);
		printf(": ");
		output << "Case #"<< i+1 <<": ";
		input >> K >> L >> S;
		string keyboard;
		string target;
		input >> keyboard >> target;
		int  keys[26];
		forn (j, 26)
			keys[j] = 0;
		forn (j, K){
			keys[keyboard[j] - 'A'] +=1;
		}
		bool poss = true;
		//int tl = target.length();
		forn (j, L)
			if (keys[target[j] - 'A'] == 0) poss = false;
		 if (!poss) {
			printf("0.0\n");
			output << "0.0" << endl;
			continue;
		}
		double expected = 1.0;
		forn (j, L){
			//printf("%d\n", keys[target[j]-'A']);
			expected = expected * keys[target[j]-'A'];
			expected = expected/ K;
		}
		//printf("Damn\n");
		expected = expected*(S-L +1);
		//printf("WTF\n");
		int maxi = 0;
		forn (j, L-1){
			bool po = true;
			forn (k, L-j-1){
				if( target[j+k+1] != target [k]) po = false;
			}
			if (po) {
				maxi = L-j-1;
				break;
			}
		}
		//printf("%d\n",maxi);
		int maxim = 1 + (S-L)/(L-maxi);
		//printf("%d\n",maxim);
		expected = maxim - expected;
		printf("%0.9f\n", expected);
		//printf("Last\n");
		output << expected << endl;
		//printf("%s\n", keyboard.c_str());
		//printf("%s\n", target.c_str());

	}
}
