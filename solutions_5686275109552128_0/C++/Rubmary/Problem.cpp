#include <iostream>
using namespace std;

int main () {
	
	int T;
	int D;
	int P[6];
	cin >> T;
	int minS;
	int sum;
	
	for (int k=1; k<=T; k++) {
		cin >> D;
		for (int i=0; i<D; i++)
			cin >> P[i];
		minS=9;
		for (int s=1; s<9; s++) {
			sum=s;
			for (int i=0; i<D; i++)
				sum+=(P[i]-1)/s;
			if (sum<minS)
				minS=sum;
		}
		
		cout << "Case #" << k << ": " << minS << endl;
	}
	
	return 0;
}
