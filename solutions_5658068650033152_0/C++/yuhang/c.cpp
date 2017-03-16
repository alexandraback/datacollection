#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k;
		cin>>n>>m>>k;
		if(n>m)
			n^=m^=n^=m;
			
		int b=1;
		for(int j=1;;j++){
			if(j/2<n)
				b+=(j/4)+1-(j%4==1);
			else if(j/2<m || (j==m*2 && n%2==0))
				b+=n/2+(n%2==1 && j%2==0);
			else if(n%2==1)
				b+=m/2 - (j-(m*2-1))/4;
			else
				b+=m/2-1 - (j-(m*2+1))/4;
			if(b>=k){
				cout<<"Case #"<<i<<": "<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
