#include <cstdio>
#include <cstring>

char s[1000];
char T[256];
char s1[]="zqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char s2[]="qzour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(int i=0;i<strlen(s1);i++)T[s1[i]]=s2[i];
	for(char i='a';i<='z';i++)if(T[i]==0){
		printf("%c\n",i);	
	}
	int cases;
	scanf("%d",&cases);
	gets(s);
	for(int casenum=1;casenum<=cases;casenum++){
		gets(s);
		for(int i=0;i<strlen(s);i++)s[i]=T[s[i]];
		printf("Case #%d: ",casenum);
		printf("%s\n",s);
	}
	return 0;
}