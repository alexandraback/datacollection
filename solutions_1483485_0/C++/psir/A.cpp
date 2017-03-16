#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char buff[200];

int main()
	{
	string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string s4 = "y qeez";

	string a1 = "our language is impossible to understand";
	string a2 = "there are twenty six factorial possibilities";
	string a3 = "so it is okay if you want to just give up";
	string a4 = "a zooq";

	char a[26]={0};
	for( int i = 0; i < s1.size(); ++i )
		{
		a[s1[i]-'a'] = a1[i] - 'a';
		}		
	for( int i = 0; i < s2.size(); ++i )
		{
		a[s2[i]-'a'] = a2[i] - 'a';
		}		
	for( int i = 0; i < s3.size(); ++i )
		{
		a[s3[i]-'a'] = a3[i] - 'a';
		}		
	for( int i = 0; i < s4.size(); ++i )
		{
		a[s4[i]-'a'] = a4[i] - 'a';
		}		
	//for( int i = 0; i < 26; ++i )
	//		cout << (char)('a' + i) << (char)(a[i]+'a') << endl;

	int T;
	gets(buff);
	sscanf(buff,"%d",&T);

	for( int t = 0 ; t< T; ++t )
		{
		gets(buff);
		for( int i = 0; i < strlen(buff); ++i )
			if( 'a' <= buff[i] && 'z' >= buff[i] )
				buff[i] = a[buff[i] - 'a'] + 'a'; 
		printf("Case #%d: %s\n",t+1,buff);
		}

	return 0;
	}
