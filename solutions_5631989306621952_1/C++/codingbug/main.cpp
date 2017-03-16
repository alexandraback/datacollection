#include <bits/stdc++.h>
#define M 1000

using namespace std;

char s[M+2],st[M+2];
bool ck[M+1];
int n,tp;

void input(void){
	scanf("%s",s+1);
	n=strlen(s+1);
}

void process(void){
	int i;
	st[tp=1]=s[1];
	for(i=2;i<=n;i++){
		if(ck[i]=(st[tp]<=s[i])) st[++tp]=s[i];
	}
	for(;tp;)printf("%c",st[tp--]);
	for(i=2;i<=n;i++) if(!ck[i]) printf("%c",s[i]);
}

int main(void){
	freopen("input.txt","r",stdin);

	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		input();
		printf("Case #%d: ",i);
		process();
		printf("\n");
	}
	return 0;
}
