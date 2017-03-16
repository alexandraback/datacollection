#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string trans = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	string orig =   "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char map[26];
	map['q'-'a'] = 'z';
	map['z'-'a'] = 'q';

	for(char a = 'a'; a <= 'z'; a++)
	{
		int pos = orig.find_first_of(a);
		if(pos != string::npos)
		{
	    	map[a-'a'] = trans[pos];
		}
		//else
		//	cout << "unfound " << a << std::endl;
	}

	//for(int i = 0; i < 26 ; i++)
	//	std::cout << map[i] << std::endl;

	ifstream fin;
	fin.open("A-small-attempt0.in");
	int num;
	fin>>num;
	ofstream fout;
	fout.open("A-small-attempt0.out");
	string input;
	getline(fin, input);
	for(int i = 1; i <= num; i++)
	{
		fout << "Case #" << i << ": ";
		std::getline(fin, input);
		for(int j = 0; j < input.size(); j++)
		{
			if(input[j] != ' ')
				input[j] = map[input[j]-'a'];
		}
		fout << input << std::endl;
	}
	return 0;
}
	
	