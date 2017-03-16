#include<cstdio>
#include<cstring>
int len,T;
char c[30],s[5][1000],ss[5][1000],sss[1000];
int main(){
	sprintf(s[0],"ejp mysljylc kd kxveddknmc re jsicpdrysi");
	sprintf(s[1],"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	sprintf(s[2],"de kr kd eoya kw aej tysr re ujdr lkgc jv");

	sprintf(ss[0],"our language is impossible to understand");
	sprintf(ss[1],"there are twenty six factorial possibilities");
	sprintf(ss[2],"so it is okay if you want to just give up");
	for (int i=0; i<3; i++){
		len=strlen(s[i]);
		for (int j=0; j<len; j++){
			if (s[i][j]>='a'&&s[i][j]<='z') c[s[i][j]-'a']=ss[i][j];
		}
	}
	c[25]='q';
	c['q'-'a']='z';
	scanf("%d",&T);
	gets(sss);
	for (int o=1; o<=T; o++){
		gets(sss);
		len=strlen(sss);
		printf("Case #%d: ",o);
		for (int i=0; i<len; i++)
		    if (sss[i]>='a'&&sss[i]<='z') printf("%c",c[sss[i]-'a']);
		    else printf("%c",sss[i]);
		printf("\n");
	}
	scanf("\n");
	return 0;
}
