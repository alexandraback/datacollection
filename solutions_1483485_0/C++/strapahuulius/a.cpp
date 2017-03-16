#include <iostream>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
using namespace std;
const string input =
	"ejp mysljylc kd kxveddknmc re jsicpdrysi"
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	"yeqz";
const string output =
	"our language is impossible to understand"
	"there are twenty six factorial possibilities"
	"so it is okay if you want to just give up"
	"aozq";
int main()
{
	assert(input.size() == output.size());
	int n = input.size();
	set<pair<char, char> > mapping;
	map<char, char> mp;
	for (int i=0; i<n; i++)
	{
		mp[input[i]] = output[i];
		if (input[i] == ' ')
		{
			assert(output[i] == ' ');
			continue;
		}
		mapping.insert(make_pair(input[i], output[i]));
	}
	assert(mapping.size() == 26);
	int t;
	cin >> t;
	string line;
	getline(cin, line);
	for (int tc=0; tc<t; tc++)
	{
		getline(cin, line);
		for (string::iterator it = line.begin(); it != line.end(); ++it)
		{
			assert(mp.count(*it));
			*it = mp[*it];
		}
		cout << "Case #" << tc + 1 << ": " << line << endl;
	}
	return 0;
}
