#include<stdio.h>
#include<string.h>
#define M 1000000007
int type[26][4];
int to[26][26];
long long fact[101];
char s[101];
//0:all 
//1:prefix
//2:suffix
//3:center

void classify(){
	int n=strlen(s);
	int a=0;
	int pre=-1,suf=-1;
	while(a<n){
		char c=s[a];
		int p=a;
		while(s[a]==c)a++;
		if(p==0&&a==n)type[c-'a'][0]++;
		else if(p==0){
			type[c-'a'][1]++;
			pre=c-'a';
		}
		else if(a==n){
			type[c-'a'][2]++;
			suf=c-'a';
		}
		else type[c-'a'][3]++;
	}
	if(pre!=-1&&suf!=-1)to[pre][suf]++;
}

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int n,i,j;
		fact[0]=1;
		for(i=1;i<=100;i++)fact[i]=(fact[i-1]*i)%M;
		for(i=0;i<26;i++)for(j=0;j<4;j++)type[i][j]=0;
		for(i=0;i<26;i++)for(j=0;j<26;j++)to[i][j]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf(" %s",s);
			classify();
		}
		bool out=false;
		long long ans=1;
		int cnt=0;
		for(i=0;i<26;i++){
			for(j=i;j<26;j++){
				if(to[i][j]>0&&to[j][i]>0)out=true;
			}
		}
		for(i=0;i<26;i++){
			if(type[i][1]>1)out=true;
			if(type[i][2]>1)out=true;
			if(type[i][3]>1)out=true;
			if(type[i][3]==1&&(type[i][0]+type[i][1]+type[i][2]>0))out=true;
			if(type[i][1]==0){
				if(type[i][2]==0){
					ans=(ans*fact[type[i][0]])%M;
					if(type[i][0]>0)cnt++;
				}
				if(type[i][2]==1){
					ans=(ans*fact[type[i][0]])%M;
					cnt++;
				}
			}
			if(type[i][1]==1)ans=(ans*fact[type[i][0]])%M;
		}
		printf("Case #%d: ",di+1);
		if(out)puts("0");
		else printf("%lld\n",(ans*fact[cnt])%M);
	}
	return 0;
}