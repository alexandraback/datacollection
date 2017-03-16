#include<bits/stdc++.h>

using namespace std;

set<int> cnums;

typedef long long int ll;

void solve(){
	int K,C,S;
	cin >> K >> C >> S;

	assert(K==S);

	for(int i=0;i<K;i++){
		cout << " " << i+1;
	}


}

int main(){

	int N;
	cin >> N;

	for(int i=1;i<=N;i++){
		printf("Case #%d:", i);
		solve();
		cout << endl;
	}

	return 0;
}
