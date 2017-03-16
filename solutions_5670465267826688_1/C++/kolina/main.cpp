#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cassert>

using namespace std;

char s[10001], mul;
bool sign;

pair<char, bool> mult(char c1, char c2) {
	if (c1 == '1')
		return make_pair(c2, true);
	if (c2 == '1')
		return make_pair(c1, true);
	if (c1 == 'i' && c2 == 'j')
		return make_pair('k', true);
	if (c1 == 'j' && c2 == 'k')
		return make_pair('i', true);
	if (c1 == 'k' && c2 == 'i')
		return make_pair('j', true);
	if (c1 == 'j' && c2 == 'i')
		return make_pair('k', false);
	if (c1 == 'k' && c2 == 'j')
		return make_pair('i', false);
	if (c1 == 'i' && c2 == 'k')
		return make_pair('j', false);
	return make_pair('1', false);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	long long T;
	scanf("%lldd", &T);
	for (long long t = 0; t < T; ++t) {
		long long l;
		long long x;
		scanf("%lld %lld", &l, &x);
		scanf("%s", s);
		mul = '1';
		sign = true;
		for (long long i = 1; i <= l; ++i) {
			pair<char, bool> cur = mult(mul, s[i - 1]);
			mul = cur.first;
			if (cur.second != sign)
				sign = false;
			else
				sign = true;
		}
		char res = mul;
		bool si = true;
		if (res != '1') {
			if (!(x % 2))
				res = '1';
			if (x % 4 == 1 || x % 4 == 2)
				si = false;
		}
		bool prom = sign;
		if (x % 2 == 0)
			prom = true;
		if (prom != si)
			si = false;
		else
			si = true;
		if (res != '1' || si) {
			cout << "Case #" << t + 1 << ": NO\n";
			continue;
		}
		char cur_res = '1';
		bool cur_si = true;
		long long min_left = -1;
		bool flag = false;
		for (long long tr = 0; tr < min(x, 4ll) && !flag; ++tr) {
			if (cur_res == 'i' && cur_si) {
				min_left = l * tr;
				flag = true;
				break;
			}
			for (long long i = 1; i <= l; ++i) {
				pair<char, bool> cur = mult(cur_res, s[i - 1]);
				cur_res = cur.first;
				if (cur.second != cur_si)
					cur_si = false;
				else
					cur_si = true;	
				if (cur_res == 'i' && cur_si) {
					min_left = l * tr + i;
					flag = true;
					break;
				}
			}
		}
		if (min_left == -1) {
			printf("Case #%d: NO\n", t + 1);
			continue;
		}
		cur_res = '1', cur_si = true;
		long long min_right = -1;
		flag = false;
		for (long long tr = 0; tr < min(x, 4ll) && !flag; ++tr) {
			if (cur_res == 'k' && cur_si) {
				min_right = l * tr;
				flag = true;
				break;
			}
			for (long long i = l - 1; i >= 0; --i) {
				pair<char, bool> cur = mult(s[i], cur_res);
				cur_res = cur.first;
				if (cur.second != cur_si)
					cur_si = false;
				else
					cur_si = true;	
				if (cur_res == 'k' && cur_si) {
					min_right = l * tr + l - i;
					flag = true;
					break;
				}
			}
		}
		if (min_right == -1) {
			printf("Case #%d: NO\n", t + 1);
			continue;
		}
		if (min_left + min_right <= l * x) {
			printf("Case #%d: YES\n", t + 1);
		}
		else
			printf("Case #%d: NO\n", t + 1);
	}
    return 0;
}