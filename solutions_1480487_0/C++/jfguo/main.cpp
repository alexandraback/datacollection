#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

string calc()
{
    int N;
    cin >> N;
    vector<int> points(N);
    int total = 0;
    for (int i = 0; i <N; ++i) {
        cin >> points[i];
        total += points[i];
    }

    vector<double> ans(N, -1);
    int rem = N;
    double total1 = total;
    for (int i = 0; i < N; ++i) {
        if (points[i]*(N-1) >= 2*total-points[i]) {
            ans[i] = 0;
            rem--;
            total1 -= points[i];
        }
    }

    if (rem > 0) {
        double avg = 1.0*(total1+total)/rem;
        for (int i = 0; i < N; ++i) if (ans[i] < 0) {
            double t = (avg - points[i])/total;
            ans[i] = t;
        }
    }

    stringstream S;
    for (int i = 0; i < N; ++i) {
        if (i != 0) {
            S << ' ';
        }

        double t = ans[i];

        long long v = 1000000000;
        long long a = t*v;

        v /= 100;
        stringstream S1;
        S1 << a%v;
        string s = S1.str();
        if (s.length() < 7) {
            s = string(7-s.length(), '0') + s;
        }
        S << a/(v) << '.' << s;
    }

    return S.str();
}

int main(void)
{
	int N;
	cin >> N;

    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
