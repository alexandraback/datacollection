#include<iostream>
#include<string>
using namespace std;
char code[256];
int main(){
	string a="qz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string b="zq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	for(int k=0;k<256;k++)code[k]=k;
	for(int k=0;k<a.size();k++) code[a[k]]=b[k];
	int n;cin>>n;
	string s;getline(cin,s);
	for(int m=1;m<=n;m++){
		getline(cin,s);
		for(int k=0;k<s.size();k++) s[k]=code[s[k]];
		cout<<"Case #"<<m<<": "<<s<<endl;
	}
	return 0;
	
}






