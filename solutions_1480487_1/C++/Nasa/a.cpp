#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int mx,t,u,n,i,j,k,a[201],b[201],s,ss;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i];
		s=0; for (i=0; i<n; i++) s+=a[i];
		for (i=0; i<n; i++) b[i]=a[i]; 
		sort(b,b+n);
		for (ss=i=0; i<n&&ss+s>=b[i]*i; ss+=b[i++]);
		double avg=((double)ss+s)/i;
		mx=a[0]; for (i=1; i<n; i++) mx=max(mx,a[i]);
		cout<<"Case #"<<(u+1)<<":";
		for (i=0; i<n; i++)
			printf(" %.08lf",(a[i]>avg?0.0:max(0.0,100.0*(avg-a[i])/s)));
		cout<<endl;
	}
	return 0;
}
