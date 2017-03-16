
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <utility>
#include <functional>
#include <popcntintrin.h>
#include <x86intrin.h>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)

int popcnt64(uint64_t val)
{
	return _mm_popcnt_u64(val);
}

int charToIdx(char c)
{
	return c - 'a';
}

int64_t facmod(int n)
{
	if (n < 1) return 1;
	return n * facmod(n-1) % 1000000007;
}

int main()
{
	int numCases;
	cin >> numCases;
	forl(i,1,numCases+1)
	{
		int charstarts[26] = {0};
		int charends[26] = {0};
		int charmiddles[26] = {0};
		int chartotals[26] = {0};
		int charLink[26] = {0};

		bool possible = true;
		int numstrings;
		cin >> numstrings;
		forl(i,0,numstrings)
		{
			string str;
			cin >> str;
			charstarts[charToIdx(str[0])]++;
			charends[charToIdx(str[str.length()-1])]++;
			if (charToIdx(str[0]) != charToIdx(str[str.length()-1]))
			{
				charLink[charToIdx(str[0])] = charToIdx(str[str.length()-1]) + 1;
			}
			int curchr = charToIdx(str[0]);
			bool changed = false;
			forl(ci, 0, str.length())
			{
				if (charToIdx(str[ci]) != curchr)
				{
					curchr = charToIdx(str[ci]);
					charmiddles[curchr]++;
					changed = true;
				}
			}
			if (!changed) chartotals[curchr]++;
			else charmiddles[curchr]--;
		}
		// Count the number of identical (up to isomorphism), interchangable sets.
		int64_t total = 1;
		forl(i,0,26)
		{
			// If there are multiple isolated chunks of the same thing, or one isolated chunk + a start or end
			if (charmiddles[i] > 1 || (charmiddles[i] && (charstarts[i] || charends[i])))
			{
				//cerr << "--- " << i << endl;
				total = 0;
				possible = false;
				break;
			}

			// If there are more starts than ends (or vice-versa) by more than one.
			if (charstarts[i] - chartotals[i] > 1 || charends[i] - chartotals[i] > 1)
			{
				total = 0;
				possible = false;
				break;
			}
			total = total * facmod(chartotals[i]) % 1000000007;
		}

		int64_t numchains = 0;
		bool visited[26] = {0};
		forl(i,0,26)
		{
			if (visited[i]) continue;
			if (!charstarts[i]) continue;
			numchains++;
			visited[i] = true;
			int chainidx = charLink[i];
			while (chainidx)
			{
				if (visited[chainidx-1])
				{
					if (chainidx-1 == i)
					{
						// We're in a cycle. Impossible.
						possible = false;
						total = 0;
						break;
					}
					// We're a new head for a chain.
					numchains--;
					break;
				}
				visited[chainidx-1] = true;
				chainidx = charLink[chainidx-1];
			}
		}
		cerr << numchains << endl;
		total = total * facmod(numchains) % 1000000007;




		cout << "Case #" << i << ": ";
		cout << total;
		cout << endl;
	}
}
