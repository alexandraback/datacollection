#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int freq[10];

int main(int argc, char* argv[]){
	int T,nocase;
	int i,j;
	string S;
	char buf[1024];
	int len;

	int cfreq[32];

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	//T = 5;
	getline(cin,S);
	for (nocase = 1; nocase <= T; ++nocase) {
		for(i=0;i<10;i++) freq[i] = 0;
		for(i=0;i<32;i++) cfreq[i] = 0;
		getline(cin,S);
		//cout << S << endl;
		sort(S.begin(),S.end());
		for(i=0;i<S.length();i++) cfreq[S[i]-'A']++;

		//for(i=0;i<26;i++) printf("%c: %d\n",'A'+i,cfreq[i]);
		
		//ZERO
		freq[0] = cfreq['Z'-'A'];
		cfreq['Z'-'A'] = freq[0];
		cfreq['E'-'A'] -= freq[0];
		cfreq['R'-'A'] -= freq[0];
		cfreq['0'-'A'] -= freq[0];

		//SIX
		freq[6] = cfreq['X'-'A'];
		cfreq['S'-'A'] -= freq[6];
		cfreq['I'-'A'] -= freq[6];
		cfreq['X'-'A'] -= freq[6];

		//EIGHT
		freq[8] = cfreq['G'-'A'];
		cfreq['E'-'A'] -= freq[8];
		cfreq['I'-'A'] -= freq[8];
		cfreq['G'-'A'] -= freq[8];
		cfreq['H'-'A'] -= freq[8];
		cfreq['T'-'A'] -= freq[8];

		//TWO
		freq[2] = cfreq['W'-'A'];
		cfreq['T'-'A'] -= freq[2];
		cfreq['W'-'A'] -= freq[2];
		cfreq['O'-'A'] -= freq[2];

		//FOUR
		freq[4] = cfreq['U'-'A'];
		cfreq['F'-'A'] -= freq[4];
		cfreq['O'-'A'] -= freq[4];
		cfreq['U'-'A'] -= freq[4];
		cfreq['R'-'A'] -= freq[4];
		
		//FIVE
		freq[5] = cfreq['F'-'A'];
		cfreq['F'-'A'] -= freq[5];
		cfreq['I'-'A'] -= freq[5];
		cfreq['V'-'A'] -= freq[5];
		cfreq['E'-'A'] -= freq[5];

		//SEVEN
		freq[7] = cfreq['V'-'A'];
		cfreq['S'-'A'] -= freq[7];
		cfreq['E'-'A'] -= freq[7];
		cfreq['V'-'A'] -= freq[7];
		cfreq['E'-'A'] -= freq[7];
		cfreq['N'-'A'] -= freq[7];

		//THREE
		freq[3] = cfreq['R'-'A'];
		cfreq['T'-'A'] -= freq[3];
		cfreq['H'-'A'] -= freq[3];
		cfreq['R'-'A'] -= freq[3];
		cfreq['E'-'A'] -= freq[3];
		cfreq['E'-'A'] -= freq[3];

		//ONE = O
		freq[1] =cfreq['O'-'A'];
		//NINE = I
		freq[9] =cfreq['I'-'A'];

		//for(i=0;i<10;i++) printf("%d: %d\n",i,freq[i]);
		//for(i=0;i<26;i++) printf("%c: %d\n",'A'+i,cfreq[i]);

		cout << "Case #" << nocase << ": ";
		for(i=0;i<10;i++){
			for(j=0;j<freq[i];j++) cout << i;
		}
		cout<<endl;
	}

	return 0;
}