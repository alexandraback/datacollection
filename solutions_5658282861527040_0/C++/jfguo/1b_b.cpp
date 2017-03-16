#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string calc() {
    long long A, B, K;
    cin >> A >> B >> K;

    long long ans = 0;
    for (int i = 0; i < A; ++i) for (int j = 0; j < B; ++j) {
        if ((i&j) < K) {
            ++ans;
        }
    }

    stringstream ss;
    ss << ans;
    return ss.str();
}

int main(void)
{
	int T;
	cin >> T;

	for (int ca=1; ca<=T; ++ca) {
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
