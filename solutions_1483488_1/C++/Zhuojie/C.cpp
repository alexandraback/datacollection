#include<cstdio>
#include<cstring>

using namespace std;

int T,I=0;
int a,b;
char s[100];
int p10[10];
int n;

int check(int k,int a,int b){
	int c=0,p=k;
	for (int i=0;i<n;++i){
		k=k/10+k%10*p10[n];
		if (k>=a && k<p)
			++c;
		if (k==p)
			break;
	}
	return c;
}

int main(){
	p10[0]=1;
	for (int i=1;i<10;++i)
		p10[i]=p10[i-1]*10;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&a,&b);
		sprintf(s,"%d",a);
		n=strlen(s)-1;
		int ans=0;
		for (int i=a;i<=b;++i)
			ans+=check(i,a,b);
		printf("Case #%d: %d\n",++I,ans);
	}
}
