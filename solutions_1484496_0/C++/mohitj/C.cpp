#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <sstream>
using namespace std;

#define UN(c) SORT(c),v.erase(unique(c.begin(),c.end()),c.end())
#define SORT(c) sort(c.begin(), c.end())

int ns[20];
int N;
int s1;

int find_sum(int bs) {
	int sum = 0;
	for(int i = 0, f = 1; i < N; ++i, f <<= 1) {
		if(bs & f) sum += ns[i];
	}
	return sum;
}

std::string print_them(int bs) {
	std::stringstream ss;
	for(int i = 0, f = 1; i < N; ++i, f <<= 1) {
		if(bs & f) ss << ns[i] << ' ';
	}
	const string s = ss.str();
	return s.substr(0, s.size()-1);
}


int main()
{
	if( freopen("C-small.in", "rt", stdin) ) {
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		int ia = -1, ja = 0;
		cin >> N;
		for(int i = 0; i < N; ++i) cin >> ns[i];
		for(int i = 1; i < (1<<20); ++i) {
			int is = find_sum(i);
			for(int j = 1; j < (1 << 20); ++j) {
				if(i & j) continue;
				int js = find_sum(j);
				if(is == js) {
					ia = i, ja = j;
					goto ans_lvl;
				}
			}
		}
ans_lvl:
		//cout << "Case #" << case_num << ": ";
		if(ia == -1) cout << "Case #" << case_num << ':' << endl << "Impossible" << endl;
		cout << "Case #" << case_num << ':' << endl << print_them(ia) << endl << print_them(ja) << endl;
	}
 	return 0;
}