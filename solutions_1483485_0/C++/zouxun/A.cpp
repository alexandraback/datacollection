#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

const char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	int cases;
	scanf("%d",&cases);
	string temp;
	getline(cin,temp);
	for (int tcase=1;tcase<=cases;tcase++)
	{
		printf("Case #%d: ",tcase);
		string str1;
		getline(cin,str1);
		for (int i=0;i<str1.size();i++)
			if (str1[i]==' ') printf(" ");
			else printf("%c",map[str1[i]-'a']);
		printf("\n");
//		string str2;
//		getline(cin,str2);
//		for (int i=0;i<str1.size();i++)
//			if (str1[i]!=' ')
//			{
//				map[str1[i]-'a']=str2[i];
///				t[str2[i]-'a']=true;	
//			}
	}
//	for (int i=0;i<26;i++) if (!t[i]) cout << char('a'+i) << endl;
//	for (int i=0;i<26;i++)
//		printf("%c,",map[i]);
	return 0;
}
