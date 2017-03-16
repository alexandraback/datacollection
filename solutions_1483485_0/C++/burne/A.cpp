#include<cstdio>
#include<string.h>
using namespace std;
char s[300];
char ss[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int cas;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&cas);
	gets(s);
	for(int ca=1;ca<=cas;ca++){
		gets(s);
		int len=strlen(s);
		printf("Case #%d: ",ca);
		for(int i=0;i<len;i++){
			if(s[i]>='a'&&s[i]<='z')printf("%c",ss[s[i]-'a']);
			else printf("%c",s[i]);	
		}
		printf("\n");
	}
}
