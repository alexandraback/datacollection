#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;

#define FORZ(i,n) for(typeof(n)i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define sz size()
#define FF first
#define SS second
typedef vector<int> VI;
typedef pair<int,int> pII;
typedef vector<string> VS;
typedef long long LL;

int main () {
	int T;
	cin >> T;
	
	for (int t = 1 ; t <= T ; t ++) {
		int N;
		cin >> N;
		
		VI S(N);
		FORZ (i, N)
			cin >> S[i];
		
		map < int, vector<VI> > mp;
		
		FORZ (s, 1 << N) {
			string bit = bitset<20>(s).to_string<char,char_traits<char>,allocator<char> >();
			
			VI v;
			int sum = 0;
			FORZ (i, N) {
				if (bit[i] == '1') {
					v.PB(S[i]);
					sum += S[i];
				}
			}
			
			mp[sum].PB(v);
		}
		
		cout << "Case #" << t << ":\n";
		bool done = false;
		
		for (map < int, vector<VI> >::iterator it = mp.begin() ; it != mp.end() ; it ++) {
			vector <VI> subset = it->SS;
			if (subset.sz == 2) {
				VI sub1 = subset[0], sub2 = subset[1];
				FORZ (i, sub1.sz - 1)
					cout << sub1[i] << " ";
				cout << sub1.back() << "\n";
				
				FORZ (i, sub2.sz - 1)
					cout << sub2[i] << " ";
				cout << sub2.back() << "\n";
				
				done = true;
				break;
			}
		}
		
		if (!done)
			cout << "Impossible\n";
	}
	
	return 0;
}
