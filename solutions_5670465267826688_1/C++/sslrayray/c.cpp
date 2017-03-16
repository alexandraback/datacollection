#include <bits/stdc++.h>
using namespace std;


int tran[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};


int getval(string str){
	int strval = 1;
	for (int i = 0; i < str.length(); i++) {
		int unit = str[i] - 'i' + 2;
		if (strval > 0)
			strval = tran[strval][unit];
		else
			strval = -tran[-strval][unit];
	}
	return strval;
}

int main(){
	int repn;
	cin >> repn;

	for (int rep = 0; rep < repn; rep++) {
		int L;
		long long X;
		string strin;
		cin >> L >> X >> strin;
		//calc the value of str:
		int strval;
		strval = getval(strin);
		
//		cout << "strval is : " << strval << endl;

		if (strval == 1 ){
			cout << "Case #"<< rep+1 << ": NO" << endl;
			continue;
		}
		if (strval == -1 ) {
			if (X % 2 == 0) {				
				cout << "Case #"<< rep+1 << ": NO" << endl;
				continue;
			}
		}else{
			if (X%2 == 1 || ((X/2) % 2 != 1)){
				cout << "Case #"<< rep+1 << ": NO" << endl;
				continue;
			}
		}
		string strtemp = "";

		for (int i = 0; i < 4; i++) 
			strtemp = strtemp + strin;
		

		int ipos = -1, jpos = -1;

		int val = 1;
//		cout << strtemp << "length " << strtemp.length() << endl;
		for (int i = 0; i < strtemp.length(); i++) {
			int unit = strtemp[i] - 'i' + 2;
			if (val > 0)
				val = tran[val][unit];
			else
				val = -tran[-val][unit];
			if (val == 2){
				ipos = i;
				break;
			}
		}

		if (ipos == -1 || (ipos / strin.length()+1 > X )) {
			cout << "Case #"<< rep+1 << ": NO" << endl;
			continue;
		}
//		cout << strtemp << "length " << strtemp.length() << endl;
//		cout << ipos << endl;
		int len =  (ipos+1)%strin.length();
		strtemp = strin.substr((ipos+1)%strin.length(), strin.length()- (ipos%strin.length()) - 1);
		for (int i = 0; i < 4; i++)
			strtemp = strtemp + strin;
		
		val = 1;
		for (int i = 0; i < strtemp.length(); i++) {
			int unit = strtemp[i] - 'i' + 2;
			if (val > 0)
				val = tran[val][unit];
			else
				val = -tran[-val][unit];
			if (val == 3){
				jpos = i;
				break;
			}
		}
		if ( jpos == -1 || (((ipos + jpos + 1) / strin.length()+1) > X)){
			cout << "Case #"<< rep+1 << ": NO" << endl;
			continue;
		}
		cout << "Case #"<< rep+1 << ": YES" << endl;		
	}
	return 0;
}