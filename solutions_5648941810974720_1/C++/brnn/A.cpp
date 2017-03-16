#include <iostream> 
using namespace std;

void solve_case(int T){
	string s;
	cin >> s;
	int counts[10] = {0};
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'Z'){
			counts[0]++;
		} else if (s[i] == 'W'){
			counts[2]++;
		} else if (s[i] == 'U'){
			counts[4]++;
		} else if (s[i] == 'X'){
			counts[6]++;
		} else if (s[i] == 'G'){
			counts[8]++;
		} else if (s[i] == 'O'){
			counts[1]++;
		} else if (s[i] == 'H'){
			counts[3]++;
		} else if (s[i] == 'F'){
			counts[5]++;
		} else if (s[i] == 'V'){
			counts[7]++;
		} else if (s[i] == 'N'){
			counts[9]++;
		}
	}

	counts[3] -= counts[8];
	counts[5] -= counts[4];
	counts[7] -= counts[5];
	counts[1] -= (counts[0] + counts[2] + counts[4]);
	counts[9] = (counts[9] - counts[1] - counts[7])/2;

	cout << "Case #" << T << ": ";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < counts[i]; j++){
			cout << i;
		}
	}
	cout << endl;
}

int main() {
  	int t;
  	cin >> t; 
  	for (int i = 1; i <= t; i++) {
  	  	solve_case(i);
  	}
  	return 0;
}