#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,r,c,w,d,v,arr[6],dp[31],x,y;
	cin>>t;
	string keys,tar,s;
	for(te=0;te<t;te++){
		cin>>k>>r>>c>>keys>>tar;
		m=pow(k,c);
		v=y=0;
		for(i=0;i<m;i++){
			s="";
			for(n=i,j=0;j<c;j++,n/=k)s+=keys[n%k];
			x=0;
			for(j=0;j<=(c-r);j++){
				for(w=0;w<r;w++)if(tar[w]!=s[j+w])break;
				if(w==r)x++;
			}
			v=max(v,x);
		}
		for(i=0;i<m;i++){
			s="";
			for(n=i,j=0;j<c;j++,n/=k)s+=keys[n%k];
			x=0;
			for(j=0;j<=(c-r);j++){
				for(w=0;w<r;w++)if(tar[w]!=s[j+w])break;
				if(w==r)x++;
			}
			y+=(v-x);
		}
		cout<<"Case #"<<(te+1)<<": ";
		printf("%.8lf\n",((double)y)/(double)m);
	}
}
