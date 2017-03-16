#include <iostream>

using namespace std;

int main()
{
	int T, i;
	cin>>T;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(6);
	for(i = 0; i<T; i++){
		int A, B, j;
		cin>>A>>B;
		double prob[3];
		double numKeysMin, numKeys;
		double probRight = 1;
		for(j = 0; j<A; j++){
			cin>>prob[j];
			probRight *= prob[j];
		}
		numKeysMin = probRight*((B-A)+1) + (1-probRight)*((B+1)+(B-A+1));
		int k;
		probRight = 1;
		for(k = 1; k<=A; k++){
			for(j = 0; j<(A-k); j++){
				probRight *= prob[j];
			}
			numKeys = probRight*(2*k+(B-A)+1) + (1-probRight)*(2*k+(B+1)+(B-A+1));
			if(numKeys < numKeysMin) numKeysMin = numKeys;
		}
		numKeys = 2+B;
		if(numKeys < numKeysMin) numKeysMin = numKeys;
		cout<<"Case #"<<(i+1)<<": "<<numKeysMin<<endl;
	}
}
