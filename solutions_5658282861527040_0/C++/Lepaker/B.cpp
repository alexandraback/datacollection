#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int tc,A,B,K,testNo = 0;
	cin >> tc;
	while (tc--) {
		int count = 0;
		cin >> A >> B >> K;
		for (int i=0;i<A;i++) {
			for (int j=0;j<B;j++) {
				if ((i & j) < K) count++; 
			}
		}
		cout << "Case #" << ++testNo << ": " << count << endl;	
	}
}
