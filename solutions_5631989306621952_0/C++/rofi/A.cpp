#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))


string solve()
{
	string S;
	string result;

	cin >> S;
	result += S[0];
	For(i, 1, S.size()) {
		if(result[0] < S[i]) {
			result = S[i] + result;
		} else if(result[0] > S[i]) {
			result += S[i];
		} else {
			auto it = find_if(result.begin(), result.end(), [&](char c) {return c != S[i];});
			if(it == result.end()) {
				result += S[i];
			} else {
				if(*it < S[i]) {
					result = S[i] + result;
				} else {
					result += S[i];
				}
			}
		}
	}

	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

