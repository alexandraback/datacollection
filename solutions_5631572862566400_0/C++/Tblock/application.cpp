#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<ll> vll;

int main()
{	
	

	int t;
	cin >> t;
	int cas = 1;

	while (t--) {
		cout << "Case #" << cas << ": ";
		cas++;

		int n;
		cin >> n;

		vi f;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			f.push_back(temp - 1); // switch to zero-based indexing
		}

		
		// preprocess each vertex
		// starting from each vertex, follow the chain and determine whether it will end as a "simple" cycle or in a pair of mutual bffs
		// if it ends in a pair of mutual, record the starting point and the length of the sequence including the mutual pair endpoint
		// also record the largest "simple" cycle

		int lps[1001]; // longest pre-sequence; if lps[i] is non-negative, then the ith student is part of a mutual bff pair, and lps[i] gives the longest presequence that ends in i
		int slps[1001]; // the starting vertex that lead to the longest pre-sequence (not actually needed for this problem)
		for (int i = 0; i < 1001; i++) {
			lps[i] = -1;
			slps[i] = -1;
		}

		int maxsimple = 0;
		for (int first = 0; first < n; first++) {
			vb avail(n, true);
			avail[first] = false;
			int circle = 1;

			int curr = first;
			int prev = -1;
			while (avail[f[curr]]) {
				circle++;
				avail[curr] = false;
				//cout << "moving from " << curr << " to " << f[curr] << endl;
				prev = curr;
				curr = f[curr];
			}
			if (f[curr] == first) {
				if (circle == 2) {
					// mark it as part of a pair if not yet found
					if (lps[curr] == -1)
						lps[curr] = 1;
					if (lps[f[curr]] == -1)
						lps[f[curr]] = 1;
				}
				else {
					//cout << "found simple circle with " << circle << " people" << endl;
					if (circle > maxsimple)
						maxsimple = circle;
				}
			}
			else if (f[curr] == prev && circle > 2) {
				//cout << "detected mutual bffs; can create a circle with at least " << circle << " people" << endl;
				
				// update the lps array
				if (lps[prev] < circle - 1) {
					lps[prev] = circle - 1;
					slps[prev] = first;
				}
			}
		}

		// now, determine the maximum circle; each mutual pair can support each other, plus the longest pre-sequences leading to each endpoint
		// each mutual pair is guaranteed to be part of subgraph disjoint from other mutual pairs
		// so, we can form a circle by including all mutual pairs and the longest pre-sequences they support
		int ans = 0;
		for (int i = 0; i < 1001; i++) {
			if (lps[i] != -1)
				ans += lps[i];
		}

		// make sure to also check that the sum is less than the max simple circle
		ans = max(ans, maxsimple);

		cout << ans << endl;

		/*

		cout << endl;
		for (int i = 0; i < 1001; i++) {
			if (lps[i] >= 0) {
				cout << i << " is in a mutual pair, longest pre-sequence is of length " << lps[i] << " starting from " << slps[i] << endl;
			}
		}
		cout << endl << "max simple circle is " << maxsimple << endl;*/

	}
    return 0;
}
