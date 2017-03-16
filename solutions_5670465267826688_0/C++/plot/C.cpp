#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int array[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int mult(int a, int b){
	int factor = 1;
	if(a < 0 && b > 0 || a > 0 && b < 0)
		factor = -1;
		
	return array[abs(a) - 1][abs(b) - 1] * factor;
}

int char_number(char c){
	return c - 'i' + 2;
}

string rep(string s, int n) {
    ostringstream os;
    for (int i = 0; i < n; i++) {
        os << s;
    }
    return os.str();
}

string solve(string s){
	int vali = 1, valj = 1, valk = 1;
	for(int i = 0; i < s.size(); i++){
		vali = mult(vali, char_number(s.at(i)));
		if(vali != 2)
			continue;
		for(int j = i + 1; j < s.size(); j++){
			valj = mult(valj, char_number(s.at(j)));
			if(valj != 3)
				continue;
			for(int k = j + 1; k < s.size(); k++){
				valk = mult(valk, char_number(s.at(k)));
				if(valk != 4)
					continue;
				if(k == s.size() - 1)
					return "YES";
			}
			break;
		}
		break;
	}
	
	return "NO";
}

int main() {
	int t, l, x;
	string s;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> l >> x;
		cin >> s;
		cout << "Case #" << (i + 1) << ": " << solve(rep(s, x)) << "\n";
	}
	
	return EXIT_SUCCESS;
}
