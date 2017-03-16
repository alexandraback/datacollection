#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

void solve_case(void)
{
	int N, S, p;
	cin >> N >> S >> p;
	int threshold;
	threshold = (p - 1) * 3;
	int greater = 0, possibly_greater = 0;
	for (int i = 0; i < N; i++) {
		int score;
		cin >> score;
		if (score > threshold) {
			greater++;
		} else if ((score > threshold - 2) && (threshold > 0)) {
			possibly_greater++;
		}
	}
	greater += ((S < possibly_greater)? S : possibly_greater);  
	cout << greater;
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
