#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

void work()
{
	int K, L, S;
	string key, word;
	cin >> K >> L >> S >> key >> word;
	double total = pow(double(K), double(L));
	double can = 1;	
	for (int i = 0; i < L; ++i) {
		double t = 0;
		for (int j = 0; j < K; ++j)
			if (key[j] == word[i])
				++t;
		if (t == 0) {
			cout << 0;
			return;
		}			
		can *= t;
	}
	double expect = double(S - L + 1) * can / total;	
	int pos = 1;
	while (pos < L && word.substr(pos) != word.substr(0, L - pos))
		++pos;
	double maximam = 1 + (S - L) / pos;
	cout << maximam - expect;
}

int main()
{
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);

	cout << fixed;
	cout.precision(10);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}

