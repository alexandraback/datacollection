#include <iostream> 
#include <cmath>
using namespace std;

bool match(string c, int inp){
	if (inp >= pow(10, c.size())){
		return false;
	} else {
		int tmp;
		bool output = true;
		for (int i = 0; i < c.size(); i++){
			tmp = inp % 10;
			inp = inp/10;
			if (tmp != (int)(c[c.size() - 1 - i] - '0') &&
				c[c.size() - 1 - i] != '?'){
				output = false;
			}
		}
		return output;
	}
}

void solve_case(int T){
	string c, j;
	cin >> c >> j;

	int minC = 1000;
	int minJ = 0;
	for (int r = 0; r < 1000; r++){
		for (int s = 0; s < 1000; s++){
			if (match(c, r) && match(j, s)){
				if (abs(r - s) < abs(minC - minJ)){
					minC = r;
					minJ = s;
				}
			}
		}
	}

	string outC = "", outJ = "";
	char tmp;
	for (int i = 0; i < c.size(); i++){
		tmp = '0' + minC % 10;
		outC = tmp + outC;
		minC = minC/10;
		tmp = '0' + minJ % 10;
		outJ = tmp + outJ;
		minJ = minJ/10;
	}

	cout << "Case #" << T << ": " << outC << " " << outJ << endl;
}

int main() {
  	int t;
  	cin >> t; 
  	for (int i = 1; i <= t; i++) {
  	  solve_case(i);
  	}
  	return 0;
}