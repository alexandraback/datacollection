#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,r,c,w,d,v,arr[6],dp[31];
	cin>>t;
	for(te=0;te<t;te++){
		cin>>c>>d>>v;
		for(i=0;i<d;i++)cin>>arr[i];
		for(i=0;i<=v;i++)dp[i]=0;
		dp[0]=1;
		for(i=0;i<d;i++){
			for(j=(v-arr[i]);j>=0;j--)if(dp[j]==1)dp[j+arr[i]]=1;
		}
		for(i=1,m=0;i<=v;i++){
			if(dp[i]==0){
				m++;
				for(j=(v-i);j>=0;j--)if(dp[j]==1)dp[j+i]=1;
			}
		}
		cout<<"Case #"<<(te+1)<<": "<<m<<"\n";
	}
}
