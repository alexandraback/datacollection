#include<bits/stdc++.h>
using namespace std;
const int MAXN=10;

char a[MAXN];
char k[MAXN],wz[MAXN];

int odp=0;
int mx=0;
int k1,l,s;
int sprawdzaj(){
	int wyn=0;
	for(int i=1;i+l-1<=s;i++){
		int ok=1;
		for(int j=1;j<=l;j++){
			if(a[i+j-1]!=wz[j]) {ok=0;break;}
		}
		wyn+=ok;
	}
	//printf("%s %d\n",a+1,wyn);
	odp+=wyn;
	mx=max(mx,wyn);
	return wyn;
}

int szukaj(int pos){
	if(pos>s) return sprawdzaj();
	for(int i=1;i<=k1;i++) {
		a[pos]=k[i];
		szukaj(pos+1);
	}
	return 0;
}

main(){
	int test;scanf("%d",&test);
	for(int testn=1;testn<=test;testn++){
		scanf("%d%d%d",&k1,&l,&s);
		scanf("%s",k+1);
		scanf("%s",wz+1);
		odp=0;
		mx=0;
		szukaj(1);
		long double kk=odp;
		int pot=1;
		for(int i=1;i<=s;i++) pot*=k1;
		kk/=(long double)(pot);
		//printf("%lld %lld\n",odp,mx);
		long double odpp=mx-kk;
		printf("Case #%d: %.9Lf\n",testn,odpp);
	}
}
	
	
