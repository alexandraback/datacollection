#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,po[11][32],curr;
	for(i=2;i<11;i++){
		po[i][0]=1;
		for(j=1;j<32;j++)po[i][j]=po[i][j-1]*i;
	}
	cin>>t;
	cout<<"Case #1: \n";
	vector<long long> v;
	for(te=0;te<t;te++){
		cin>>n>>m;
		for(i=ans=0;i<po[2][16] && ans<m;i++){
			v.clear();
			for(j=2;j<11;j++){
				for(k=curr=0;k<16;k++){
					if(i&po[2][k])curr+=po[j][k];
				}
				for(k=2;(k*k)<=curr;k++)if((curr%k)==0)break;
				if((k*k)>curr)break;
				v.push_back(k);
			}
			if(j==11 && (i&po[2][0]) && (i&po[2][n-1])) {
				ans++;
				for(k=n-1;k>=0;k--)cout<<((i&po[2][k])?'1':'0');
				for(k=0;k<v.size();k++)cout<<" "<<v[k];
				cout<<"\n";
			}
		}
	}
	return 0;
}