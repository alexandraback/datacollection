#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

long long gcd (long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int bn(long long a) {
    int ans = 0;
    while (a) {
        ans++;
        a &= a-1;
    }
    return ans;
}

string calc()
{
    char ch;
    long long P, Q;
    cin >> P >> ch >> Q;

    long long g = gcd(P, Q);
    P /= g;
    Q /= g;

    int qn = bn(Q);

    int ans = 0;

    long long p = P;
    long long q = Q;
    for (int i = 1; i <= 40; ++i) {
        p *= 2;
        if (p < Q) continue;

        long long one = 1;
        if (qn == 1) {
            stringstream ss;
            ss << i;
            return ss.str();
        }
    }

    return "impossible";
}

int main(void)
{
    /*
    long long a = 1000000;
    a *= a;
    long long one = 1;
    a *= one<<40;
    cout << a << endl;
    */

	int T;
	cin >> T;
	//getline(cin, line);
	for (int ca=1; ca<=T; ++ca) {
		//getline(cin, line);
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
