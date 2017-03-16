#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
char a1[]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
char a2[]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char a3[]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
char b1[]="our language is impossible to understand";
char b2[]="there are twenty six factorial possibilities";
char b3[]="so it is okay if you want to just give up";
int Map[100];
int s[26];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	Map['z'-'a'] = 'q' -'a'; s['q'-'a'] = 1;
	Map['a'-'a'] = 'y' -'a'; s['y'-'a'] = 1;
	Map['o'-'a'] = 'e' -'a'; s['e'-'a'] = 1;
	Map['q'-'a'] = 'z' -'a';
	int i,j,k,T,ca=1;
	for(j=0;a1[j];j++)
		if(a1[j] <='z' && a1[j]>='a')Map[a1[j] - 'a' ] = b1[j] - 'a' , s[b1[j] - 'a'] = 1;
	for(j=0;a2[j];j++)
		if(a2[j] <='z' && a2[j]>='a')Map[a2[j] - 'a' ] = b2[j] - 'a' , s[b2[j] - 'a'] = 1;
	for(j=0;a3[j];j++)
		if(a3[j] <='z' && a3[j]>='a')Map[a3[j] - 'a' ] = b3[j] - 'a' , s[b3[j] - 'a'] = 1;
	char str[1000];

	cin>>T;
	scanf("%*c");
	while(T-- && gets(str)){
		printf("Case #%d: ",ca++);
		for(i=0;str[i];i++){
			if(str[i]>='a' &&str[i]<='z') printf("%c",Map[str[i] - 'a'] +'a');
			else printf("%c",str[i]);
		}
		printf("\n");
	}

}