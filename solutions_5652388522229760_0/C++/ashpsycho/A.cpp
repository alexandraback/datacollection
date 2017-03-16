#include <bits/stdc++.h>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,po[10];
	po[0]=1;
	for(i=1;i<10;i++)po[i]=2*po[i-1];
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		if(n==0){
			cout<<"Case #"<<(te+1)<<": INSOMNIA\n";
			continue;
		}
		ans=n;
		m=0;
		while(true){
			for(j=ans;j>0;j/=10)m=m|po[j%10];
			if(m==1023)break;
			ans+=n;
		}
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	//	printf("Case #%d: %.9Lf\n",te+1,ans);

	}
	return 0;
}