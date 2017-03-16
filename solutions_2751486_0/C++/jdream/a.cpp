#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
char s[1010000];
int a[1010000],n,T,TT,i,x,num,j,tot,A[1010000];
LL ans;
int main(){
	freopen("aa.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=1;i<=n;i++)
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||
			s[i]=='u')a[i]=0;else a[i]=1;
		scanf("%d",&num);
		x=0;
		memset(A,0,sizeof(A));tot=0;
		for(i=1;i<=n;i++){
			if(a[i])x++;else x=0;
			if(x>=num){
				A[++tot]=i-num+1;
				x=num;
			}
		}
		ans=0;
		for(j=1,i=1;i<=n;i++){
			while(j<=tot&&A[j]<i)j++;
			if(j<=tot)ans+=n-(A[j]+num-1)+1;
		}
		printf("Case #%d: %I64d\n",T,ans);
	}
}