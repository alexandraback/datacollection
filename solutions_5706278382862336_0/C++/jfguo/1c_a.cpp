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

int ok(long long p, long long q) {
    long long g = gcd(p, q);
    p /= g;
    q /= g;

    for (int i = 1; i <= 40; ++i) {
        p *= 2;
        long long g = gcd(p, q);
        p /= g;
        q /= g;
        if ((p == 0 || p == 1) && q ==1) return 1;
    }
    return 0;
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

    int ans = 0;

    for (int i = 1; i <= 40; ++i) {
        long long p = (P<<i);
        long long q = (Q<<i);
        p -= Q;
        if (p < 0) continue;

        g = gcd(p, q);
        p /= g;
        q /= g;

        int n = bn(q);
        long long one = 1;
        if (n == 1 && q <= (one<<40)) {
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
    double a  = 1000000;
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
