// Vladimir Burian, 2016 (vladaburian@gmail.com)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include <algorithm>
#include <cmath>

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long int ll;

ifstream in;
ofstream out;


ll cmaxi(ll N) {
	ll maxi = 10;
	for (; N; N/=10, maxi*=10) ;
	return maxi;
}

void solve() {
	ll N;
	in >> N;

	 ll maxi = cmaxi(N);

	 int mask = 0;

	 for (ll i=1; i<=maxi; ++i) {
		for (ll Ni = i*N; Ni; Ni/=10) {
			mask |= (1 << Ni%10);
		}

		if (mask == 0x3ff) {
			out << i*N;
			return;
		}
	 }

	 out << "INSOMNIA";
}

int main() {
	string name = "A-small-attempt0";

	in.open((name + ".in").c_str());
	out.open((name + ".out").c_str());

    int T;
    in >> T;
    for (int i = 1; i <= T; i++) {
    	cout << "Case #" << i;

        out << "Case #" << i << ": ";
        solve();
        out << '\n';

        cout << " DONE\n";
    }

    in.close();
    out.close();

    return 0;
}
