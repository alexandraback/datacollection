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

bool con(char c)
{
	return c != 'a' && c != 'o' && c != 'i' && c != 'u' && c != 'e';
}

int main(int argc, char* argv[])
{
    // freopen("input.txt", "rt", stdin);

    int testCases;
    cin >> testCases;

    forn(tt, testCases)
    {
    	string s;
    	int l;

    	cin >> s >> l;
    	int n = s.length();

    	vector<int> segs;

    	int len = 0;
    	forn(i, n)
    		if (con(s[i]))
    		{
    			len++;
    			if (len >= l)
    				segs.push_back(i - l + 1)/*, cout << i - l + 1 << endl*/;
    		}
    		else
    			len = 0;

    	li result = 0;

    	forn(i, n)
    	{
    		vector<int>::iterator it = lower_bound(segs.begin(), segs.end(), i);
    		if (it != segs.end())
    		{
    			int pos = *it;
    			int end = pos + l - 1;
    			result += n - end;
    			// cout << pos << " " << end << " " << n - end << endl;
    		}
    	}

    	cout << "Case #" << (tt + 1) << ": " << result << endl;
    }

    return 0;
}
