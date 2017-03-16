#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

#define cin fin
#define cout fout

void run() {
	int A, B, K;
	cin>>A>>B>>K;
	int ans = 0;
	for (int i = 0; i < A; ++i)
		for (int j = 0; j < B; ++j)
			if ((i & j) < K) ++ans;
	cout<<ans<<endl;
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}