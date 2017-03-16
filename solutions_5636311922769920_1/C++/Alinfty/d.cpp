#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int K,C,S;
		cin>>K>>C>>S;
		cout<<"Case #"<<i<<":";
		int ans=K-C+1;
		ans=(ans<1)?1:ans;
		if(ans>S) cout<<" IMPOSSIBLE"<<endl;
		else{
			long long int p=0;
			for(int j=1;j<C;j++){
				if(j-1<K) p=K*(p+(j-1)*K);
				else p=K*(p+(K-1)*K);
			}
			for(int j=0;j<ans;j++){
				cout<<" "<<p+K-ans+j+1;
			}
			cout<<endl;
		}
	}
	return 0;
}
