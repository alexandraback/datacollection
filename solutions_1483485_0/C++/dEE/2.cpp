#include<iostream>
using namespace std;

char rep[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main() {
	int tc; scanf("%d\n",&tc);
	char s[101];
	for(int t=1;t<=tc;t++) {
		cin.getline(s,101);
		int l = strlen(s);
		for(int i=0;i<l;i++) if(s[i]!=' ') s[i] = rep[s[i]-'a'];
		cout<<"Case #"<<t<<": "<<s<<"\n";
	}
}
