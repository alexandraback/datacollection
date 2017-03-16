#include<iostream>

using namespace std;

int a[55][55];

int main(){
	int t;
	int b;
	long long m;
	cin>>t;
	int k=1;

	while(t--){
		int i,j;
		for(i=0;i<55;i++){
			for(j=0;j<55;j++){
				a[i][j]=0;
			}
		}
		cin>>b>>m;
		

		for(i=2;i<=b-1;i++){
			for(j=i+1;j<=b;j++){
				a[i][j]=1;
			}

		}
		long long w=1;
		for(i=0;i<b-2;i++){
			w*=2LL;
		}


		if(m>w){
			cout<<"Case #"<<k<<": IMPOSSIBLE"<<endl;
			k++;
			continue;
		}

		m--;
		a[1][b]=1;

		for(i=b-1;i>=2;i--){
			if(m%2LL==1){
				a[1][i]=1;
			}
			m/=2LL;
		}

		cout<<"Case #"<<k<<": POSSIBLE"<<endl;

		for(i=1;i<=b;i++){
			for(j=1;j<=b;j++){
				cout<<a[i][j];
			}cout<<endl;
		}



		k++;
	}






	return 0;
}