#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int t,o,tot;
ll i,j,k,A,B;
ll s[100011],Pow[17];
ll odd(ll x){
	ll i,k,o;
	for (o=1,i=x,k=0;i;k=k*10+i%10,i/=10,o*=10);
	o/=10;
	k%=o;
	return x*o+k;
}
ll even(ll x){
	ll i,k,o;
	for (o=1,i=x,k=0;i;k=k*10+i%10,i/=10,o*=10);
	return x*o+k;
}
bool isfair(ll x){
	ll i,k;
	for (i=x,k=0;i;k=k*10+i%10,i/=10);
	return x==k;
}
int main(){
	Pow[0]=1;
	for (i=1;i<17;i++)Pow[i]=Pow[i-1]*10;
	for (i=1;i<=9;i++)
		if (i&1)
			for (j=Pow[(i+1)/2-1];j<Pow[(i+1)/2];j++){
				k=odd(j);
				if (isfair(k*k))s[++tot]=k*k;
			}
		else
			for (j=Pow[(i+1)/2-1];j<Pow[(i+1)/2];j++){
				k=even(j);
				if (isfair(k*k))s[++tot]=k*k;
			}
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&t);
	for(o=1;o<=t;o++){
		cin>>A>>B;
		A--;
		A=upper_bound(s,s+tot,A)-s;
		B=upper_bound(s,s+tot,B)-s;
		cout<<"Case #"<<o<<": "<<B-A<<endl;
	}
	return 0;
}
