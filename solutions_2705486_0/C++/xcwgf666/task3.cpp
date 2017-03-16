#include <cstdio>
#include <algorithm>
using namespace std;

int i,ls[521196+10],tqn,tqi,F[4404][6],n,j,wi,lm,fail,k,mmatch,ans;
char A[521196+10][40],s[4404];

int main(){
	freopen("dict.txt","r",stdin);
	for(i=1;i<=521196;i++){
		gets(A[i]);
		ls[i]=strlen(A[i]);
	}
	freopen("in.txt","r",stdin);	
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	gets(s);
	for(tqi=1;tqi<=tqn;tqi++){
		gets(s);n=strlen(s);
		for(i=n;i;i--)s[i]=s[i-1];
		for(i=0;i<=n;i++)for(j=0;j<=5;j++)F[i][j]=1000000000;
		F[0][5]=0;
		for(i=0;i<=n;i++)for(j=0;j<=5;j++)if(F[i][j]!=1000000000){
			for(wi=1;wi<=521196;wi++)if(i+ls[wi]<=n){
				lm=j;fail=0;
				mmatch=0;
				for(k=0;k<ls[wi]&&!fail;k++){
					++lm;
					if(A[wi][k]!=s[i+1+k]){
						if(lm<5){fail=1;break;}
						++mmatch;
						lm=0;
					}
				}
				if(!fail)F[i+ls[wi]][min(lm,5)]=min(F[i+ls[wi]][min(lm,5)],F[i][j]+mmatch);
			}
		}
		ans=1000000000;
		for(i=0;i<=5;i++)ans=min(ans,F[n][i]);
		printf("Case #%d: %d\n",tqi,ans);
	}
	return 0;
}
