#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string str;
const char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b',
					'k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	int t,cases=1;
	for(cin>>t,getchar();t--;)
	{
		printf("Case #%d: ",cases++);
		getline(cin,str);
		for(int i=0;i<str.length();++i)
		{
			if(str[i]==' ')putchar(' ');
			else printf("%c",map[str[i]-'a']);
		}
		puts("");
	}
	return 0;
}
