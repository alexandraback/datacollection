#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
long long gcd(long long a,long long b){
	return (a==0?b:gcd(b%a,a));
}
int main(){
	long long a,b,n,f,i,r=1,f2;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	cin>>n;
	while(n--){
		cout<<"Case #"<<r<<": ";
		r++;
		scanf("%lld/%lld",&a,&b);
		f=gcd(a,b);
		a/=f;
		b/=f;
		for(i=0,f=1;i<40;i++,f<<=1) if(f>=b) break;
		if(f==b) {
			for(i=0,f=f2=1;1;i++,f2*=2){
				if(f2*a>=b) break;
			}
			cout<<i<<endl;
		}
		else cout<<"impossible"<<endl;
	}
	return 0;
}