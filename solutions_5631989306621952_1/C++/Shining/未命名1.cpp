#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int TT,l,r;
char s[5000],tp[5000];

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&TT);
	scanf(" ");
	for	(int T=1;T<=TT;++T){
		gets(s);
		l=2000;r=2000;
		tp[l]=s[0];
		for	(int i=1;i<strlen(s);++i)
			if	(s[i]>=tp[l])	tp[--l]=s[i];
			else	tp[++r]=s[i];
		printf("Case #%d: ",T);
		for	(int i=l;i<=r;++i)	printf("%c",tp[i]);
		printf("\n"); 
	}
} 
