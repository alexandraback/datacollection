#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long int ll;
int main(){
ll power[]={-1,10,100,1000,10000,100000,1000000,10000000};
int T;
cin>>T;
int tc;
for(tc=1;tc<=T;tc++){
	ll possibs[8];
	memset(possibs,0,sizeof possibs);
	ll a,b,nod=0;
	cin>>a>>b;
	ll ans=0;
	if(a<=9)
		printf("Case #%d: 0\n",tc);
	else
	{
		ll i,j;
		if(a<=99) nod=2;
		else if (a<=999) nod =3;
		else if (a<=9999) nod =4;
		else if (a<=99999) nod =5;
		else if (a<=999999) nod =6;
		else if (a<=2000000) nod = 7;
		
		for(i=a;i<=b;i++){
			possibs[1]=10*(i%power[nod-1])+i/power[nod-1];
			if(possibs[1]>i&&possibs[1]<=b&&possibs[1]>=a) {ans++;}
			for(j=2;j<nod;j++){
				possibs[j]=10*(possibs[j-1]%power[nod-1])+possibs[j-1]/power[nod-1];
				bool t=true;
				for(int k=j-1;k>=1;k--) if(possibs[j]==possibs[k]) t=false;
				if(t)
				if(possibs[j]>i&&possibs[j]<=b&&possibs[j]>=a) {ans++;}
			}	
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
}
return 0;
}
