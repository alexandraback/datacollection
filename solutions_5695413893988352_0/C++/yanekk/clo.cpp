#include <iostream>
#include <string>

using namespace std;

int main(){
	int i,n,j,k;
	string s1,s2;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> s1 >> s2;
		for(j=0; j<s1.size(); j++){
			if(s1[j] == '?' && s2[j] != '?') s1[j] = s2[j];
			if(s2[j] == '?' && s1[j] != '?') s2[j] = s1[j];
			if(s2[j] == s1[j] && s1[j] == '?') s2[j] = s1[j] = '0';
			if(s2[j] != '?' && s1[j] != '?' && s2[j] != s1[j]) break;
		}
		if(j < s1.size() && s1[j] > s2[j]){
			for(k=j; k<s1.size(); k++) if(s1[k] == '?') s1[k] = '0';
			for(k=j; k<s2.size(); k++) if(s2[k] == '?') s2[k] = '9';
		}
		else{
			for(k=j; k<s1.size(); k++) if(s1[k] == '?') s1[k] = '9';
			for(k=j; k<s2.size(); k++) if(s2[k] == '?') s2[k] = '0';
		}
		cout << "Case #" << i+1 << ": " << s1 << " " << s2 << "\n";
	}
	return 0;
}
