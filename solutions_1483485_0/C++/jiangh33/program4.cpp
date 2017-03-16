#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100 + 5;
char plain[3][MAX] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};
char encode[3][MAX] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
char map[MAX], line[MAX];
bool flag[MAX];
int n;

void init()
{
	memset(flag, 0, sizeof(flag));
	memset(map, 0, sizeof(map));
	for(int i = 0; i < 3; ++ i)
		for(int j = 0; encode[i][j] != '\0'; ++ j)
		{
			map[encode[i][j]-'a'] = plain[i][j];
			flag[plain[i][j]-'a'] = 1;
		}
	map['q'-'a'] = 'z';
	for(int i = 0; i < 26; ++ i)
		if(flag[i] == 0)
		{
			for(int j = 0; j < 26; ++ j)
				if(map[j] == 0)
				{
					map[j] = i + 'a';
					break;
				}
			break;
		}
}

int main()
{
	fstream in("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\data.txt", ios::in), 
		out("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\ans.txt", ios::out);
	init();
	in>>n;
	in.getline(line, sizeof(line));
	for(int t = 1; t <= n; ++ t)
	{
		out<<"Case #"<<t<<": ";
		in.getline(line, sizeof(line));
		int i = 0;
		do{
			char ch;
			if(isalpha(line[i]))
				ch = map[line[i]-'a'];
			else if(line[i] == '\0')
				ch = '\n';
			else
				ch = line[i];
			out<<ch;
		}while(line[i++] != '\0');
	}
	in.close(), out.close();

	return 0;
}