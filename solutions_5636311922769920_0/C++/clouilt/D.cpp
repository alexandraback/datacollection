#include <iostream>
#include <cstdio>

using namespace std;

int T, K, C, S;

long long calc(int* arr){
	long long res =0;
	for(int i=0; i<C; ++i){
		res *= K;
		res += arr[i]-1;
	}
	return res + 1;
}


int main(){
	cin>>T;
	for(int cs=1; cs<=T; ++cs){
		cin>>K>>C>>S;
		if( C * S < K){
			printf("Case #%d: IMPOSSIBLE\n", cs);
			continue;
		}
		int arr[103];
		long long brr[103];
		int cnt=0;
		int i = 0;

		while(i < K){
			for(int j = 0; j<C; ++j){
				if( i < K){
					++i;
				}
				arr[j] = i;
			}
			brr[cnt++] = calc(arr);
		}
		
		cout<<"Case #"<<cs<<": "<<brr[0];
		for(int i=1; i<cnt; ++i){
			cout<<' '<<brr[i];
		}
		cout<<endl;
		
	}
	return 0;
}
