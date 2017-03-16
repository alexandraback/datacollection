#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> goo;
	goo.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	goo.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	goo.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

	vector <string> eng;
	eng.push_back("our language is impossible to understand");
	eng.push_back("there are twenty six factorial possibilities");
	eng.push_back("so it is okay if you want to just give up");

	map<char, char> mapping;

	for(char c='a';c<='z';c++)
	{
		mapping[c]=c;
	}

	for(size_t i=0;i<goo.size();i++)
	{
		for(size_t j=0;j<goo[i].size();j++)
		{
			mapping[goo[i][j]] = eng[i][j];
		}
	}

	mapping['z'] = 'q';
	mapping['q'] = 'z';

	freopen("A-small-attempt3.in", "r", stdin);
	freopen("qr_a_output.txt", "w", stdout);

	int t;
	scanf("%d",&t);
	char tmp[100];
	gets(tmp);
	for(int i=1;i<=t;i++)
	{
		char line[200];
		gets(line);
		printf("Case #%d: ",i);
		for(int j=0;j<strlen(line);j++)
		{
			putchar(mapping[line[j]]);
		}
		putchar('\n');
	}

	return 0;
}
