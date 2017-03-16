#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void add(std::string &a, std::string &b){
	int more = 0;
	for (int i = 0; i < a.size() || i < b.size(); ++i) {
		int na = (i < a.size()) ? a[i] - '0' : 0;
		int nb = (i < b.size()) ? b[i] - '0' : 0;
		int result = na + nb + more;
		a[i] = (result % 10) + '0';
		more = (result) / 10;
	}
	if (more) {
		a += ((more + '0'));
	}
}

std::string testCase(std::string &number){
	std::vector<bool> vc(10, false);
	int c = 0;

	std::reverse(number.begin(), number.end());
	{
		std::string acc(number);

		for (int i = 0; i < acc.size(); ++i) {
			int n = acc[i] - '0';
			if (!vc[n]) {
				++c; vc[n] = true;
			}
		}
		while (c != 10) {
			add(acc, number);
			if (acc == number) {return "INSOMNIA";}
			for (int i = 0; i < acc.size(); ++i) {
				int n = acc[i] - '0';
				if (!vc[n]) {
					++c; vc[n] = true;
				}
			}			
		}
		std::reverse(acc.begin(), acc.end());
		return acc;
	}
}

int main(){
	int n;

	cin >> n;
	cerr << "nt " << n;
	for (int i = 0; i < n; ++i) {
		std::string number;
		cin >> number;
		if (number[0] == '-') {
			cerr << number;
			number.erase(0, 1);
		}

		cout << "Case #" << (i + 1) << ": "<< testCase(number) << endl;
	}
}