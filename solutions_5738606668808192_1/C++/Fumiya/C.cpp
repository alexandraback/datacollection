#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

bool divide(unsigned int t, int base, int d){
	int c = 1;
	int s = 0;
	while(t > 0){
		if(t%2 == 1){
			s += c;
		}
		c = (c*base)%d;
		t /= 2;
	}
	return s%d == 0;
}

int main(){
	int T; cin >> T;
	vector<int> prime;
	prime.push_back(2);
	for(int t=3;prime.size() < 1000;t+=2){
		bool ok = true;
		for(int i=0;i<prime.size();i++){
			if(t%prime[i] == 0) ok = false;
		}
		if(ok) prime.push_back(t);
	}
	for(int t=1;t<=T;t++){
		printf("Case #%d:\n", t);
		int N, J; cin >> N >> J;
		int divisor[9];
		while(J > 0){
			for(int i=0;i<(1<<(N-2));i++){
				unsigned int t = (1UL << (N-1)) + i*2 + 1;
				bool ok = true;
				for(int base=2;base<=10;base++){
					for(int i=0;i<prime.size();i++){
						if(divide(t, base, prime[i])){
							divisor[base-2] = prime[i];
							break;
						}
						if(i == prime.size()-1){
							ok = false;
							break;
						}
					}
					if(!ok) break;
				}
				if(ok){
					for(int i=N-1;i>=0;i--){
						cout << ((t>>i)%2);
					}
					for(int i=0;i<9;i++) cout << " " << divisor[i];
					cout << endl;
					J--;
					if(J == 0) break;
				}
			}
		}
	}
}
