#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <math.h>
#include <utility>
#include <sstream>
#pragma comment(linker, "/STACK:133217728")

using namespace std;

bool good(int n, string s) {
	if(s.length() == 1 && n > 9) return false;
	if(s.length() == 2 && (n < 10 || n > 99)) return false;
	if(s.length() == 3 && (n < 100)) return false;
	string w = "";
	while(w.length() != s.length()) {
		w = char('0' + n % 10) + w;
		n /= 10;
		//cout << w << endl;
	}

	for(int i=0; i<s.length(); i++)
		if(w[i] != s[i] && s[i] != '?' && w[i] != '?')
			return false;

	return true;
}

long long diff(string& a, string& b) {
	long long x = 0;
	long long y = 0;

	for(int i=0; i<a.length(); i++) {
		if(a[i] == '?') {
			if(b[i] == '?') b[i] = '0';
			a[i] = '9';
		} 
		if(b[i] == '?') {
			b[i] = '0';
		}
		x = x * 10 + a[i] - '0';
		y = y * 10 + b[i] - '0';
	}
	return abs(x - y);
}

long long toLong(string s) {
	long long ans = 0;
	for(int i=0; i<s.length(); i++)
		ans = ans * 10 + s[i] - '0';
	return ans;
}
int main() {  
	freopen("in.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	
	int T;
	cin >> T;
	

	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		string a, b;
		cin >> a >> b;
		long long ansa = 1e+18, ansb = 1e+18;
		long long dif = ansa;
		string sa, sb;
		int k = 0;
		for(int i=0; i<a.length(); i++)
			if(a[i] != b[i] && a[i] != '?' && b[i] != '?') {
				if(a[i] < b[i]) k = -1; else
					k = 1;
				break;
			}

		//if(k == 1) swap(a, b);
		if(!k) {
			for(int i=0; i<a.length(); i++)
				if(a[i] == '?') {
					if(b[i] == '?') b[i] = '0';
					a[i] = b[i];
				} else if(b[i] == '?') {					
					b[i] = a[i];
				}
			cout << a << " " << b << endl;
			continue;
		}
		bool was = 0;
		string aa, bb;
		for(int i=0; i<a.length(); i++) {
			if(a[i] == '?') {
				if(b[i] == '?') {
					aa = a, bb = b;
					bb[i] = '1'; aa[i] = '0';
					long long d = diff(aa, bb);
					if(d < dif) {
						ansa = toLong(aa), ansb = toLong(bb), dif = d;
					} else 
						if(d == dif && ansa > toLong(aa)) {
							ansa = toLong(aa), ansb = toLong(bb);
						} else
							if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
								ansb = toLong(bb);
							}
							aa = a, bb = b;
					bb[i] = '0'; aa[i] = '1';
					d = diff(bb, aa);
					if(d < dif) {
						ansa = toLong(aa), ansb = toLong(bb), dif = d;
					} else 
						if(d == dif && ansa > toLong(aa)) {
							ansa = toLong(aa), ansb = toLong(bb);
						} else
							if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
								ansb = toLong(bb);
							}
					aa = a, bb = b;
					bb[i] = '9'; aa[i] = '0';
					d = diff(bb, aa);
					if(d < dif) {
						ansa = toLong(aa), ansb = toLong(bb), dif = d;
					} else 
						if(d == dif && ansa > toLong(aa)) {
							ansa = toLong(aa), ansb = toLong(bb);
						} else
							if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
								ansb = toLong(bb);
							}
					aa = a, bb = b;
					bb[i] = '0'; aa[i] = '9';
					d = diff(aa, bb);
					if(d < dif) {
						ansa = toLong(aa), ansb = toLong(bb), dif = d;
					} else 
						if(d == dif && ansa > toLong(aa)) {
							ansa = toLong(aa), ansb = toLong(bb);
						} else
							if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
								ansb = toLong(bb);
							}
					a[i] = '0';
					b[i] = '0';
				} else {
					if(b[i] != '0') {
						aa = a, bb = b;
						aa[i] = bb[i] - 1;
						long long d = diff(aa, bb);
						if(d < dif) {
							ansa = toLong(aa), ansb = toLong(bb), dif = d;
						} else 
							if(d == dif && ansa > toLong(aa)) {
								ansa = toLong(aa), ansb = toLong(bb);
							} else
								if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
									ansb = toLong(bb);
								}
					}
						aa = a, bb = b;
						aa[i] = '0';
						long long d = diff(bb, aa);
						if(d < dif) {
							ansa = toLong(aa), ansb = toLong(bb), dif = d;
						} else 
							if(d == dif && ansa > toLong(aa)) {
								ansa = toLong(aa), ansb = toLong(bb);
							} else
								if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
									ansb = toLong(bb);
								}
						aa = a, bb = b;
						aa[i] = '9';
						d = diff(aa, bb);
						if(d < dif) {
							ansa = toLong(aa), ansb = toLong(bb), dif = d;
						} else 
							if(d == dif && ansa > toLong(aa)) {
								ansa = toLong(aa), ansb = toLong(bb);
							} else
								if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
									ansb = toLong(bb);
								}
					
					a[i] = b[i];
				}
			} 
			if(b[i] == '?') {
				if(a[i] != '0') {
						aa = a, bb = b;
						bb[i] = aa[i] - 1;
						long long d = diff(bb, aa);
						if(d < dif) {
							ansa = toLong(aa), ansb = toLong(bb), dif = d;
						} else 
							if(d == dif && ansa > toLong(aa)) {
								ansa = toLong(aa), ansb = toLong(bb);
							} else
								if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
									ansb = toLong(bb);
								}
				}
						aa = a, bb = b;
						bb[i] = '0';
						long long d = diff(bb, aa);
						if(d < dif) {
							ansa = toLong(aa), ansb = toLong(bb), dif = d;
						} else 
							if(d == dif && ansa > toLong(aa)) {
								ansa = toLong(aa), ansb = toLong(bb);
							} else
								if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
									ansb = toLong(bb);
								}
						aa = a, bb = b;
						bb[i] = '9';
						d = diff(bb, aa);//cout << aa << " " << bb << endl;

						if(d < dif) {
							ansa = toLong(aa), ansb = toLong(bb), dif = d;
						} else 
							if(d == dif && ansa > toLong(aa)) {
								ansa = toLong(aa), ansb = toLong(bb);
							} else
								if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
									ansb = toLong(bb);
								}
					
				b[i] = a[i];
			}
		}
		aa = a, bb = b;
		long long d = diff(aa, bb);
		if(d < dif) {
			ansa = toLong(aa), ansb = toLong(bb), dif = d;
		} else 
			if(d == dif && ansa > toLong(aa)) {
				ansa = toLong(aa), ansb = toLong(bb);
			} else
				if(d == dif && ansa == toLong(aa) && ansb > toLong(bb)) { 
					ansb = toLong(bb);
				}
		//if(k == 1) cout << b << " " << a << endl; else
		sa = "";
		sb = "";
		while(ansa > 0) {
			sa = char('0' + ansa % 10) + sa;
			ansa /= 10;
		}
		while(ansb > 0) {
			sb = char('0' + ansb % 10) + sb;
			ansb /= 10;
		}

		while(sa.length() < a.length()) {
			sa = '0' + sa;
		}
		while(sb.length() < b.length()) {
			sb = '0' + sb;
		}
		//cout << a << " "  << b << endl;
		cout << sa << " " << sb << endl;
/*		int ansa = 0, ansb = 1000, dif = 1000;
		for(int i=0; i<1000; i++)
			for(int j=0; j<1000; j++)
				if(good(i, a) && good(j, b)) {
					if(abs(i - j) < dif) {
						ansa = i;
						ansb = j;
						dif = abs(i - j);
					} else
					if(abs(i - j) == dif && (i < ansa)) {
						ansa = i;
						ansb = j;
					} else 
						if(abs(i - j) == dif && i == ansa && j < ansb) {
						ansb = j;
					}

				}
				cout << ansa << " " << ansb << endl;
				*/
		//cout << endl;
	}
	
	return 0;
}