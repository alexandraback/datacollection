#include <cstdio>
#include <iostream>
using namespace std;
int c[2505],a[2505][2505],l[2505];
int main(){
	int T,cnt=0;
	cin>>T;
	while(T--){
		for(int i=0; i<=2500; ++i) c[i]=0;
		int n;
		cin>>n;
		for(int i=0; i<2*n-1; ++i){
			for(int j=0; j<n; ++j){
				int x;
				cin>>x;
				++c[x];
			}
		}
		int m=0;
		for(int i=0; i<=2500; ++i)
			if (c[i]%2==1) l[++m]=i;
		++cnt;
		cout<<"Case #"<<cnt<<": ";
		for(int i=1; i<=n; ++i)
			if (i==n) cout<<l[i]<<endl;
			else cout<<l[i]<<" ";
	}
	return 0;
}
