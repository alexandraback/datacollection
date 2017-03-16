#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=111;

char kk[MAXN],ll[MAXN];


int P[MAXN];

int dp0[MAXN][MAXN];//dl prefiksosuf, indeks kk


void kmp(int l){
	P[0]=P[1]=0;
	for(int i=2;i<=l;i++){
		int t=P[i-1];
		while(t>0&&ll[i]!=ll[t+1]) t=P[t];
		if(ll[i]==ll[t+1]) t++;
		P[i]=t;
	}
}

void liczdp(int l,int k){
	for(int i=0;i<=l;i++){
		for(int j=1;j<=k;j++){
			int t=i;
			while(t>0&&kk[j]!=ll[t+1]) t=P[t];
			if(kk[j]==ll[t+1]) t++;
			dp0[i][j]=t;
		}
	}
}
typedef long double LD;
LD dp[MAXN][MAXN];
//dp[i][j] - w i-tej rundzie jest prefs. j z prawdop. dp[i][j]

LD wynik=0.;

void dynamik(int l,int k,int s){
	dp[0][0]=1.0;
	LD div=(LD)k;
	for(int pp=0;pp<=s;pp++){
		for(int dlp=0;dlp<=l;dlp++){
			for(int ns=1;ns<=k;ns++){
				dp[pp+1][dp0[dlp][ns]]+=(dp[pp][dlp]/div);
			}
		}
		wynik+=dp[pp][l];
	}
}





main(){
	int test;scanf("%d",&test);
	for(int cs=1;cs<=test;cs++){
		int k,l,s;scanf("%d%d%d",&k,&l,&s);
		scanf("%s",kk+1);
		scanf("%s",ll+1);
		for(int i=0;i<=105;i++){
			for(int j=0;j<=105;j++){
				dp0[i][j]=0;
				dp[i][j]=0.;
			}
			P[i]=0;
		}
		wynik=0.;
		kmp(l);
		liczdp(l,k);
		dynamik(l,k,s);
		LD maks=0;
		int ob=0;
		for(int i=1;i<=s;i++){
			int nast=0;
			for(int j=1;j<=k;j++){
				if(dp0[ob][j]>nast) nast=dp0[ob][j];
			}
			ob=nast;
			if(ob==l) maks+=1;
		}
		wynik=maks-wynik;
		
		printf("Case #%d: %.9Lf\n",cs,wynik);
	}
}

