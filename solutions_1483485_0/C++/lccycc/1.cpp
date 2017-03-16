#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <assert.h>
using namespace std;
const char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
const char b[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
char map[300];
char ye[300]="ynficwlbkuomxsevzpdrjgathaq";
int num[26];
int main()
{
	freopen("out.out","w",stdout);
	freopen("A-small-attempt1.in","r",stdin);
	int i,j;
	for (i=0;i<strlen(a);i++)
		map[a[i]] = b[i];
	map['y']='a';
	map['e']='o';
	map['q']='z';
/*	for (i=0;i<26;i++)
		if (map[i+'a']!=0)
			num[i]++;
	for (i=0;i<26;i++)
		cout<<char('a'+i)<<' '<<num[i]<<endl;
*/
	map['z']='q';
//	for (i=0;i<strlen(ye);i++)
//		map[ye[i]]=i+'a';
//	map[' '] = ' ';
	int n;
//	for (char c='a';c<='z';c++)
//		cout<<c<<' '<<map[c]<<endl;
	scanf("%d\n",&n);
	for (j=1;j<=n;j++)
	{
		char s[20000];
		gets(s);
		printf("Case #%d: ",j);
		int len=strlen(s);
		for (i=0;i<len;i++)
		{
	//		assert(map[s[i]]!=0);
			s[i] = map[s[i]];	
			putchar(s[i]);
		}
		puts("");
	}
	return 0;
}
