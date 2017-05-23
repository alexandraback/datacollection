#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int T;
string S;

int main(){
	cin >> T;
	for(int i=0; i< T; i++){
		cin >> S;
		int len = S.length();
		string ans = "";
		ans += S[0];
		for(int j = 1; j < len; j++){
			if(S[j] >= ans[0])
				ans = S[j] + ans;
			else
				ans += S[j];
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}