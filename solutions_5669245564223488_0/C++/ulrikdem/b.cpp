#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Set {
	char first, last;
	bool connected = false;
};

struct Letter {
	int first = -1, last = -1, connected = 0;
	bool used = false;
};

long long factorial(long long number) {
	long long answer = 1;
	while(number > 1) {
		answer = answer * number % 1000000007;
		--number;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int count;
		cin >> count;
		vector<Set> sets(count);
		vector<bool> middle(26);
		bool valid = true;
		for(Set& set : sets) {
			string letters;
			cin >> letters;
			set.first = letters[0];
			set.last = *letters.rbegin();
			if(middle[set.first - 'a'] || middle[set.last - 'a']) {
				valid = false;
				break;
			}
			while(*letters.rbegin() == set.last) {
				letters.pop_back();
			}
			if(set.first == set.last) {
				if(letters.empty()) {
					set.connected = true;
				} else {
					valid = false;
					break;
				}
			}
			for(int index = 1; index < letters.size(); ++index) {
				if(letters[index] == letters[index - 1]) {
					continue;
				}
				if(middle[letters[index] - 'a']) {
					valid = false;
					break;
				}
				middle[letters[index] - 'a'] = true;
			}
			if(!valid) {
				break;
			}
		}
		if(!valid) {
			cout << "Case #" << test << ": 0\n";
			continue;
		}
		vector<Letter> letters(26);
		for(int index = 0; index < count; ++index) {
			if(sets[index].connected) {
				++letters[sets[index].first - 'a'].connected;
				continue;
			}
			if(letters[sets[index].first - 'a'].last >= 0) {
				valid = false;
				break;
			}
			letters[sets[index].first - 'a'].last = index;
			if(letters[sets[index].last - 'a'].first >= 0) {
				valid = false;
				break;
			}
			letters[sets[index].last - 'a'].first = index;
		}
		if(!valid) {
			cout << "Case #" << test << ": 0\n";
			continue;
		}
		long long answer = 0;
		for(int index = 0; index < 26; ++index) {
			if(!letters[index].used && (letters[index].first >= 0 || letters[index].last >= 0 || letters[index].connected)) {
				letters[index].used = true;
				++answer;
				int previous = index;
				while(letters[previous].first >= 0) {
					previous = sets[letters[previous].first].first - 'a';
					if(letters[previous].used) {
						valid = false;
						break;
					}
					letters[previous].used = true;
				}
				if(!valid) {
					break;
				}
				int next = index;
				while(letters[next].last >= 0) {
					next = sets[letters[next].last].last - 'a';
					if(letters[next].used) {
						valid = false;
						break;
					}
					letters[next].used = true;
				}
				if(!valid) {
					break;
				}
			}
		}
		if(!valid || answer == 0) {
			cout << "Case #" << test << ": 0\n";
			continue;
		}
		answer = factorial(answer);
		for(Letter& letter : letters) {
			answer = answer * factorial(letter.connected) % 1000000007;
		}
		cout << "Case #" << test << ": " << answer << '\n';
	}
	return 0;
}
