#include <iostream>
#include <fstream>

using namespace std;
int main() {
	fstream f;
	f.open("a.dat", ios::in);
	if (!f.is_open()) {
		throw "Failed to open";
	}

	int T;

	f>>T;

	for (int i =0;i<T;i++) {
		cout<<"Case #"<<(i+1)<<": ";
		unsigned int A, B, K;
		f>>A;
		f>>B;
		f>>K;
		int ans = 0;
		for (unsigned int o =0; o<A;o++) {
			for (unsigned int p=0;p<B;p++) {
				if ((o&p) < K) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
