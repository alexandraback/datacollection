/*
 * Author:Õı”Ì«Ô(jywyq) 
 * Date:20160416
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define LL long long
int fa[1010];
int num(int u){
	int cnt=1;
	int p=u;
	while(fa[p]!=u){
		//printf("%d\n",p);
		p=fa[p];
		cnt++;
		if(cnt>1100)return 0;
	}
	if(fa[p]==u)return cnt;
	else return 0;
}
int nnum(int u,int ff,int ob){
	int cnt=1;
	//int cpu=u;
	while(fa[u]!=ff && fa[u]!=ob){
		u=fa[u];
		cnt++;
		if(cnt>1100)return 0;
	}/*
	while(fa[cpu]!=ff){
		cout<<cpu<<" "<<fa[cpu]<<endl;
		cpu=fa[cpu];
	}
	puts("");*/
	if(fa[u]==ff)return cnt;
	else return 0;
}
bool vis[1010];
int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("dataout.txt","w",stdout);
	int t,cas=0,n;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>fa[i];
		}
		int MA=0,ma2=0;
		for(int i=1;i<=n;i++){
			int k=num(i);
			MA=max(MA,k);
			if(k==2){
				int masa=0;
				int u=i,v=fa[i] ;
				if(vis[u]||vis[v])continue;
				vis[u]=1;vis[v]=1;
				int mau=0,mav=0;
				for(int j=1;j<=n;j++)if(j!=u && j!=v){
					mau=max(mau,nnum(j,u,v));
					mav=max(mav,nnum(j,v,u));
				}
				masa=max(masa,mau+mav);
				//printf("%d %d\n",mau,mav);
				k+=masa;
				ma2+=k;
			}
		}
		
		printf("Case #%d: %d\n",++cas,max(MA,ma2));
		
	}
	
}
