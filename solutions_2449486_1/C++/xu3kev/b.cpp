#include<iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	int a[101][101];
	int b[101][101];
	int n;
	int m;
	for(int Ti=1;Ti<=T;++Ti){
		cout<<"Case #"<<Ti<<": ";
		cin>>n>>m;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>a[i][j];
				b[i][j]=0;
			}
		}

		int tmp;

		for(int i=0;i<n;++i){
			tmp=0;
			for(int j=0;j<m;++j){
				if(a[i][j]>tmp)
					tmp=a[i][j];
			}
			for(int j=0;j<m;++j){
				if(a[i][j]==tmp)
					b[i][j]=1;
			}
		}

		for(int j=0;j<m;++j){
			tmp=0;
			for(int i=0;i<n;++i){
				if(a[i][j]>tmp)
					tmp=a[i][j];
			}
			for(int i=0;i<n;++i){
				if(a[i][j]==tmp)
					b[i][j]=1;
			}
		}
		int sum=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				sum+=b[i][j];
			}
		}
		if(sum==n*m)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
	return 0;
}
