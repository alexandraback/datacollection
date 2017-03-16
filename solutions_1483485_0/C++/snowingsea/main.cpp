#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
using namespace std;
char s[1000];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i;
	map<char,char> m;
	string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string s2 = "our language is impossible to understand";
	for(i = s1.length()-1;i >= 0;i--)
		m[s1[i]] = s2[i];
	s1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s2 = "there are twenty six factorial possibilities";
	for(i = s1.length()-1;i >= 0;i--)
		m[s1[i]] = s2[i];
	s1 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	s2 = "so it is okay if you want to just give up";
	for(i = s1.length()-1;i >= 0;i--)
		m[s1[i]] = s2[i];
	i = 0;
	for (char ch = 'a';ch <= 'z';ch++)
	{
		if(m.find(ch) == m.end())
			s[i++] = ch;
	}
	m[s[0]] = s[1];
	m[s[1]] = s[0];
 	int t,cas=1;
	scanf("%d\n", &t);
	while (t--)
	{
		gets(s);
		for (i = 0;s[i] != '\0';i++)
			s[i] = m[s[i]];
		printf("Case #%d: %s\n",cas++,s);
	}
	return 0;
}