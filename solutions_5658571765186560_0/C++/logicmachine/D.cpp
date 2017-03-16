#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int x, r, c;
		cin >> x >> r >> c;
		bool answer = true;
		if(r > c){ swap(r, c); }
		if(x >= 7 || x > c){ answer = false; }
		if(r * c % x != 0){ answer = false; }
		if(answer && x > r){
			if(x == 3){
				if(r == 1){ answer = false; }
			}else if(x == 4){
				if(r <= 2){ answer = false; }
			}else if(x == 5){
				if(r <= 2){ answer = false; }
				if(r == 3 && c <= 5){ answer = false; }
			}else if(x == 6){
				if(r <= 4){ answer = false; }
			}
		}
		cout << "Case #" << case_num << ": ";
		cout << (!answer ? "RICHARD" : "GABRIEL") << endl;
	}
	return 0;
}

