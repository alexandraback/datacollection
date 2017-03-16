#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 110
using namespace std;
char in[MAX];
char a[]="yhesocvxduiglbkrztnwjpfmaq";
int main(){
	int T;
	int ca=1;
	scanf("%d",&T);
	gets(in);
	while(T--){
		gets(in);
		int len=strlen(in);
		for(int i=0;i<len;i++){
			if('a'<=in[i] && in[i]<='z')
				in[i]=a[in[i]-'a'];
		}
		printf("Case #%d: %s\n",ca++,in);
	}
	return 0;
}
