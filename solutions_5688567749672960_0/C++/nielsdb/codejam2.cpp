// codejam2.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <set>
#include <regex>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <functional>
#include <bitset>
#define INF 2000000000
#define endl "\n"
#define gcd(x,y) __gcd((x),(y))
#define	all(c)	(c).begin(), (c).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
const long long mod = 1000000007;

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

vector<int> rdigs(int i){ vector<int> r; while (i){ r.push_back(i % 10); i /= 10; }return r; }
ull digstoint(vi d){ ull r = 0; for (vi::size_type i = 0; i < d.size(); i++){ r *= 10; r += d[i]; }return r; }

ull smallestBSwap(int i){
	auto digs = rdigs(i);
	sort(digs.begin(), digs.end());
	int zeroC = 0;
	for (int dig : digs){
		if (dig == 0) zeroC++;
		else break;
	}
	swap(digs[0], digs[zeroC]);
	return digstoint(digs);
}

int nbZeros(int i){
	auto digs = rdigs(i);
	int zeroC = 0;
	for (int dig : digs){
		if (dig == 0) zeroC++;
	}
	return zeroC;
}

int main(){
	ios::sync_with_stdio(false);
	int nbCases;
	cin >> nbCases;
	for (int caseNb = 1; caseNb <= nbCases; caseNb++){
		ull N;
		cin >> N;
		ull count = 1;
		while (N!=1){
			//cout << N << endl;
			count++;
			if (nbZeros(N) > nbZeros(N - 1) && smallestBSwap(N) != N){
				N = smallestBSwap(N);
			}
			else if (nbZeros(N - 1) > nbZeros(N) && nbZeros(N-1) < rdigs(N-1).size()-1){
				N--;
			}
			else if (smallestBSwap(N) < smallestBSwap(N - 1)){
				N = min(smallestBSwap(N), N - 1);
			}
			else
			{
				N--;
			}
		}

		cout << "Case #" << caseNb << ": " << count << endl;
	}
	return 0;
}