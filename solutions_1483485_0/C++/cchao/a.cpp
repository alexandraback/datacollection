#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
	string a;
	string s="yhesocvxduiglbkrztnwjpfmaq";
	int tt;
	cin >> tt;
	int k,j;
	getline(cin,a);
	for(k=0;k<tt;k++){
		cout << "Case #" << k+1 << ": ";
		getline(cin,a);
		for(j=0;j<a.length();j++)
			if(islower(a[j])) putchar(s[(int)(a[j]-'a')]);
			else putchar(a[j]);
		cout << endl;
	}
	return 0;
}
