#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring> // memset(void *b, int c, size_t len);
#include <algorithm> // sort
#include <iomanip> // cout << std::fixed << std::setprecision(4)

using namespace std;

#define maxP 1005

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int D, p;
		long long P[maxP] = {0}, count = 0;
		cin >> D;
		for(int d = 0; d < D; ++d) { cin >> p; P[p]++; }
		for(int i = maxP-1; i >= 4; --i) {
			if(P[i] == 0) continue;
			//cout << i << " " << P[i] << endl;
			P[i/2] += P[i];
			P[i-i/2] += P[i];
			count += P[i];
			P[i] = 0;
		}
		//cout << count << endl;
		for(int i = 3; i >=0; --i) {
			if(P[i] > 0) { 
				count += i; 
				break;
			}
		}
		cout << "Case #" << t+1 << ": " << count << endl;

	}
	return 0;
}

