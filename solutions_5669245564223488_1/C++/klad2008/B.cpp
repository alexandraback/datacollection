#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
using namespace std;
const LL pp=1000000007;
LL st[1010],ne[1010],go[1010];
LL pt,T,N,sum,ans;
LL use[1010],in[1010];
bool uu[1010];
bool ok[1010],tr[1010];
char s[1010][1010];
bool flag;
void Add(LL x,LL y){ne[++pt]=st[x];st[x]=pt;go[pt]=y;}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%I64d",&T);
	for (LL tt=1;tt<=T;tt++){
		memset(st,0,sizeof(st));
		memset(ne,0,sizeof(ne));
		memset(go,0,sizeof(go));
		pt=N=sum=ans=0;
		memset(use,0,sizeof(use));
		memset(in,0,sizeof(in));
		memset(uu,0,sizeof(uu));
		memset(ok,0,sizeof(ok));
		memset(tr,0,sizeof(tr));
		flag=false;
		scanf("%I64d\n",&N);for (LL i=1;i<=N;i++)scanf("%s",s[i]);scanf("\n");
		flag=true;
		memset(ok,0,sizeof(ok));
		for (LL i=1;i<=N&&flag;i++){
			LL ll=strlen(s[i]);memset(use,0,sizeof(use));
			for (LL j=0;j<ll;j++)if (j&&use[s[i][j]]&&s[i][j-1]!=s[i][j]){flag=false;break;}else use[s[i][j]]=1;
			sum=0;for (LL j=0;j<256;j++)if (use[j])sum++;if (sum==1)ok[i]=1;
		}//直接特判单个无解情况 
		if (!flag){printf("Case #%I64d: 0\n",tt);continue;}
		memset(st,0,sizeof(st));pt=0;
		for (LL i=1;i<=N;i++)
		for (LL j=1;j<=N;j++)
		if (!ok[i]&&!ok[j]){
			LL l1=strlen(s[i]);
			if (s[i][l1-1]==s[j][0])Add(i,j),in[j]++;
		}//将能连接的连接，不是链直接无解 
		for (LL i=1;i<=N;i++)if (in[i]>1){flag=false;break;}
		if (!flag){printf("Case #%I64d: 0\n",tt);continue;}
		memset(tr,0,sizeof(tr));memset(use,0,sizeof(use));
		sum=0;ans=1;
		for (LL i=1;i<=N;i++)
		if (!in[i]&&!tr[i]&&!ok[i]){
			sum++;LL x=i;tr[x]=true;
			memset(uu,0,sizeof(uu));
			while (true){
				bool rr=true;
				LL ll=strlen(s[i]);
				for (LL j=0;j<ll;j++)uu[s[i][j]]=true;
				for (LL j=st[x];j;j=ne[j])
				if (in[go[j]]==1){in[go[j]]--;tr[go[j]]=1;x=go[j];rr=false;break;}
				if (rr)break;
			}
			for (LL j=0;j<256;j++)
			if (uu[j]&&use[j]){flag=false;break;}
			for (LL j=0;j<256;j++)use[j]|=uu[j];
		}
		//尝试连接 
		for (LL i=1;i<=N;i++)if (!ok[i]&&!tr[i]){flag=false;break;}
		if (!flag){printf("Case #%I64d: 0\n",tt);continue;}
		memset(use,0,sizeof(use));
		for (LL i=1;i<=N;i++)if (ok[i])use[s[i][0]]=true;
		for (LL i=1;i<=N;i++)
		if (!ok[i]){
			LL ll=strlen(s[i]),l=0,r=ll-1;
			while (l<ll&&s[i][0]==s[i][l])l++;
			while (r>=0&&s[i][ll-1]==s[i][r])r--;
			for (LL k=l;k<=r;k++)if (use[s[i][k]]){flag=false;break;}
			for (LL k=l;k<=r;k++)use[s[i][k]]=true;
		}
		//判断是否有单字符链被别的包含的无解情况 
		if (!flag){printf("Case #%I64d: 0\n",tt);continue;}
		memset(use,0,sizeof(use));
		for (LL i=1;i<=N;i++)if (ok[i])use[s[i][0]]++,tr[i]=true;
		for (LL i=0;i<256;i++)
		if (use[i]>0){
			LL s1=0,s2=0;
			for (LL j=1;j<=N;j++)
			if (!ok[j]){
				LL ll=strlen(s[j]);
				if (s[j][0]==i)s1++;
				if (s[j][ll-1]==i)s2++;
			}
			if (s1>1||s2>1){flag=false;break;}
			if (s1==0&&s2==0)sum++;
		}
		if (!flag){printf("Case #%I64d: 0\n",tt);continue;}
		//判断单字符链是否有确定被连接的位置
		for (LL j=1;j<=sum;j++)ans=ans*j%pp;
		for (LL i=0;i<256;i++)
		for (LL j=1;j<=use[i];j++)ans=ans*j%pp;
		//计算答案 
		printf("Case #%I64d: %I64d\n",tt,ans);
	}
}
