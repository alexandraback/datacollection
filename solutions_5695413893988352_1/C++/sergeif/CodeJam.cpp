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

	bool beqa = true;
	bool alb = false;
	bool bla = false;
	for (int i = 0; i < ans.a.size() && beqa && !alb && !bla; ++i){
		if (ans.a[i] < ans.b[i]) alb = true;
		if (ans.b[i] < ans.a[i]) bla = true;
		if (ans.a[i] != ans.b[i]) beqa = false;
	}
	
	if (s2[pos] == '?' && s1[pos] == '?') {
		TAns bestRes;
		if (beqa) {
			int npos = pos + 1;
			while (beqa && npos < s1.length()){
				//std::cout << pos << " " << s1[npos] << " " << s2[npos] << std::endl;
				if (s1[npos] == '?' || s2[npos] == '?') {
					npos++;
					continue;
				}
				int an = (int)(s1[npos] - '0');
				int bn = (int)(s2[npos] - '0');
				if (an != bn) {
					beqa = false;
					if (an < bn) alb = true;
					else bla = true;
					break;
				}
				npos++;
			}
			newans.a.push_back(0);
			newans.b.push_back(0);
			TAns zer = FindMin(s1, s2, pos + 1, newans);
			TAns newans = ans;
			if (alb) {
				newans.a.push_back(1);
				newans.b.push_back(0);
				TAns one = FindMin(s1, s2, pos + 1, newans);
				//std::cout << abs(one.diff) << " " << abs(zer.diff) << std::endl;
				if (abs(one.diff) < abs(zer.diff)) {
					return one;
				}
				return zer;
			}
			else {
				newans.a.push_back(0);
				newans.b.push_back(1);
				TAns one = FindMin(s1, s2, pos + 1, newans);
				
				if (abs(one.diff) < abs(zer.diff)) {
					return one;
				}
				return zer;
			}
		}
		else if (bla) {
			newans.a.push_back(0);
			newans.b.push_back(9);
			return FindMin(s1, s2, pos + 1, newans);
		}
		else if (alb) {
			newans.a.push_back(9);
			newans.b.push_back(0);
			return FindMin(s1, s2, pos + 1, newans);
		}
	}
	if (s2[pos] == '?' && s1[pos] != '?') {
		int ai = a;
		int bi = ai;
		if (beqa) {
			int npos = pos + 1;
			while (beqa && npos < s1.length()){
				if (s1[npos] == '?' || s2[npos] == '?') {
					npos++;
					continue;
				}
				int an = (int)(s1[npos] - '0');
				int bn = (int)(s2[npos] - '0');
				if (an != bn) {
					beqa = false;
					if (an < bn) alb = true;
					else bla = true;
				}
				npos++;
			}
			newans.a.push_back(ai);
			newans.b.push_back(ai);
			TAns zer = FindMin(s1, s2, pos + 1, newans);
			TAns newans = ans;
			if (alb && ai > 0) {
				newans.a.push_back(ai);
				newans.b.push_back(ai - 1);
				TAns one = FindMin(s1, s2, pos + 1, newans);
				if (abs(one.diff) <= abs(zer.diff)) {
					return one;
				}
				return zer;
			}
			else if (bla && bi < 9) {
				newans.a.push_back(bi);
				newans.b.push_back(bi + 1);
				TAns one = FindMin(s1, s2, pos + 1, newans);
				if (abs(one.diff) < abs(zer.diff)) {
					return one;
				}
				return zer;
			}
			return zer;
		} 
		if (alb) {
			bi = 0;
		} else if (bla) {
			bi = 9;
		}
		newans.a.push_back(ai);
		newans.b.push_back(bi);
		return FindMin(s1, s2, pos + 1, newans);
	}
	if (s2[pos] != '?' && s1[pos] == '?') {
		int bi = b;
		int ai = bi;
		if (beqa) {
			int npos = pos + 1;
			while (beqa && npos < s1.length()){
				if (s1[npos] == '?' || s2[npos] == '?') {
					npos++;
					continue;
				}
				int an = (int)(s1[npos] - '0');
				int bn = (int)(s2[npos] - '0');
				if (an != bn) {
					beqa = false;
					if (an < bn) alb = true;
					else bla = true;
				}
				npos++;
			}
			newans.a.push_back(ai);
			newans.b.push_back(ai);
			TAns zer = FindMin(s1, s2, pos + 1, newans);
			TAns newans = ans;
			if (alb && ai < 9) {
				newans.a.push_back(ai + 1);
				newans.b.push_back(ai);
				TAns one = FindMin(s1, s2, pos + 1, newans);
				if (abs(one.diff) < abs(zer.diff)) {
					return one;
				}
				return zer;
			}
			else if (bla && bi > 0) {
				newans.a.push_back(bi - 1);
				newans.b.push_back(bi);
				TAns one = FindMin(s1, s2, pos + 1, newans);
				if (abs(one.diff) <= abs(zer.diff)) {
					return one;
				}
				return zer;
			}
			return zer;
		}
		if (alb) {
			ai = 9;
		}
		else if (bla) {
			ai = 0;
		}
		newans.a.push_back(ai);
		newans.b.push_back(bi);
		return FindMin(s1, s2, pos + 1, newans);
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

