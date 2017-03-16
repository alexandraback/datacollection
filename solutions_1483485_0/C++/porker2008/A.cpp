#include <iostream>
using namespace std;

string o[4] = 
{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	"qz" // get by hand
};

string n[4] = 
{
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up",
	"zq" // get by hand
};

int map[26];
int onto[26];

int main()
{
	memset(map,0,sizeof(map));
	memset(onto,0,sizeof(onto));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<o[i].size();j++)
		{
			if(o[i][j]==' ')
				continue;
			if(map[o[i][j]-'a']==0 || map[o[i][j]-'a']==n[i][j]-'a'+1)
			{
				map[o[i][j]-'a'] = n[i][j]-'a'+1;
				onto[n[i][j]-'a'] = 1;
			}
			else
			{
				cout << "Error" << endl;
			}
		}
	}
	for(int i=0;i<26;i++)
	{
		if(map[i]==0)
			cout << "Error: " << char(i+'a') << endl;
		if(onto[i]==0)
			cout << "Wrong: " << char(i+'a') << endl;
	}
	int t;
	string input;
	cin >> t;
	getline(cin,input);
	for(int i=1;i<=t;i++)
	{
		getline(cin,input);
		cout << "Case #" << i << ": ";
		for(int j=0;j<input.size();j++)
		{
			if(input[j]==' ')
				cout << ' ';
			else
				cout << char(map[input[j]-'a']+'a'-1);
		}
		cout << endl;
	}
}
