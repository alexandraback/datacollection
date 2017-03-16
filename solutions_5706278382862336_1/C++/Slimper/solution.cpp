#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
    cerr << "Case #" << caseNumber << endl;
    if (ans == -1) {
        cout << "Case #" << caseNumber << ": impossible" << endl;
    }
    else {
        cout << "Case #" << caseNumber << ": " << ans << endl;
    }
}

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

template <class AnswerType>
AnswerType SolveTestCase() {
    string str;
    getline(cin, str);
    long long P = 0;
    long long Q = 0;
    size_t i = 0;
    for (; str[i] != '/'; i++) {
        P = 10 * P + (str[i] - '0');
    }
    i++;
    for (; i < str.length(); i++) {
        Q = 10 * Q + (str[i] - '0');
    }
    
    long long d = GCD(P, Q);
    P /= d;
    Q /= d;
    int n = 0;
    long long cur = 1;
    while (cur < Q) {
        cur *= 2;
        n++;
    }
    if (cur != Q || n > 40) {
        return -1;
    }
    int ans = 0;
    while (P < Q) {
        P *= 2;
        ans++;
    }
    return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("A-small.in", "r", stdin);
	freopen("A-large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;
    string str;
    getline(cin, str);
	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase<int>() );

	return 0;
}