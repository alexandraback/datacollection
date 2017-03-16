#include<iostream>
#include<string>
using namespace std;

char dic[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	int n;
	cin>>n;
	string str;
	getline(cin,str);

	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		cout<<"Case #"<<i+1<<": ";
//		cout<<s<<endl;
		for(int k=0;k<s.size();k++){
			if(!isalpha(s[k])) cout<<" ";
			else cout<<dic[s[k]-'a'];
		}
		cout<<endl;
	}
	return 0;
}