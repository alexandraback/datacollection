#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<long long> valid;

bool check(long long x)
{
    ostringstream os;
    os << x;
    string s = os.str();
    for (int i = 0, j = (int)s.length() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int count(long long x)
{
    return distance(valid.begin(), valid.upper_bound(x));
}

int main()
{
    const int UPBOUND = 1e7 + 10;
    for (int i = 0; i < UPBOUND; i++) {
        if (check(i) && check((long long)i * i)) {
            valid.insert((long long)i * i);
            // cout << (long long)i * i << endl;
        }
    }

    int tasks;
    cin >> tasks;
    for (int task = 1; task <= tasks; task++) {
        long long A, B;
        cin >> A >> B;
        cout << "Case #" << task << ": " << count(B) - count(A - 1) << endl;
    }

    return 0;
}
