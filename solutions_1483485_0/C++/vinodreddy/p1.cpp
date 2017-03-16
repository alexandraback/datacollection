#include<iostream>
using namespace std;
int main()
{
	char map[150];
	string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string s2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	for(int i = 0;i < s1.length();i++)
	{
		map[s1[i]] = s2[i];
	}
	
	map['z'] = 'q';
	map['q'] = 'z';
	int t;
	cin >> t;
	string s;
	getline(cin,s);
	for(int i = 1;i <= t;i++)
	{
		
		getline(cin,s);
		cout << "Case #" << i <<": ";
		for(int j = 0;j < s.length();j++)
		{
			cout << map[s[j]];
		}
		cout << endl;
	}
	return 0;
}
