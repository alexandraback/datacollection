#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>

using namespace std;

char s[10005],p[10005],q[10005],tail1,tail2;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%s",s);
		tail1=tail2=0;
		p[++tail1]=s[0];
		int len=strlen(s);
		for(int i=1;i<len;i++){
			if(s[i]>=p[tail1])
				p[++tail1]=s[i];
			else
				q[++tail2]=s[i];
		}
		printf("Case #%d: ",cas);
		while(tail1>0)
			printf("%c",p[tail1--]);
		q[++tail2]=0;
		printf("%s",q+1);
		printf("\n");
	}
	return 0;
}
