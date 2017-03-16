#include <iostream>
using namespace std;

int main(){
	int t, tt = 1;
	for(cin >> t; t; t--, tt++){
		cout << "Case #" << tt << ": ";
		string s;
		cin >> s;
		int c = 0, l;
		for(l = s.size() - 1; l >= 0 && s[l] == '+'; l--){}
		while(l >= 0){
			if(s[0] == '+'){
				for(int i = 0; i < s.size() && s[i] == '+'; i++)
					s[i] = '-';
				c++;
			}
			for(int i = 0; i <= l / 2; i++){
				char t = s[i];
				s[i] = s[l - i];
				s[l - i] = t;
			}
			for(int i = 0; i <= l; i++)
				s[i] = s[i] == '-' ? '+' : '-';
			c++;
			for(; l >= 0 && s[l] == '+'; l--){}
		}
		cout << c << endl;
	}

	return 0;
}