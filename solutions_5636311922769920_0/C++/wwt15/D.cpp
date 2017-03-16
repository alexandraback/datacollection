#include <cstdio>

int K,C,S;

void Main(){
	scanf("%d%d%d",&K,&C,&S);
	if(S<K){
		puts("IMPOSSIBLE");
		return;
	}
	for(int i=1;i<=S;i++) printf("%d%c",i,i==S?'\n':' ');
}

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		printf("Case #%d: ",Case);
		Main();
	}
}