// CodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

struct THyp{
	int minv;
	int amin;
	int bmin;
	int azero;
	int bzero;
	int maxv;
	int amax;
	int bmax;
};

THyp hipoteses[18];
int ansa[18];
int ansb[18];

struct TAns {
	std::vector<int> a;
	std::vector<int> b;
	long long diff;
};

TAns FindMin(const std::string& s1, const std::string& s2, int pos, TAns ans) {
	TAns newans = ans;
	if (pos >= s1.length()) {
		long long a = 0;
		long long b = 0;
		long long bs = 1;
		for (int i = ans.a.size() - 1; i >=0; --i) {
			a += ans.a[i] * bs;
			b += ans.b[i] * bs;
			bs *= 10;
		}
		newans.diff = b - a;
		return newans;
	}
	int a = (int)(s1[pos] - '0');
	int b = (int)(s2[pos] - '0');
	if (s1[pos] != '?' && s2[pos] != '?') {
		newans.a.push_back(a);
		newans.b.push_back(b);
		return FindMin(s1, s2, pos + 1, newans);
	}
	
	if (s2[pos] == '?' && s1[pos] == '?') {
		long long maxDiff = 1e20;
		TAns bestRes;
		for (int ai = 0; ai < 10; ++ai) {
			for (int bi = 0; bi < 10; ++bi) {
				TAns nans = ans;
				nans.a.push_back(ai);
				nans.b.push_back(bi);
				TAns res = FindMin(s1, s2, pos + 1, nans);
				if (abs(res.diff) < maxDiff) {
					bestRes = res;
					maxDiff = abs(res.diff);
				} else if (abs(res.diff) == maxDiff) {
					bool bettera = false;
					bool beqa = true;
					for (int i = 0; i < res.a.size() && ! bettera && beqa; ++i) {
						if (bestRes.a[i] > res.a[i]) bettera = true;
						else if (res.a[i] > bestRes.a[i]) beqa = false;
					}
					if (bettera) {
						bestRes = res;
						maxDiff = abs(res.diff);
					} else if (beqa) {
						bool betterb = false;
						bool beqb = true;
						for (int i = 0; i < res.a.size() && !betterb && beqb; ++i) {
							if (bestRes.b[i] > res.b[i]) betterb = true;
							else if (res.b[i] > bestRes.b[i]) beqb = false;
						}
						if (betterb) {
							bestRes = res;
							maxDiff = abs(res.diff);
						}
					}
				}
			}
		}
		return bestRes;
	}
	if (s2[pos] == '?' && s1[pos] != '?') {
		long long maxDiff = 1e20;
		TAns bestRes;
		int ai = a;
		for (int bi = 0; bi < 10; ++bi) {
			TAns nans = ans;
			nans.a.push_back(ai);
			nans.b.push_back(bi);
			TAns res = FindMin(s1, s2, pos + 1, nans);
			if (abs(res.diff) < maxDiff) {
				bestRes = res;
				maxDiff = abs(res.diff);
			}
			else if (abs(res.diff) == maxDiff) {
				bool bettera = false;
				bool beqa = true;
				for (int i = 0; i < res.a.size() && !bettera && beqa; ++i) {
					if (bestRes.a[i] > res.a[i]) bettera = true;
					else if (res.a[i] > bestRes.a[i]) beqa = false;
				}
				if (bettera) {
					bestRes = res;
					maxDiff = abs(res.diff);
				}
				else {
					bool betterb = false;
					bool beqb = true;
					for (int i = 0; i < res.a.size() && !betterb && beqb; ++i) {
						if (bestRes.b[i] > res.b[i]) betterb = true;
						else if (res.b[i] > bestRes.b[i]) beqb = false;
					}
					if (betterb) {
						bestRes = res;
						maxDiff = abs(res.diff);
					}
				}
			}
		}
		return bestRes;
	}
	if (s2[pos] != '?' && s1[pos] == '?') {
		long long maxDiff = 1e20;
		TAns bestRes;
		int bi = b;
		for (int ai = 0; ai < 10; ++ai) {
			TAns nans = ans;
			nans.a.push_back(ai);
			nans.b.push_back(bi);
			TAns res = FindMin(s1, s2, pos + 1, nans);
			if (abs(res.diff) < maxDiff) {
				bestRes = res;
				maxDiff = abs(res.diff);
			}
			else if (abs(res.diff) == maxDiff) {
				bool bettera = false;
				bool beqa = true;
				for (int i = 0; i < res.a.size() && !bettera && beqa; ++i) {
					if (bestRes.a[i] > res.a[i]) bettera = true;
					else if (res.a[i] > bestRes.a[i]) beqa = false;
				}
				if (bettera) {
					bestRes = res;
					maxDiff = abs(res.diff);
				}
				else {
					bool betterb = false;
					bool beqb = true;
					for (int i = 0; i < res.a.size() && !betterb && beqb; ++i) {
						if (bestRes.b[i] > res.b[i]) betterb = true;
						else if (res.b[i] > bestRes.b[i]) beqb = false;
					}
					if (betterb) {
						bestRes = res;
						maxDiff = abs(res.diff);
					}
				}
			}
		}
		return bestRes;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::string s, s1, s2;
		std::cout << "Case #" << t << ": ";
		std::cin >> s1 >> s2;
		int N = s1.length();
		TAns ans;
		TAns res = FindMin(s1, s2, 0, ans);
		for (int i = 0; i < N; ++i) std::cout << res.a[i];
		std::cout << " ";
		for (int i = 0; i < N; ++i) std::cout << res.b[i];
		std::cout << std::endl;
	}
	return 0;
}

