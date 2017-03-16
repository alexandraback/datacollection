#include <iostream>
#include <algorithm>
using namespace std;

		/*abcdefghijklmnopqrstuvwxyz*/
char* tr="yhesocvxduiglbkrztnwjpfmaq";

void tst()
{
	string s;
	getline(cin, s);

	for (int i=0; i<s.length(); i++) {
		if (s[i]>='a' && s[i]<='z') {
			cout << tr[s[i]-'a'];
		} else {
			cout << s[i];
		}
	}
}

int main()
{
    int t;
    cin >> t;
	string s;
	getline(cin, s);
    for(int i=0;i<t;i++) {
        cout << "Case #" << i+1 << ": ";
		tst();
		cout << endl;
	}
}



