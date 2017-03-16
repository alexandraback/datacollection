#include "stdafx.h"
#include "stdafx.h"
#include "fstream"
#include "vector"
#include "algorithm"
#include "numeric"
#include "sstream"
#include "string"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	string str1("ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv");
    string str2("our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up");

	vector<char> map;
	map.resize('z' - 'a' + 1, '!');
	for (int i = 0; i < str1.length(); ++i)
	{
		if (str1[i] == ' ')
		{
			continue;
		}
		map[str1[i]  - 'a'] = str2[i];
	}
	map['z'  - 'a'] = 'q';
	map[16] = 'z';
	//sort(map.begin(), map.end());

	fstream f("test.txt");
	fstream r("result.txt");
	
	stringstream strStream;
	string line;
	//string word;
	int t;
	f >> t;
	getline(f, line);
	for (int i = 0; i < t; ++i)
	{
		getline(f, line);
		
		r << "Case #" << i + 1<< ": ";
		for (int j = 0; j < line.length(); ++j)
		{
			if (line[j] == ' ' || line[j] == '\n')
			{
				r << line[j];
				continue;
			}
			r << map[line[j] - 'a'];
		}
		r << endl;
		
		
	}

	r.close();
	f.close();
	return 0;
}
