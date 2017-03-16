#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
	int S_max;
	cin >> S_max;
	string str;
	cin >> str;
	int sum = 0;
	int numFriends = 0;
	for (int s = 0; s <= S_max; s++) {
	    int x = str[s] - '0';
	    if (x > 0 && sum < s) {
		int diff = s - sum;
		numFriends += diff;
		sum += diff;
	    }
	    sum += x;
	}
	cout << "Case #" << (t + 1) << ": " << numFriends << endl;
    }
}
