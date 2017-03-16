#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	char a[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	int t,j;
	char s[105];char c;
	scanf("%d%c",&t,&c);
	for(int i=1;i<=t;++i){
		gets(s);
		for(int j=0;j<strlen(s);++j)
			if(s[j]!=' ')
				s[j]=a[s[j]-'a'];
		printf("Case #%d: %s\n",i,s);
	}
	return 0;
}