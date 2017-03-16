#include <stdio.h>
#include <iostream>
using namespace std;

char cg[300],s[100000];
string s0[7];
int main()
{
	int T,i,j,t;
	s0[1]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	s0[2]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s0[3]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	s0[4]="our language is impossible to understand";
	s0[5]="there are twenty six factorial possibilities";
	s0[6]="so it is okay if you want to just give up";

	for (i=1; i<=3; i++)
		for (j=0; j<s0[i].length(); j++)
			cg[(int)s0[i][j]]=s0[i+3][j];
	cg[96+26]='q'; cg[96+17]='z';
	//for (i=1; i<=26; i++) cout << (char)(96+i) << " " << cg[96+i] << endl;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> T;
	getchar();
	for (t=1; t<=T; t++)
	{
		printf("Case #%d: ", t);
		gets(s);
		for (i=0; s[i]; i++)
			if (s[i]==' ') printf(" ");
			else printf("%c", cg[(int)s[i]]);
		puts("");
	}
	return 0;
}