#include<cstdio>
#include<cstring>
#include<cctype>
const char *s="yhesocvxduiglbkrztnwjpfmaq";
char c[1111];
int main(){
	int n,i,len,j;
//	freopen("a.in","r",stdin);
//	freopen("a.txt","w",stdout);
	scanf("%d",&n);
	gets(c);
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		gets(c);
		len=strlen(c);
		for (j=0;j<len;j++){
			if (isalpha(c[j])){
				printf("%c",s[c[j]-'a']);
			} else printf("%c",c[j]);
		}
		puts("");
	}
	return 0;
}
