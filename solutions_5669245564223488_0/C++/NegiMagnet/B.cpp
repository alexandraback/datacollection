#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    init();
	int t;
	cin >> t;
	rep(tt, t) {
		int n;
		ll cnt = 0;
		cin >> n;
		vector<string> ins(n);
		rep(i,n) {
			string in;
		   	cin >> in;
			ins[i] = in[0];
			rep(j, in.length()) {
				if( ins[i][ins[i].length()-1] != in[j] ) {
					ins[i] += in[j];
				}
			}
		}
		vector<int> p(n);
		int len = 0;
		rep(i,n) {
			p[i] = i;
			len += ins[i].length();
		}
		do {
			bool check = true;
			bool exist[30] = {};
			int index = 0;
			string in="";
			rep(i,n) in += ins[p[i]];
			while(index < len) {
				if( exist[in[index]-'a'] ) {
					check = false;
					break;
				}
				exist[in[index]-'a'] = true;
				char c = in[index];
				while( index < len && c == in[index] ) {
					index++;
				}
			}
			if( check ) {
				cnt = (cnt+1) % 1000000007;
			}
		}while( next_permutation( p.begin(), p.end() ) );
		cout << "Case #" << (tt+1) << ": " << cnt << endl;
	}
	return 0;
}
