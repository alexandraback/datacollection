#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#define fi "A-small-attempt1.in"
#define fo "A-small-attempt1.out"
//#define fi "Q_A.INP"
//#define fo "Q_A.OUT"
#define INF 1000000000
using namespace std;
//VARIABLES
string s[3],t[3];
int a[50],n;
char ch[200];

//MAIN
void Init()
{
	s[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	s[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	t[0]="our language is impossible to understand";
	t[1]="there are twenty six factorial possibilities";
	t[2]="so it is okay if you want to just give up";
	for (int i=0;i<=2;++i)
	for (int j=0;j<s[i].size();++j)
	if (s[i][j]!=' ')
	a[int(s[i][j]-'a')]=int(t[i][j]-'a');
	a[int('z'-'a')]=int('q'-'a');
	a[int('q'-'a')]=int('z'-'a');
}
int main()
{
	int test;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       Init();
       scanf("%d",&test);gets(ch);
       cerr << "ok" << endl;
       for (int i=1;i<=test;++i)
       {
		gets(ch);n=strlen(ch);
		for (int j=0;j<n;++j)
		if (ch[j]!=' ') ch[j]=char(a[int(ch[j]-'a')]+'a');
		printf("Case #%d: %s\n",i,ch);
	}
       return 0;
}
