#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

bool match(string x, int y){
	int len = x.length();
	stringstream ss;
	ss << y;
	string tmp = ss.str();
	string prefix(len - tmp.length(), '0');
	string sy = prefix + tmp;

	for (int i = 0; i < len; i++){
		if (x[i] == '?')
			continue;

		if (x[i] != sy[i])
			return false;
	}

	return true;
}

int main(){
	int t;
	string c, j;
	string ans_c, ans_j;

	scanf("%d", &t);

	for (int i = 1; i <= t; i++){
		cin >> c >> j;
		int bound = pow(10, c.length()), ans = INT_MAX;
		for (int a = 0; a < bound; a++){
			for (int b = 0; b < bound; b++){
				if (ans > abs(a - b) && match(c, a) && match(j, b)){
					ans = abs(a - b);
					stringstream ss1, ss2;
					ss1 << a;
					ss2 << b;
					string sa = ss1.str(), sb = ss2.str();
					string prea(c.length() - sa.length(), '0');
					string preb(c.length() - sb.length(), '0');
					ans_c = prea + sa;
					ans_j = preb + sb;
				}
				if (ans == 0)
					break;
			}
			if (ans == 0)
				break;
		}
		cout << "Case #" << i << ": " << ans_c << " " << ans_j << endl;
	}
		
	return 0;
}
