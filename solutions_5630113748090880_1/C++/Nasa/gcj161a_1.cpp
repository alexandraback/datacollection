#include <iostream>
#include <string>
using namespace std;

#define MAX 2500

int n,c[MAX+1];

int main(){
	int t,u,i,j,k;
	cin>>t; for (u=0; u<t; u++){ cin>>n;
		for (i=1; i<=MAX; i++) c[i]=0;
		for (i=0; i<(2*n-1)*n; i++){ cin>>k; c[k]=1-c[k]; }
		cout<<"Case #"<<(u+1)<<":";
		for (i=1; i<=MAX; i++) if (c[i]) cout<<" "<<i;
		cout<<endl;
	}
	return 0;
}
