#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define fri(n) for(lli i=0;i<n;i++)
#define frin(i,n) for(lli i=1;i<=n;i++)
lli a[100001];
int main(){
	freopen("A-large.in","r",stdin);
	freopen("out1.txt","w",stdout);
	lli t,m,sum;
	cin>>t;
	for(lli k=1;k<=t;k++){
	lli	r,c,w;
	cin>>r>>c>>w;
	m=c/w;
	sum=m;
	m*=r;
	m+=(w-1);
	if((c%w)!=0)
	m++;
	
		cout<<"Case #"<<k<<": "<<m<<endl;
	}
}
