#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

#define cin fin
#define cout fout
ifstream fin("A-large.in");
ofstream fout("A-large.out");

const long long MAXN = 1000001;
char str[MAXN];
long long len;
long long cont;

long long startx[MAXN], endx[MAXN];
long long nPairs;

char vowels[] = "aeiou";

bool isVowel(char c) {
	for (long long i = 0; vowels[i]; i++)
		if (vowels[i] == c)
			return true;

	return false;
}

void getPairs() {
	len = strlen(str);
	nPairs = 0;

	long long index1 = -1, index;

	while (true) {
		index = index1 + 1;
		while (index < len && isVowel(str[index]))
			index++;

		if (index >= len)
			return;

		index1 = index + 1;
		while (index1 < len && !isVowel(str[index1]))
			index1++;

		if (index1 - index >= cont) {
			startx[nPairs] = index;
			endx[nPairs] = index1 - 1;
			nPairs++;
		}
	}
}

long long getResult() {
	getPairs();

	long long result = 0;
	long long curr = 0;
	
	for (long long i = 0; i < nPairs; i++) {
		result += (startx[i] - curr) * (len - startx[i] - cont + 1);

		curr = startx[i];
		while (curr + cont - 1 <= endx[i]) {
			result += len - curr - cont + 1;
			curr++;
		}
	}

	return result;
}

int main() {
	long long nCases;
	cin >> nCases;

	for (long long cnt = 1; cnt <= nCases; cnt++) {
		cin >> str >> cont;

		cout << "Case #" << cnt << ": " << getResult() << endl;
	}
}
