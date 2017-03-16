#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring> // memset(void *b, int c, size_t len);
#include <algorithm> // sort
#include <iomanip> // cout << std::fixed << std::setprecision(4)

using namespace std;

int main(int argc, char* argv[]) {
	int T, Smax;
	string s;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> Smax >> s;
		
		int num = 0, total = 0;
		for(int i = 0; i <= Smax; ++i) {
			int n = s.at(i) - '0';
			if(n > 0 && total+num < i) 
				num = i - total;
			total += n;
		}

		cout << "Case #" << t+1 << ": " << num << endl;
	}
	return 0;
}

