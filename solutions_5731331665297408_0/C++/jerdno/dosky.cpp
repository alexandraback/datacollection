#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <fstream>

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//#include <random>
#include <time.h>

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ size

int test(vector<int> post, vector<pair<int, int> > spoje) {
	stack<int> pred;
	int i, ii, ok, d, z;
	z = post[0];
	for (i = 1; i < post.SZ(); i++) {	
		d = post[i];
		ok = 0;
		while (ok == 0) {
			for (ii = 0; ii < spoje.SZ(); ii++) {
				if ((spoje[ii].first == z && spoje[ii].second == d) || (spoje[ii].first == d && spoje[ii].second == z)) {
					ok = 1;
				}
			}
			if (ok == 0) {
				if (pred.SZ() == 0)
					return 0;
				else {
					z = pred.top();
					pred.pop();
				}
			}
		}
		pred.push(z);
		z = d;
	}
	return 1;
}

int main() {
	int i, pocet, ii, n, ok, iii, pom1, pom2, vys, a, b, c;
	vector<pair<string, int> > st;
	vector<pair<string, vector<int> > > meh;
	vector<pair<int, int> > st2, st3;
	vector<int> pocty;
	string s;
	double pom3;
	char last;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> a;
		cin >> b;
		for (ii = 0; ii < a; ii++) {
			cin >> s;
			st.PB(MP(s, ii + 1));
		}
		for (ii = 0; ii < b; ii++) {
			cin >> pom1;
			cin >> pom2;
			st2.PB(MP(pom1, pom2));
		}
		sort(st.begin(), st.end());
		do {
			s = "";
			for (ii = 0; ii < a; ii++)
				s = s + st[ii].first;
			for (ii = 0; ii < a; ii++)
				pocty.PB(st[ii].second);
			meh.PB(MP(s, pocty));
			pocty.clear();
		} while ( next_permutation(st.begin(),st.end()) );
		sort(meh.begin(), meh.end());
		for (ii = 0; ii < meh.SZ(); ii++) {
			if (test(meh[ii].second, st2) == 1) {
				cout << "Case #" << i + 1 << ": " << meh[ii].first << endl;
				break;
			}
		}
		meh.clear();
		st.clear();
		st2.clear();
	}
  	return 0;
}