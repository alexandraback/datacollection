#include<cstdio>
#include<cstring>
#define LL long long
#define mod 1000000007
using namespace std;
/*bool check(){
	for(i=1;i<l;i++)
		if(s[i]==s[0]&&s[i-1]!=s[0]){
			F=1;break;
		}
	for(i=0;i<l-1;i++)
		if(s[i]==s[l-1]&&s[i+1]!=s[l-1]){
			F=1;break;
		}
}*/
int fa[128],F,TT,T,cnt[128],num_all[128],S[128][128],n,N,l,L[128],j;
int NUM,i,x,y,z,be,en;
LL jc[100],ans;
char s[128];
int getfa(int x){
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&TT);
	jc[0]=1;
	for(i=1;i<=100;i++)jc[i]=jc[i-1]*i%mod;
	for(T=1;T<=TT;T++){
		scanf("%d\n",&n);
		printf("Case #%d: ",T);
		F=0;N=0;ans=1;
		memset(num_all,0,sizeof(num_all));
		memset(cnt,0,sizeof(cnt));
		while(n--){
			scanf("%s",s);
			l=strlen(s);
			if(s[0]==s[l-1]){
				for(i=1;i<l;i++)if(s[i]!=s[0])break;
				if(i==l){
					num_all[s[0]-'a']++;
					continue;
				}
			}
			for(i=0;i<l;i++)cnt[s[i]-'a']++;
			L[++N]=l;
			for(i=0;i<l;i++)S[N][i]=s[i]-'a';
		}
		for(i=1;i<=N;i++)fa[i]=i;
		for(i=0;i<26;i++)ans=ans*jc[num_all[i]]%mod;
		F=1;NUM=N;
		for(i=0;i<26;i++){
			be=en=0;
			for(z=1;z<=N;z++){
				if(S[z][0]==i)be=z;
				if(S[z][L[z]-1]==i)en=z;
			}
			getfa(be);getfa(en);
			if(fa[be]==fa[en]&&be>0){F=0;break;}
			if(en==0&&be==0){
				if(cnt[i]>0&&num_all[i]>0){F=0;break;}
				if(num_all[i]>0)NUM++;
				if(cnt[i]>0){
					for(z=1;z<=N;z++){
						for(j=0;j<L[z];j++)if(S[z][j]==i)break;
						if(j<L[z]){
							for(;j<L[z]&&S[z][j]==i;j++)cnt[i]--;
							break;
						}
					}
				}
			}
			
			if(be)for(j=0;j<L[be]&&S[be][j]==i;j++)
				cnt[i]--;
			if(en)for(j=L[en]-1;j>=0&&S[en][j]==i;j--)
				cnt[i]--;
			if(cnt[i]){F=0;break;}
			
			if(be&&en){
				x=getfa(be);y=getfa(en);
				x=getfa(be);y=getfa(en);
				fa[x]=y;NUM--;
			}
		}
		if(!F){printf("0\n");continue;}
		ans=ans*jc[NUM]%mod;
		printf("%d\n",ans);
		/*
			a[i][s[0]-'a']|=1;
			a[i][s[l-1]-'a']|=2;
			for(i=1;i<l-1;i++)
				if(s[i]!=s[0]&&s[i]!=s[l-1])
					flag[s[i]-'a']=1;
			
			if(check())F=1;
			
		}
		if(F){
			printf("0\n");continue;
		}
		for(i=0;i<26;i++)if(flag[i]){
			
		}
		
		ans=1;
		*/
	}
}
