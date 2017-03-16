#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int testCase(std::string &number){
	int c = 0;
	bool state = false;
	for (int i = 0; i < number.size(); ++i) {
		bool nstate = (number[i] == '+');
		if (state != nstate) {
			c += (i != 0);
			state = nstate;
		}
	}
	if (state == false)
		++c;
	return c;
}

int main(){
	int n;

	cin >> n;
	cerr << "nt " << n;
	for (int i = 0; i < n; ++i) {
		std::string number;
		cin >> number;
		cout << "Case #" << (i + 1) << ": "<< testCase(number) << endl;
	}
}