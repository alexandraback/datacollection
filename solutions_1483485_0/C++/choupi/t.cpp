#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int i, T, t;
	char a[26];
	char c;
	char inp[110];
	char *enc="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char *org="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	for(i=0;i<strlen(enc);i++) 
		if(enc[i]>='a' && enc[i]<='z') a[enc[i]-'a']=org[i];
	a['z'-'a']='q';
	a['q'-'a']='z';
//	for(i=0;i<26;i++) printf("%c)%c ",i+'a',a[i]);
	scanf("%d", &T);
	cin.getline(inp,110);
	for(t=0;t<T;t++) {
		cin.getline(inp,110);
		printf("Case #%d: ", t+1);
		for(i=0;i<strlen(inp);i++) 
			printf("%c", inp[i]==' '?' ':a[inp[i]-'a']);
		printf("\n");
	}
}
