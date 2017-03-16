#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int digitNum(int a)
{
    int ans = 0;
    while (a) {
        ans++;
        a /= 10;
    }
    return ans;
}

int mm[] = {-1, 1, 10, 100, 1000, 10000, 100000, 1000000};
//int MM = {-1, 9, 99, 999, 9999, 99999, 999999, 9999999};

set<int> visited;

int A, B;
int calc(int a)
{
    int dn = digitNum(a);
    int m = mm[dn];

    visited.clear();
    for (int i = 1; i <= dn - 1; ++i) {
        int b = (a%mm[i+1]) * mm[dn-i+1] + a/mm[i+1];
        if (b < mm[dn]) continue;
        if (b > B) continue;
        if (b <= a) continue;
        if (visited.count(b)) continue;
        visited.insert(b);
    }
    return visited.size();
}

string calc()
{
    cin >> A >> B;
    int ans = 0;
    for (int i = A; i <= B; ++i) {
        ans += calc(i);
    }
    stringstream S;
    S << ans;
    return S.str();
}

int main(void)
{
	int N;
	cin >> N;

    // NOTE: if using getline() to read the input, the following two lines should be
    // added to read the line sepeartor in the first line. 
    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
