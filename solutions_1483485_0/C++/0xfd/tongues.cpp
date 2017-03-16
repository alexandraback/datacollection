#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sample[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"y qee"
};

string translated[] = {"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"a zoo"
};

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");
	
	// analyze the sample
	char *map = new char[26];
	
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<sample[i].length(); j++)
		{
			if (sample[i][j] != ' ')
			{
				cout<<sample[i][j]<<" -> "<<translated[i][j]<<endl;
				map[int(sample[i][j])-97] = translated[i][j];
			}
		}
	}
	
	// display the mapping
	for (int i=0; i<26; i++)
	{
		cout<<char(i+97)<<" => "<<map[i]<<endl;
	}
	
	// observing that 'z' is missing and it should go to 'q' by inspection
	map[int('z')-97] = 'q';
	
	int t;
	fi>>t;
	string s;
	getline(fi, s);
	for (int i=0; i<t; i++)
	{
		getline(fi, s);
		string r = "";
		
		for (int j=0; j<s.length(); j++)
		{
			r += (s[j] == ' ')? ' ' : map[int(s[j])-97];
		}
		
		cout<<"Case #"<<i+1<<": "<<r<<endl;
		fo<<"Case #"<<i+1<<": "<<r<<endl;
	}
	
	return 0;
}