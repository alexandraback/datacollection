#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int in;

void testcase() {
	in A,B,K; cin>> A >> B >> K;
	in res = 0;
	for(in a=0; a<A; a++) {
		for(in b=0; b<B; b++) {
			res += ((a&b)<K);
		}
	}
	cout << res;

}

int main() {
	in T;
	cin >> T;
	for(int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		testcase();
		cout << endl;
	}
}