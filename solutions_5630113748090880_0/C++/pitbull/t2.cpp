#include<iostream>
using namespace std;
int main(){

	int t,i,j,l,x,n;
	cin>>t;
	char p[1010];
	for(i=1;i<=t;++i){
		cin>>n;
		int a[4000]={0};
		for(j=1;j<=2*n-1;++j){
			for(l=0;l<n;++l){
				cin>>x;
				a[x]++;
			}
		}
		
		cout<<"Case #"<<i<<": ";
		
		for(j=0;j<4000;++j){
			if(a[j]%2==1) cout<<j<<" ";
		}
		
		cout<<"\n";
	}


	return 0;
}

