#pragma comment(linker, "/STACK:5000000000")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <ctime>
#include <unordered_map>
#include <set>
#include <stack>
#include <cassert>
#include <deque>
#include <bitset>
#include <unordered_set>

#define LOCAL

using namespace std;

int mn[333][333];
char sg[333][333];
int dv[333][333];
char dsg[333][333];

void pre () {
	mn[1][1] = 1;
	mn[1]['i'] = 'i';
	mn[1]['j'] = 'j';
	mn[1]['k'] = 'k';

	mn['i'][1] = 'i';
	mn['i']['i'] = 1;
	sg['i']['i'] = 1;
	mn['i']['j'] = 'k';
	mn['i']['k'] = 'j';
	sg['i']['k'] = 1;

	mn['j'][1] = 'j';
	mn['j']['i'] = 'k';
	sg['j']['i'] = 1;
	mn['j']['j'] = 1;
	sg['j']['j'] = 1;
	mn['j']['k'] = 'i';

	mn['k'][1] = 'k';
	mn['k']['i'] = 'j';
	mn['k']['j'] = 'i';
	sg['k']['j'] = 1;
	mn['k']['k'] = 1;
	sg['k']['k'] = 1;

	dv[1][1] = 1;
	dv[1]['i'] = 'i';
	dsg[1]['i'] = 1;
	dv[1]['j'] = 'j';
	dsg[1]['j'] = 1;
	dv[1]['k'] = 'k';
	dsg[1]['k'] = 1;

	dv['i'][1] = 'i';
	dv['i']['i'] = 1;
	dv['i']['j'] = 'k';
	dsg['i']['j'] = 1;
	dv['i']['k'] = 'j';

	dv['j'][1] = 'j';
	dv['j']['i'] = 'k';
	dv['j']['j'] = 1;
	dv['j']['k'] = 'i';
	dsg['j']['k'] = 1;

	dv['k'][1] = 'k';
	dv['k']['i'] = 'j';
	dsg['k']['i'] = 1;
	dv['k']['j'] = 'i';
	dv['k']['k'] = 1;
}

struct qt {
	int val;
	char sgn;

	qt (int val = 0, char sgn = 0) : val(val), sgn(sgn) {};

	qt operator * (const qt &x) const{
		return qt (mn[val][x.val], sgn ^ x.sgn ^ sg[val][x.val]);
	};

	qt operator / (const qt &x) const{
		return qt (dv[val][x.val], sgn ^ x.sgn ^ dsg[val][x.val]);
	};

	bool operator == (const qt &x) const {
		return val == x.val && sgn == x.sgn;
	};

	bool operator != (const qt &x) const {
		return val != x.val || sgn != x.sgn;		
	};

	string get_val () {
		string ret;
		if (sgn)
			ret += '-';
		if (val == 1)
			ret += '1';
		else
			ret += val;
		return ret;
	};
};
      
int ans;
int T;
string Ans[] = {"NO", "YES"};
int l, x;
string tmp;
string s;
qt mas[10004];
const qt last (1, 1);
const qt I ('i', 0);
const qt K ('k', 0);
const qt pre_last = last / K;

void print_ans (int t, int ans) {
	printf ("Case #%d: %s\n", t, Ans[ans].c_str ());
}

int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);
#endif                                
	//freopen (".in", "r", stdin);
	//freopen (".out", "w", stdout);

	pre ();
	mas[0] = qt (1, 0);

	cin >> T;

	for (int t = 1; t <= T; t++) {
    	
    	cin >> l >> x >> tmp;

		s = "&";

		for (int i = 0; i < x; i++)
			s += tmp;

		int n = s.size ();

		for (int i = 1; i < n; i++) 
			mas[i] = mas[i - 1] * qt (s[i], 0);	

		if (mas[n - 1] != last) {
			print_ans (t, 0);
			continue;
		}

		int pos = -1;
		
		for (int i = 1; i < n; i++) {
			bool tt = mas[i] == I;
			if (mas[i] == I) {
				pos = i;
				break;
			}
		}

		if (-1 == pos) {
			print_ans (t, 0);
			continue;
		}

		for (int i = pos + 1; i < n; i++) {
			if (mas[i] == K) {
				pos = -1;
				break;
			}
		}

		if (-1 != pos) {
			print_ans (t, 0);
			continue;
		}

		print_ans (t, 1);    	
    }

	return 0;
}