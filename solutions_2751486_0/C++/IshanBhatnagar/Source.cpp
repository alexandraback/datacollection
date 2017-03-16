#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MOD 1000000007

bool is_vowel(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;
	else 
		return true;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	int t, i, j, l, n, k;
	bool array[1000001];
	ll ans;
	string s, x;

	cin >> t;

	for(k=1; k<=t; ++k)
	{
		cin >> s >> n;
		ans = 0;
		x.clear();
		l = s.length();
		j = 0;

		for(i=0; i<l; ++i){
			array[i] = is_vowel(s[i]);
		}

		int count = 0;
		for(i=0; i<n; ++i){
			if(array[i])
				++count;
		}

		if(count == n){
			ans += (l-n+1);
			j = 1;
		}

		for(i=n; i<l; ++i){
			if(array[i])
				++count;
			if(array[i-n])
				--count;
			if(count == n){
				ans += (i-n-j+2)*(l-i);
				j = i-n+2;
			}
		}

		cout << "Case #" << k << ": " << ans << endl;
	}

	return 0;
} 