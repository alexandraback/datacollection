#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

int main() {
    ll T; cin >> T;
    FOR(t,0,T) {
        cout << "Case #" << t+1 << ": ";

		list<char> res;
		string s; cin >> s;
		for(char c : s) {
			if(c >= *begin(res))
				res.push_front(c);
			else
				res.push_back(c);
		}
		for(char c : res)
			cout << c;

		cout << endl;
    }
}
