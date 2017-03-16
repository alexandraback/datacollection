#include <bits/stdc++.h>
using namespace std;
string trans(string x, string y) {
	if(x == "1" && y == "1") return "1";
	if(x == "1" && y == "i") return "i";
	if(x == "1" && y == "j") return "j";
	if(x == "1" && y == "k") return "k";

	if(x == "i" && y == "1") return "i";
	if(x == "i" && y == "i") return "-1";
	if(x == "i" && y == "j") return "k";
	if(x == "i" && y == "k") return "-j";

	if(x == "j" && y == "1") return "j";
	if(x == "j" && y == "i") return "-k";
	if(x == "j" && y == "j") return "-1";
	if(x == "j" && y == "k") return "i";

	if(x == "k" && y == "1") return "k";
	if(x == "k" && y == "i") return "j";
	if(x == "k" && y == "j") return "-i";
	if(x == "k" && y == "k") return "-1";
}
string Mul(string x, string y) {
	
	//cout << "x = " << x << ", y = " << y << endl;
	bool flag = 0;
	if(x[0] == '-') {
		flag ^= 1;
		x.erase(0, 1);
	}
	if(y[0] == '-') {
		flag ^= 1;
		y.erase(0, 1);
	}
	//cout << "x = " << x << ", y = " << y << " trans = " << trans(x, y) << endl;
	string ret = trans(x, y);
	if(flag) {
		if(ret[0] == '-') ret.erase(0, 1); else ret = "-" + ret;
	}
	return ret;
}
int main() {
#ifdef youmu
	freopen("C.in", "r", stdin);
	freopen("C.ou", "w", stdout);
#endif
	int T, L, X, cases = 0;
	cin >> T; 
	while(T--) {
		cin >> L >> X;
		string str = "", tmp;
		cin >> tmp;
		for(int i = 0; i < X; i++) str += tmp;
		//cout << "Str = " << str << endl;
		string t = "1";
		bool flag1 = 0, flag2 = 0;
		for(int i = 0; i < L * X; i++) { 
			string u = "";
			u += str[i];
			//cout << "###" << "u = " << u << endl;
			t = Mul(t, u);
			if(t == "i") flag1 = 1;
			if(t == "k" && flag1 == 1) flag2 = 1;
		}
		cout << "Case #" << ++cases << ": " << ((t == "-1" && flag2) ? "YES" : "NO") << endl;
	} 
	return 0;
}

