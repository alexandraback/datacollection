#include<bits/stdc++.h>

using namespace std;

int T,N,M,K;

int mysq(int a){
	int l=0,r=a,mid;
	while(l<r){
		mid=(l+r)/2;
		if(1LL*mid*mid<a) l=mid+1;
		else r=mid;
	}
	return l;
}

int test(int a){
	int mxs=N-2;

	int qg=mysq(a);
//	cout << a << "*" << qg << endl;
	if(qg>mxs) qg=mxs; 

	int ans=0;
	ans+=qg*2;
	ans+=a/qg*2;
	ans+=(a%qg!=0);
	
//	cout << "ans " << ans+a << endl;
	
	return ans+a;
	
}

int main(){
	cin>>T;
	for(int _T=1;_T<=T;_T++){
		cin>>N>>M>>K;
		if(N>M) swap(N,M);

		if(K<=4||N<=2){
			cout << "Case #" << _T << ": " << K << endl;
			continue;
		}

		if(K>=N*M-4){
			cout << "Case #" << _T << ": " << N+N+M+M+K-N*M-4 << endl;
			continue;
		}

		int l=1,r=(N-2)*(M-2);

		while(l<r){
			int mid=(l+r)/2;
//			cout<<mid<< " "<< test(mid)<<endl;
			if(test(mid)>=K){
				r=mid;
			}else{
				l=mid+1;
			}
		}

		cout << "Case #" << _T << ": " << test(l)-l << endl;
	}
}
