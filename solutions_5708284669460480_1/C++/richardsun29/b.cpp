#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int k, l, s;
		cin >> k >> l >> s;
		string keys, target;
		cin.ignore();
		getline(cin, keys);
		getline(cin, target);
		unordered_map<char, int> keyboard;
		for(char c = 'A'; c <= 'Z'; c++)
			keyboard[c] = 0;
		for(int j = 0; j < keys.size(); j++)
			keyboard[keys[j]]++;
		
		bool possible = true;
		for(int j = 0; j < target.size(); j++) // Keyboard incomplete
			if(keyboard[target[j]] == 0) {
				possible = false;
				break;
			}
		if(l > s) possible = false;
		
		int total = 0;
		double avg = 0;
		if(possible) {
			int overlap = 0;
			string temp = target;
			for(int j = 1; j < target.size(); j++) {
				temp = "." + temp;
				bool match = true;
				for(int a = j; a < target.size(); a++) {
					if(target[a] != temp[a]) {
						//printf("diff: %c %c\n", target[a], temp[a]);
						match = false;
						break;
					}
				}
				if(match) {
					overlap = target.size() - j;
					//cout << "set overlap" << endl;
					break;
				}
			}
			//cout << overlap << endl;
			int offset = target.size() - overlap;
			total = (s - target.size()) / offset + 1;
			//cout << total << endl;
			
			double oneword = 1.0;
			for(int j = 0; j < target.size(); j++) {
				double curr = (double)keyboard[target[j]] / k;
				//cout << curr << endl;
				oneword *= curr;
			}
			avg = oneword * (s - target.size() + 1);
		}




		//cout << keys << target << possible <<  endl;
		//cout << total << endl << avg << endl;
		printf("Case #%d: %.7g\n", i, (double)total - avg);
	}
}
