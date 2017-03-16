#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char map[26]={'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main() {
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	for (int i=1;i<=n;i++) {
		cout<<"Case #"<<i<<": "; 
		getline(cin,s);
		for (int i=0;s[i];i++)
			if (s[i]==' ') putchar(' ');
			else putchar(map[s[i]-'a']);
		cout<<endl;
	}
	return 0;
}
