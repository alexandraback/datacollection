#include <iostream>
#include <ios>
#include <algorithm>
#include <iterator>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		int B;
		unsigned long long M;
		cin >> B >> M;
		cout << "Case #" << i << ": ";
		bool bridges[50][50]={{false}};
		// fill(bridges,bridges+2500,false);
		if(M>((unsigned long long)1<<(B-2))) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		bitset<64> kaminos(M);
		// cerr << kaminos << endl << kaminos[2] << endl;
		int j;
		for(j=48;j>=0 && !kaminos[j];--j);
		for(int k=B-j-1;k<B;++k) fill(bridges[k]+k+1,bridges[k]+B,true);
		fill(bridges[0]+(B-j-1),bridges[0]+B,true);
		for(--j;j>=0;--j) {
			if(kaminos[j]) {
				bridges[1][B-j-2]=true;
				bridges[0][1]=true;
			}
		}
		ostream_iterator<bool> output(cout,"");
		cout << "POSSIBLE" << endl;
		for(int j=0;j<B;++j) {
			copy(bridges[j],bridges[j]+B,output);
			cout << endl;
		}
	}
	return 0;
}