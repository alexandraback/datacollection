#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

int solve(li a, vector<li> b, int n)
{
	int result = 0;

	forn(i, n)
	{
		while (b[i] >= a)
		{
			if (a == 1)
				return 1000000000;
			a += a - 1;
			result++;
		}

		a += b[i];
	}	

	return result;
}

int main(int argc, char* argv[])
{
    // freopen("input.txt", "rt", stdin);

    int testCases;
    cin >> testCases;

    forn(tt, testCases)
    {
    	li a;
    	vector<li> b;
    	int n;
    	cin >> a >> n;
    	b.resize(n);
    	forn(i, n)
    		cin >> b[i];
    	sort(b.begin(), b.end());

    	int result = n + 1;
    	forn(i, n + 1)
    		result = min(result, i + solve(a, b, n - i));

    	cout << "Case #" << (tt + 1) << ": " << result << endl;
    }

    return 0;
}
