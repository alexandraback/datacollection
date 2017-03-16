#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int tt;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	string s="yhesocvxduiglbkrztnwjpfmaq";
	scanf("%d\n",&tt);
	for (int ii=1;ii<=tt;++ii) {
		string s1;
		getline(cin,s1);
		printf("Case #%d: ",ii);
		for (int i=0;i<(int)s1.size();++i)
			if (!isalpha(s1[i])) cout << s1[i];
			else cout << s[s1[i]-'a'];
		cout << endl;
	}
	return 0;
}
