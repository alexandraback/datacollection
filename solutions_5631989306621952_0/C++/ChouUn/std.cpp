//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vpii;

#define rep(i,a,b) for(auto i=a,i##_n=b;i<i##_n;++i)
#define rrep(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : std.cpp
 *  Date : 2016年4月16日 上午8:59:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
	std::cout << "Case #" << __ << ": ";
	string s; cin >> s;
	deque<char> q;
	for(auto& ch : s) {
		if (q.empty()) q.push_front(ch);
		else {
			if (ch >= q.front()) q.push_front(ch);
			else q.push_back(ch);
		}
	}
	while (!q.empty()) cout << q.front(), q.pop_front(); cout << endl;
  }
  return 0;
}

