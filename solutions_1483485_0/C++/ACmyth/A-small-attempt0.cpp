#include<iostream>
#include<cstdio>
#include<cstring>
char change[27]={"yhesocvxduiglbkrztnwjpfmaq"};
char str[100010];
int main()
{
	int n;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&n);
	getchar();
	for(int ca=1;ca<=n;ca++){
		memset(str,0,sizeof(str));
		gets(str);
		int l=strlen(str);
		printf("Case #%d: ",ca);
		for(int i=0;i<l;i++){
			if(str[i]>='A'&&str[i]<='Z') printf("%c",change[str[i]+32-'a']-32);
			else if(str[i]>='a'&&str[i]<='z') printf("%c",change[str[i]-'a']);
			else printf("%c",str[i]);
		}
		puts("");
	}
	return 0;
}
