#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long fac[100];
int main(){
freopen("B-large (1).in","r",stdin); 
freopen("B-large (1).out","w",stdout);
fac[1]=1;
for(int y=2;y<=40;y++)fac[y]=fac[y-1]*y,fac[y]%=1000000007;
      int tc,ii;
scanf("%d",&tc);
for(ii=1;ii<=tc;ii++){
    printf("Case #%d: ",ii);
    int n,i,j;
    int v[1000];
    char s[105][105];
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
		for(j=0;j<=99;j++)s[i][j]=0;
		scanf("%s",s[i]);
		v[i]=0;
	}
	int start=100,end=100;
	int b[30000]; for(i=0;i<=29999;i++)b[i]=0;
	int g[200][2],no=0;
	b[100]=1;
	v[1]=1;
	for(i=1;i<=201;i++){
		int par=0;
		for(j=1;j<=n;j++){
			if(v[j]==0){
				if(s[j][strlen(s[j])-1]==s[b[start]][0]&&s[j][0]==s[j][strlen(s[j])-1]){
					par=1;
					start--;
					b[start]=j;
					v[j]=1;
				}
			}
		}
		for(j=1;j<=n;j++){
			if(v[j]==0&&par==0){
				if(s[j][0]==s[b[end]][strlen(s[b[end]])-1]&&s[j][0]==s[j][strlen(s[j])-1]){
					par=1;
					end++;
					b[end]=j;
					v[j]=1;
				}
			}
		}
		for(j=1;j<=n;j++){
			if(v[j]==0&&par==0){
				if(s[j][strlen(s[j])-1]==s[b[start]][0]){
					par=1;
					start--;
					b[start]=j;
					v[j]=1;
				}
			}
		}
		for(j=1;j<=n;j++){
			if(v[j]==0&&par==0){
				if(s[j][0]==s[b[end]][strlen(s[b[end]])-1]){
					par=1;
					end++;
					b[end]=j;
					v[j]=1;
				}
			}
		}
		if(par==0){
			for(j=1;j<=n;j++){
		    	if(v[j]==0){
					no++;
					g[no][0]=start;
					g[no][1]=end;
					start=end=end+101;
					b[start]=j;
					v[j]=1;
					break;
				}
			}
		}
	}
	no++;
	g[no][0]=start;
	g[no][1]=end;
	char c=0;
	int f[200];for(i='a';i<='z';i++)f[i]=0;
	int noans=0;
	for(i=0;i<=30000;i++){
		if(b[i]!=0){
			int z=b[i];
			for(j=0;j<strlen(s[z]);j++){
				if(s[z][j]!=c)f[c]=-1;
				if(f[s[z][j]]==-1)noans=1;
				c=s[z][j];
			}
		}
	}
	int cnt[100];
	long long ans=1;
	for(i=1;i<=no;i++){ans*=i,ans%=1000000007;
		int sta=g[i][0],en=g[i][1];
		int r[100];
		for(j=sta;j<=en;j++){
			if(s[b[j]][0]==s[b[j]][strlen(s[b[j]])-1])r[j-sta+1]=s[b[j]][0];
			else r[j-sta+1]=0;
			//printf("%s \n",s[b[j]]);
		}
		int tp=1;
		for(j=2;j<=en-sta+1;j++){
			if(r[j]!=r[j-1])ans*=fac[tp],ans%=1000000007,tp=1;
			else if(r[j]!=0)tp++;
		}
		ans*=fac[tp],ans%=1000000007;
			
	}
     if(noans==1)printf("0\n");
     else printf("%lld\n",ans);
}



return 0;
}
		
