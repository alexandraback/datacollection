#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <utility>
#include <list>
#include <functional>

#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	all(v)					(v).begin(),(v).end()

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	pair<int,int>			PII;


struct Uniq {
	char c;
	const char *number;
	int n;
} uniq[] = {
	{'Z', "ZERO",  0},
	{'W', "TWO",   2},
	{'U', "FOUR",  4},
	{'X', "SIX",   6},
	{'G', "EIGHT", 8},

	{'O', "ONE",   1},
	{'T', "THREE", 3},
	{'F', "FIVE",  5},
	{'S', "SEVEN", 7},
	{'I', "NINE",  9},
	{'\0', "",    -1}
};

string solve()
{
	string S;
	cin >> S;
	map<char, int> hist;

	rep(i, S.size())
		hist[S[i]]++;

	vector<int> phone;
	for(int i = 0 ; uniq[i].c ; ++i) {
		while(hist[uniq[i].c]) {
			for(int j  = 0 ; uniq[i].number[j] ; ++j) {
				hist[uniq[i].number[j]]--;
			}
			phone.pb(uniq[i].n);
		}
	}

	string result;
	sort(all(phone));
	rep(i, phone.size())
		result += '0' + phone[i];

	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

