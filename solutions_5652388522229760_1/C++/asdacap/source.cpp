#include<bits/stdc++.h>

using namespace std;

set<int> cnums;

typedef long long int ll;

void addDigit(ll num){
	if(num == 0) cnums.insert(0);

	while(num){
		cnums.insert(num%10);
		num/=10;
	}
}

void solve(){
	cnums.clear();

	ll C;
	cin >> C;
	ll cur = C;

	for(ll i=1;i<=100000;i++){
		addDigit(cur);
		if(cnums.size() == 10){
			cout << cur;
			return;
		}
		cur = C*i;
	}

	cout << "INSOMNIA";
}

int main(){

	int N;
	cin >> N;

	for(int i=1;i<=N;i++){
		printf("Case #%d: ", i);
		solve();
		cout << endl;
	}

	return 0;
}
