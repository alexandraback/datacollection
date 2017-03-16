#include <iostream>

using namespace std;

typedef unsigned long long Int;

int main(int, char **) {
	int nb_tc;
	cin >> nb_tc;
	Int K, C, S;
	for (auto tc = 1; tc <= nb_tc;  ++tc) {
		cin >> K >> C >> S;
		cout << "Case #" << tc << ':';
		for (auto i = 1; i <= S; ++i) {
			cout << ' ' << i;
		}
		cout << endl;
	}
    return 0;
}
