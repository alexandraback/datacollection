#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef long long int tint;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

vector<char> word;
int n;

int main(){
	freopen("alarge.in","r",stdin);
	freopen("alarge.out","w",stdout);
	int T;
	scanf("%d",&T);
	scanf("\n");
	forn(casos, T) {
		word.clear();
		char c;
		while (scanf("%c", &c) && c != ' ') {
			word.push_back(c);
		}
		scanf("%d\n", &n);
		int left = 0;
		int right = 0;
		int value = 0;
		int size = word.size();
		int lastGoodOne = -1;
		tint total = 0;
		//forn(i, size) cout << word[i];
		//cout << endl;
		for(;left < size;left++) {
			if (left > right) right = left;
			while (right < size && !isVowel(word[right])) {
				value++;
				right++;
			}
			//cout << left << ' ' << right << ' ' << value << endl;
			if (value >= n) {
				//cout << left << ' ' << right << endl;
				//cout << size - (left + n) + 1 << endl;
				total += ((tint)((left + 1) - (lastGoodOne + 1))) * (size - (left + n) + 1);
				lastGoodOne = left;
			}
			if (right > left) {
				value -= !isVowel(word[left]);
			}
		}
		cout << "Case #" << casos + 1 << ": " << total << endl;
	}
}
