										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int64 calc(int64 x){
	vector <int> v;
	while(x){
		v.push_back(x % 10);
		x /= 10;
	}
	v[v.size() - 1]--;
	int64 ret = 0, p = 1;
	int rev = 0;
	for(int i = 0, j = v.size() - 1; i <= j; i++, j--){
		ret += v[i] * p;
		if(i != j){
			ret += v[j] * p;
			if(v[j] > 0)
				rev = 1;
		}
		p *= 10;
	}
	return ret + rev;
}

int main(){
	freopen("A-Counter Culture.in", "r", stdin);
	freopen("A-Counter Culture.out", "w", stdout);
	int T, test = 0;
	int64 n;
	for(cin >> T; T--; ){
		cin >> n;
		int64 tot = n % 10 ? 0 : 1;
		if(n % 10 == 0)
			n--;

		int64 idx = 1;
		while(idx * 10 <= n){
			tot += calc(idx * 10 - 1) + 1;
			idx *= 10;
		}
		tot += calc(n);
		cout << "Case #" << ++test << ": " << tot + 1 << endl;
	}
	return 0;
}
