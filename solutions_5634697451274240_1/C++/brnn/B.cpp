#include <iostream> 
using namespace std;

void solve_case(int T){
	string s;
	cin >> s;

	int count = 0;
	for (int i = 1; i < s.size(); i++){
		if (s[i] != s[i-1]){
			count++;
		}
	}

	if (s[s.size()-1] == '-'){
		count++;
	}

	cout << "Case #" << T << ": " << count << endl;
}

int main() {
  int t;
  cin >> t; 
  for (int i = 1; i <= t; i++) {
    solve_case(i);
  }
  return 0;
}