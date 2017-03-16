#include<iostream>
#include<string>
using namespace std;
int t,res;
string s;
char akt_znak;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> s;
		
		akt_znak = s[0];
		res = 0;
		
		
		for(int j = 1; j < s.size(); j++){
			if(s[j] != akt_znak){
				res++;
				akt_znak = s[j];
			}
		}
		
		if(s[s.size() - 1] == '-')res++;
		
		cout << "Case #"<<i<<": "<<res<<endl;
	}

return 0;
}
