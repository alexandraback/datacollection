#include<bits/stdc++.h>
using namespace std;
#define Int long long
#define p 1000000007
int main(){
	int t,i,j,n,T,Hash[2505],m,arr[110][55];
	cin>>T;
	for(t=1;t<=T;t++){
		cin>>n;
		memset(Hash,0,sizeof(Hash));m=0;
		for(i=1;i<2*n;i++){
			for(j=1;j<=n;j++){
				cin>>arr[i][j];
				Hash[arr[i][j]]++;
				if(m<arr[i][j])m = arr[i][j];
			}
		}
		printf("Case #%d: ",t);
		for(i=1;i<=m;i++){
			if(Hash[i]%2 !=0)cout<<i<<" ";
		}cout<<endl;
	}
	return 0;
}