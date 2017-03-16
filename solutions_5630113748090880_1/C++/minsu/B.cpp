#include <bits/stdc++.h>
using namespace std;

int cnt[2505];
int main(){
	int T,l,N;

	ios_base::sync_with_stdio(false);
	cin>>T;
	for(int t=1; t<=T; t++){
		cin>>N;
		memset(cnt, 0, sizeof cnt);
		for(int i=0; i<(2*N-1)*N; i++){
			cin>>l;
			cnt[l]++;
		}
		cout<<"Case #"<<t<<": ";
		for(int i=1;i<=2500;i++){
			if( cnt[i]%2 ) cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
