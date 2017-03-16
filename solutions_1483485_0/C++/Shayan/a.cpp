#include <iostream>
using namespace std;

int t;
string s,ss,s1;
char ch[10000];

int main()
{
	cin >> t;
	s="ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
	ss="ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
	for (int i=0;i<s.length();i++)
		ch[s[i]]=ss[i];
	ch['z']='q';
	ch['q']='z';
	ch[' ']=' ';	
	getline(cin,s);
	for (int i=1;i<=t;i++)
	{
		getline(cin,s);
		ss="";
		for (int j=0;j<s.length();j++)
				ss+=ch[s[j]];
		cout << "Case #"<<i<<": "<< ss << endl;
	}
	return 0;
}
