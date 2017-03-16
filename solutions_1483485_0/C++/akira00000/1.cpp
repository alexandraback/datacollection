// 1.cpp
//

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	const char map_alpha[27] = "yhesocvxduiglbkrztnwjpfmaq";
	int T;
	char buf[128];
	char ans[128];

	cin.getline(buf, 128);
	T = atoi(buf);
	for(int t=1 ; t<=T ; ++t) {
		cin.getline(buf, 128);
		int len = strlen(buf);
		for(int i=0 ; i<len ; ++i) {
			if(isalpha(buf[i]))	ans[i] = map_alpha[buf[i]-'a'];
			else				ans[i] = ' ';
		}
		ans[len] = 0;
		cout << "Case #" << t << ": " << ans << endl;
	}


	return 0;
}