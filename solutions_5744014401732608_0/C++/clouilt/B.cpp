#include <iostream>
using namespace std;
int T;
long long B,M;

long long arr[53];
int mp[53][53];

int main(){
	cin>>T;
	for(int cs = 1; cs<=T; ++cs){
		cin>>B>>M;
		cout<<"Case #"<<cs<<": ";
		int mid = B-2;
		for(int i = 0;i< mid; ++i){
			arr[i] = 1;
		}
		for(int i = 0; i< mid; ++i){
			for(int j = 0; j< i; ++j){
				arr[i] += arr[j];
			}
		}
		int m =1;
		for(int i = 0; i< mid ;++i){
			m += arr[i];
		}
		// cout<<m<<endl;
		if(M > m){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}else
			cout<<"POSSIBLE"<<endl;;

		for(int i=0; i< 53; ++i){
			for(int j = 0; j<53; ++j){
				mp[i][j] = 0;
			}
		}

		int highbit = 0;
		long long t = M;
		long long mask = 1;
		int t2 = 1;
		if(M == m){
			for(int i = 1;i<B; ++i)
				mp[0][i] = 1;
			for(int i = 1;i<B-1; ++i)
				mp[i][B-1] = 1;
			for(int i= 1; i<B-1; ++i){
				for(int j = 1; j<i; ++j){
					mp[j][i] = 1;
				}
			}
			goto _output;
		}
		while(t){
			if(t&mask){
				t &= ~mask;
			}
			mask <<=1;
			++highbit;
			// 2 -> 2
			// 3 -> 2
		}

		for(int i = 0;i<B-1; ++i)
			mp[i][B-1] = 1;

		for(int i = 1;i< highbit; ++i)
			mp[0][i] = 1;

		for(int i= 1; i<highbit; ++i){
			for(int j = 1; j<i; ++j){
				mp[j][i] = 1;
			}
		}

		t = M;

		t -= (1LL << (highbit -1));

		mask = 1;
		while(t){
			if(mask & t){
				mp[t2][highbit] = 1;
				t &= ~mask;
			}
			mask <<=1;
			++t2;
		}
		

	_output:
		for(int i = 0; i<B; ++i){
			for(int j = 0;j<B; ++j){
				cout<<mp[i][j];
			}
			cout<<endl;
		}

		
	}
	return 0;
}
