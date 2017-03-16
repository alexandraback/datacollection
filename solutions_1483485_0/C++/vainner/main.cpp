#include <iostream>
#include <string>
#include <map>
using std::map;
using std::string;
using std::cin ; using std::cout;
using std::endl;
map<char,char> dic;
string ori[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string done[3]= {"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};

void init()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		int len = ori[i].length();
		for(int j = 0 ; j < len ; j++)
			dic[ori[i][j]] = done[i][j];
	}
	dic['z'] = 'q';
	dic['q'] = 'z';
}
int main()
{
	init();
	string str;
	int n;
	scanf("%d",&n);
	{
		getchar();
		for (int k = 1 ; k <= n ; k++)
		{
			getline(cin,str);
			int len = str.length();
			printf("Case #%d: ",k);
			for (int i = 0 ; i < len ; i++)
				printf("%c",dic[str[i]]);
			printf("\n");
		}
	}
	return 0;
}