#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int m[30];
bool is[30];
void initail(){
	int i;
	char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	char b[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	char c[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char aa[] = "our language is impossible to understand";
	char ab[] = "there are twenty six factorial possibilities";
	char ac[] = "so it is okay if you want to just give up";
	memset(m,0xff,sizeof(m));
	memset(is,0,sizeof(is));
	m['y'-'a'] = 'a'-'a';
	is['a'-'a'] = 1;
	m['q'-'a'] = 'z'-'a';
	is['z'-'a'] = 1;
	m['e'-'a'] = 'o'-'a';
	is['o'-'a'] = 1;
	for (i = 0;i < strlen(a);i++){
		if (a[i] != ' '){
			m[a[i]-'a'] = aa[i]-'a';
			is[ aa[i]-'a'] = 1;
		}
	}
	for (i = 0;i < strlen(b);i++){
		if (b[i] != ' '){
			m[b[i]-'a'] = ab[i]-'a';
			is[ab[i]-'a'] = 1;
		}
	}
	for (i = 0;i < strlen(c);i++){
		if (c[i] != ' '){
			m[c[i]-'a'] = ac[i]-'a';
			is[ac[i]-'a'] = 1;
		}
	}
	for (i = 0;i < 26;i++){
		if (!is[i]){
			m['z'-'a'] = i;
		}
	}
}
int main()
{
	char s[256];
	initail();
	int t,i,j;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(i = 0;i < t;i++){
		cin.getline(s,256,'\n');
		if (strlen(s) == 0){
			i --;
			continue;
		}
		for (j = 0;j < strlen(s);j++){
			if (s[j] == ' ' )
				continue;
			s[j] = 'a'+m[s[j]-'a'];
		}
		printf("Case #%d: %s\n",i+1,s);
	}
	return 0;
}