#include<iostream>
using namespace std;

int tt, n, t, J;
string s;

int main(){
	cin >> tt;
	for (int _t=0 ; _t<tt ; _t++){
		cin >> n >> s;
		J = 0;
		t = s[0] - '0';
		for (int i=1 ; i<=n ; i++){
			if (s[i]!='0' && t<i){
				J += i-t;
				t = i;
			}
			t += s[i] - '0';
		}
		cout << "Case #" << _t+1 << ": " << J << endl;
	}
}
