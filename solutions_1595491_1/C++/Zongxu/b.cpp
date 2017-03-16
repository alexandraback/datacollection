#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	freopen("b-large.in", "r", stdin);
	freopen("b-large.out", "w", stdout);

	int t, N, S, num, numS, p, tot, rem;

	cin>>t; cin.ignore();
	for (int k=1; k<=t; k++) {
		cin>>N>>S>>p;
		num = numS = 0;
		for (int i=0; i<N; i++) {
			cin>>tot;
			if (tot>=p) {
				rem = (tot - p) / 2;
				if (rem >= max(p-1,0))
					++num;
				else if (rem == max(p-2,0))
					++numS;
			}
		}

		printf("Case #%d: %d\n", k, num+min(S, numS));		
	}	
	return 0;
}
