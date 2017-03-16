#include<cstring>
#include<cstdio>
char s[2500],ss[2500];
int main(){
	freopen("A-large.bin","r",stdin);
        freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	char *p;
	int i;
	for(int cas=1;cas<=t;cas++){
		scanf("%s",s);
		p=ss+1200;
		memset(ss,0,sizeof ss);
		*p=s[0];
		for(i=1;s[i];i++){
			if(s[i]>=*p)*--p=s[i];
			else *(p+i)=s[i];
		}
		printf("Case #%d: %s\n",cas,p);
	}
}
