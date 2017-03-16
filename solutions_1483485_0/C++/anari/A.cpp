#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
ifstream fin("sample.in");
map<char, char> m;
string l1, l2;
void setmap(char c,char d){
	if (m.find(c)!=m.end() && m[c]!=d)
		throw -1;
	m[c]=d;
}
char getmap(char c){
	if (m.find(c)==m.end())
		throw -1;
	return m[c];
}
int main(){
	int tcou;fin>>tcou;getline(fin, l1);
	while (tcou--){
		getline(fin, l1);
		getline(fin, l2);
		for (int i=0;i<l1.size();++i)
			if (l1[i]>='a' && l1[i]<='z')
				setmap(l1[i], l2[i]);
	}
	char c1=0,c2=0;
	for (char c='a';c<='z';++c){
		c2^=c;
		if (m.find(c)==m.end())
			c1=c;
		else
			c2^=m[c];
	}
	if (c1!=0)
		setmap(c1, c2);
	int tnum=0;
	cin>>tcou;getline(cin, l1);
	while (tcou--){
		getline(cin, l1);
		cout<<"Case #"<<++tnum<<": ";
		for (int i=0;i<l1.size();++i)
			cout<<((l1[i]>='a' && l1[i]<='z')?getmap(l1[i]):l1[i]);
		cout<<endl;
	}
	return 0;
}
