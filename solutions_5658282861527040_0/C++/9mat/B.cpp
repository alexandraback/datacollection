#include <iostream>
#include <vector>
#include <string>

#define FOR(i,n) for(int i = 0, _n = (n); i < _n; i++)

using namespace std;

int main(){
	int A, B, K, T;
	cin >> T;
	
	FOR(caseno, T){
		cin>>A>>B>>K;
		int count = 0;
		FOR(a, A) FOR(b, B){
	//		cout<<a<<" "<<b<<" "<<(a&b)<<endl;
			if ((a&b) < K) count++;
		}
		cout<<"Case #"<<caseno+1<<": "<<count<<endl;
	}
	return 0;
}