#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
	int cases=0;
	cin >> cases;
	int caseNum=0;
	while (caseNum < cases) {
		caseNum++;
		cout << "Case #" << caseNum << ":" << endl;
		int n=0;
		cin >>  n;
		n=n/2;
		int j = 0;
		cin >> j;
		vector<long long>divisors;
		for (int i = 2; i <=10;i++)
			divisors.push_back(pow(i,n)+1);
		for (int i=1; i<=j; i++) {
			long long temp= (i<<1) | (1<<(n-1)) | 1;
			temp |= (temp << n);
			cout << bitset<32>(temp);
			for (int k=0; k<=(10-2); k++)
				cout << " " << divisors[k];
			cout << endl;
		}
	}
	return 0;
}

