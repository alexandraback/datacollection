#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
char TO[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	long i,j,n;
	char c[1003];
	scanf("%ld",&n);
	c[0]=getchar();
	for (j=1;j<=n;++j){
		gets(c);
		for (i=0;c[i]!='\0';++i)
			if (c[i]>='a' && c[i]<='z') c[i]=TO[c[i]-'a'];
		printf("Case #%ld: ",j);
		puts(c);
	}
	return 0;
}

