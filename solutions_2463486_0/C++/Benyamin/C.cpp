// In The Name of God
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
#define pb push_back
#define popb pop_back
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;

ifstream fin("C-small-attempt0.in");
ofstream fout("C-small-attempt0.out");

ll t, a, b;
vector<ll>v;

bool is_palindrome(ll x) {
	ll arr[18];
	int p = 0;
	while(x) {
		arr[p++] = x % 10;
		x /= 10;
	}
	for(int i = 0; i < p; ++i)
		if(arr[i] != arr[p - i - 1])
			return false;
	return true;
}
void fill_v() {
	ll tmp;
	for(int i1 = 1; i1 < 10; i1++){
		tmp = i1;
		if(is_palindrome(tmp * tmp))
			v.pb(tmp * tmp);
	}
	for(int i1 = 1; i1 < 10; i1++){
		tmp = 10 * i1 + i1;
		if(is_palindrome(tmp * tmp))
			v.pb(tmp * tmp); 
	}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++){
			tmp = i1 * 100 + i2 * 10 + i1;
			if(is_palindrome(tmp * tmp))
				v.pb(tmp * tmp);
		}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++){		
			tmp = 1000 * i1 + 100 * i2 + 10 * i2 + i1;
			if(is_palindrome(tmp * tmp))
				v.pb(tmp * tmp); 
		}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++){
				tmp = 10000 * i1 + 1000 * i2 + 100 * i3 + 10 * i2 + i1;
				if(is_palindrome(tmp * tmp))
					v.pb(tmp * tmp);
			}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++){			
				tmp = 100000 * i1 + 10000 * i2 + 1000 * i3 + 100 * i3 + 10 * i2 + i1;
				if(is_palindrome(tmp * tmp))
					v.pb(tmp * tmp); 
			}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++)
				for(int i4 = 0; i4 < 10; i4++){
					tmp = 1000000 * i1 + 100000 * i2 + 10000 * i3 + 1000 * i4 + 100 * i3 + 10 * i2 + i1;
					if(is_palindrome(tmp * tmp))
						v.pb(tmp * tmp);
				}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++)
				for(int i4 = 0; i4 < 10; i4++){				
					tmp = 10000000 * i1 + 1000000 * i2 + 100000 * i3 + 10000 * i4 + 1000 * i4 + 100 * i3 + 10 * i2 + i1;
					if(is_palindrome(tmp * tmp))
						v.pb(tmp * tmp);	
				}
}

void print(int c, int ans) {
	cout << "Case #" << c << ": " << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	fill_v();
	for(int i = 1; i <= t; ++i) {
		cin >> a >> b;
		print(i, int(upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a)) );
	}
	return 0;
}
