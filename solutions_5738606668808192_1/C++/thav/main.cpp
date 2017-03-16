#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41}; //len = 13
const int limx = 1e6;
const int limprimes = 6;
const int limshift = 1;

int interpret(int x, int b, int p) {
	int potb = 1, res = 0;
	while(x) {
		if(x % 2) {
			res = (res + potb) % p;
		}
		x /= 2;
		potb = ( potb * 1ll * b ) % p;
	}
	return res;
}

struct solution {
	int x, shift;
	vector<int> div;
};

bool fits(int x, int len, int s = 1) {
    len -= (1 + s);
    while(x) {len--; x/=2;}
    return len >= 0;
}

vector<solution> find(int len, int n) {
	vector<solution> ans;//x, shift
	for(int x = 0; x < limx && fits(x, len); x++) {
		///cout << "Analyzing " << x << endl;
		for(int s = 1; s <= limshift && fits(x, len, s); s++) {
			vector<int> div(10, -1);
			for(int b = 2; b <= 10; b++) {
				bool found = false;
				for(int ip = 0; ip < limprimes; ip++) {
					int p = primes[ip];
					int mod = 1;
					for(int iter = len - 1; iter--;) {
						mod = (mod * 1ll * b) % p;
					}
					mod = (mod + 1) % p;///assuming len > 1
					int inter = interpret(x, b, p);
					for(int tmp = s; tmp--;) {
						inter = (inter * 1ll * b) % p;
					}
					//if log2(x) > len - 2 break;

					mod = (mod + inter) % p;
					if(mod == 0) {
						div[b - 1] = p;
						found = true;
						break;
					}
				}
				if(!found) break;
			}
			bool ok = true;
			for(int b = 2; b <= 10; b++)
				ok &= (div[b - 1] != -1);
			if(ok) {
				solution rr;
				rr.x = x;
				rr.shift = s;
				rr.div = div;
				ans.push_back(rr);
				//cout << "Found " << ans.size() << " so far\n";
				if(ans.size() == n)
					return ans;
			}
		}
	}
	return ans;
}

void printbin(int x, int len) {
	if(len == 0) return;
	printbin(x / 2, len - 1);
	cout << ((x%2==0)?"0":"1");
}

void query(int howmany, int width) {
    vector<solution> sol = find(width, howmany);
	assert(howmany == sol.size());
	for(int i = 0; i < sol.size(); i++) {
		//cout << sol[i].x << " " << sol[i].shift << "\ndivs:\n";
		cout << 1; printbin(sol[i].x, width - 2); cout << 1 << " ";
		for(int j = 1; j < sol[i].div.size(); j++)
			cout << sol[i].div[j] << " ";
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	int howmany = 100 , width = 6;

	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		cin >> width >> howmany;
		cout << "Case #" << cas << ": \n";
		query(howmany, width);

	}
}
