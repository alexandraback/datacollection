#include <iostream>
#include <string>
using namespace std;
int m[30];
bool b[30];
int main()
{
	int i, j;
	m['q'-'a'+1] = 'z'-'a'+1;
	b['z'-'a'+1] = 1;
	for(i = 0; i < 3; i++) {
		string sin, sout;
		getline(cin, sin);
		getline(cin, sout);
		for(j = 0; j < sin.length(); j++)
			if(sin[j] != ' ') {
				m[sin[j]-'a'+1] = sout[j]-'a'+1;
				b[sout[j]-'a'+1] = 1;
			}
	}
	for(i = 1; i < 27; i++) {
		if(m[i] == 0) {
			for(j = 1; j < 27; j++)
				if(!b[j]) break;
			m[i] = j;
			b[j] = 1;
		}
	}
//	for(i = 1; i < 27; i++) cout <<char(i+'a'-1) <<" "<<char(m[i]-1+'a')<<endl;
	string s;
	int n;
	cin >> n;
	cin.ignore();
	for(i = 1; i <= n; i++) {
		getline(cin, s);
		string ans = "";
		for(j = 0; j < s.length(); j++)
			if(s[j] == ' ') ans.push_back(s[j]);
			else ans.push_back(m[s[j]-'a'+1]-1+'a');
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
