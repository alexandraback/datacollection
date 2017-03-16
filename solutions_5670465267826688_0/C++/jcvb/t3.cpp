#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,x;
char s[11111];
typedef long long ll;
int ta[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int ss[4][4]={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};
struct num{
	int sg,id;
};
num one,ii,jj,kk;
num operator*(num a,num b){
	int s=a.sg*b.sg*ss[a.id][b.id];
	return (num){s,ta[a.id][b.id]};
}
num operator-(num a){
	return (num){a.sg*-1,a.id};
}
int operator==(num a,num b){
	return a.sg==b.sg && a.id==b.id;
}
num pre[11111];
num suf[11111];

num qp(num a,ll b){
	num ans=one;
	do{if(b&1)ans=ans*a;a=a*a;}while(b>>=1);
	return ans;
}

int main()
{
	freopen("me.in","r",stdin);
	freopen("me.out","w",stdout);
	one=(num){1,0};
	ii=(num){1,1};
	jj=(num){1,2};
	kk=(num){1,3};
	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		cin>>n>>x;		
		scanf("%s",s+1);
		pre[0]=one;
		for (int i=1;i<=n;i++){
			if(s[i]=='i')pre[i]=ii;
			else if(s[i]=='j')pre[i]=jj;
			else if(s[i]=='k')pre[i]=kk;
		}
		suf[n+1]=one;
		for (int i=n;i>=1;i--)suf[i]=pre[i]*suf[i+1];
		for (int i=1;i<=n;i++)pre[i]=pre[i-1]*pre[i];
		num res=qp(pre[n],x);
		num tar=(ii*jj)*kk;
		int ok=1;
		if(!(res==tar)){
			ok=0;
		}
		if(ok){
			ll mi=(ll)1e18;
			ll ma=0;
			num p=one;
			for (int i=1;i<=4 && i<=x;i++){
				for (int j=0;j<=n;j++)if(p*pre[j]==ii){
					mi=min(mi,1ll*(i-1)*n+j);
					break;
				}
				p=p*pre[n];
			}
			p=one;
			for (ll i=x;i>=1 && i>=x-4+1;i--){
				for (int j=n+1;j>=1;j--)if(suf[j]*p==kk){
					ma=max(ma,(i-1)*n+j);
					break;
				}
				p=suf[1]*p;
			}
			if(mi>=ma)ok=0;
		}
		if(ok)printf("Case #%d: YES\n",tt);
		else printf("Case #%d: NO\n",tt);
	}
}
