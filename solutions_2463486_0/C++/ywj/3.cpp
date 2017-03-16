#include<stdio.h>
#include<string.h>

int f[1010];
char num[110];

bool is_palindrome(char str[]){
	int len=strlen(str);
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(num[i]!=num[j])return false;
	}
	return true;
}

void init(){
	for(int i=0;i<1010;i++){
		f[i]=0;
	}
	for(int i=1;i<32;i++){
		sprintf(num,"%d",i);
		if(!is_palindrome(num))continue;
		int x=i*i;
		sprintf(num,"%d",x);
		if(is_palindrome(num))f[x]=1;
	}
	for(int i=1;i<1001;i++){
		f[i]+=f[i-1];
	}
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int T;
	scanf("%d",&T);
	init();
	for(int Case=1;Case<=T;Case++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",Case,f[b]-f[a-1]);
	}
	return 0;
}