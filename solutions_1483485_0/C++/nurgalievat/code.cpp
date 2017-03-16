#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>
using namespace std;

char p[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int n;
string s,sr;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>ws;
	for(int i=0;i<n;i++)
	{
		getline(cin,s);
		sr = s;
		for(int j=0;j<s.length();j++)
			if(isalpha(s[j]))
				sr[j] = p[s[j]-'a'];
		cout<<"Case #"<<(i+1)<<": "<<sr<<endl;
	}
	return 0;
}