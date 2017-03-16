#include <iostream>

using namespace std;

int main(){
	int n, smax, c, add;
	string s;
	cin >> n;
	for (int k = 1; k <= n; k++){
		cin >> smax >> s;
		c = add = 0;
		for (int i = 0; i < s.length(); i++){
			if (i > c){
				add += i - c;
				c = i;
			}
			c += s[i] - '0';
		}
		cout << "Case #" << k << ": " << add << endl;
	}
	
	return 0;
}
