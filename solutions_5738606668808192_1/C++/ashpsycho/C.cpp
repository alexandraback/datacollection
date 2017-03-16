#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,ans,curr,po[11][32];
	po[2][0]=1;
	for(i=1;i<32;i++)po[2][i]=po[2][i-1]*2;
	cin>>t;
	cout<<"Case #1: \n";
	vector<long long> v;
	for(te=0;te<t;te++){
		cin>>n>>m;
		for(i=po[2][n-1]+1,ans=0;ans<m;i+=2){
			v.clear();
			for(j=2;j<11;j++){
				for(k=n-1,curr=0;k>=0;k--){
					curr=curr*j;
					if((i&po[2][k]))curr++;
					curr%=(j+1);
				}
				if(curr!=0)break;
				v.push_back(j+1);
			}
			if(j==11) {
				ans++;
				for(k=n-1;k>=0;k--)cout<<((i&po[2][k])?'1':'0');
				cout<<" 3 2 5 2 7 2 3 2 11 \n";
			}
		}
	}
	return 0;
}