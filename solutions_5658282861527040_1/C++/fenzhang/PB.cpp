#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long int lnt;
typedef double dou;
int a,b,c;
int dd[2000];
#include<map>
map<int,lnt>lg;

lnt f(int ta,int la,int tb,int lb,int tc,int lc){
	if(la>lb){swap(la,lb);swap(ta,tb);}
	int fil=max(la,max(lb,lc));
	int thl=min(la,min(lb,lc));
	int sel=la+lb+lc-fil-thl;
	if(((ta>>fil)&(tb>>fil))!=(tc>>fil))return 0;
	lnt ans=1;
	if(lc==fil){
		ans*=1;
		ans*=(1ll<<sel-thl);
		ans*=(1ll<<thl*2);
	}
	else if(lc==sel){
		for(int i=sel;i<fil;i++){
			if((ta&(1ll<<i))==0&&(tc&(1ll<<i))==0){
				ans*=2ll;
			}
			if((ta&(1ll<<i))==0&&(tc&(1ll<<i))!=0){
				ans*=0ll;
			}
			if((ta&(1ll<<i))!=0&&(tc&(1ll<<i))==0){
				ans*=1ll;
			}
			if((ta&(1ll<<i))!=0&&(tc&(1ll<<i))!=0){
				ans*=1ll;
			}
		}
		ans*=(1ll<<sel-thl);
		ans*=(1ll<<thl*2);
	}
	else{
		for(int i=sel;i<fil;i++){
			if((ta&(1ll<<i))==0&&(tc&(1ll<<i))==0){
				ans*=2ll;
			}
			if((ta&(1ll<<i))==0&&(tc&(1ll<<i))!=0){
				ans*=0ll;
			}
			if((ta&(1ll<<i))!=0&&(tc&(1ll<<i))==0){
				ans*=1ll;
			}
			if((ta&(1ll<<i))!=0&&(tc&(1ll<<i))!=0){
				ans*=1ll;
			}
		}
		for(int i=thl;i<sel;i++){
			if((tc&(1ll<<i))==0){
				ans*=3ll;
			}
			if((tc&(1ll<<i))!=0){
				ans*=1ll;
			}
		}
		ans*=(1ll<<thl*2);
	}
	return ans;
}
void sol(int uuu){
	scanf("%d %d %d",&a,&b,&c);
	/*
	for(int k=0;k<2000;k++){
		dd[k]=0;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			dd[i&j]++;
		}
	}
	lnt ans=0;
	for(int k=0;k<c;k++){
		ans=ans+dd[k];
	}
	
	printf("Case #%d: %I64d\n",uuu,ans);
	*/
	lnt ans2=0;
	for(int ta=a;ta;){
		int la=lg[ta&-ta];
		ta-=(ta&-ta);
		for(int tb=b;tb;){
			int lb=lg[tb&-tb];
			tb-=(tb&-tb);
			for(int tc=c;tc;){
				int lc=lg[tc&-tc];
				tc-=(tc&-tc);
				ans2=ans2+f(ta,la,tb,lb,tc,lc);
			}
		}
	}
	printf("Case #%d: %I64d\n",uuu,ans2);
	//if(ans!=ans2)puts("jizz");
}

int main(){
	for(int i=0;i<31;i++){
		lg[1<<i]=i;
	}
	freopen("B-large.in","r",stdin);
	freopen("pb_l.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)sol(ti);
	return 0;
}

