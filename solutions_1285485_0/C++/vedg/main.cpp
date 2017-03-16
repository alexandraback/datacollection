#define IDBG
//#undef IDBG

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <deque>
#include <set>

using namespace std;

struct Fraction {
    int a, b; // a/b
    int sq;
	Fraction(int a, int b): a(a), b(b) {}
    void reduce() {
		if (a < 0) {
			if (b < 0) {
				sq = 0;
				b = - b;
			} else
				sq = 1;
			a = - a;
		} else {
			if (b < 0) {
				sq = 2;
				b = - b;
			} else
				sq = 3;
		}
		
		
        if (a == 0) {
            b = 1;
            return;
        }
        if (b == 0) {
            a = 1;
            return;
        }
        int p = min(a, b);       
        int q = int(sqrt(p) + 0.1);
		deque<int> d;
		for (int i = 2; i <= q; ++i) {
			while (p % i == 0) {
				p /= i;
				d.push_back(i);
			}
		}
		if (p != 1)
			d.push_back(p);
		int * big, * little;
		if (a < b) {
			big = & b;
			little = & a;
		} else {
			big = & a;
			little = & b;
		}			
		
		for (int i = 0; i < d.size(); ++i) {
			if (*big % d[i] == 0) {
				*big /= d[i];
				*little /= d[i];
			}
		}
    }

	bool operator<(const Fraction & right) const {
		if (sq != right.sq)
			return sq < right.sq;
		return a == right.a ? b < right.b : a < right.a;
	}
};

int main() {
#ifdef IDBG
    freopen("cin", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1;cas <= cases;++cas) {
        cout << "Case #" << cas << ": ";
		int h, w, d;
		cin>>h>>w>>d;
		int d2 = d * d;
		int x=-1,y;
        for (int i = 0; i < h; ++i) {
			string s;
			cin>>s;
			if (x != -1)
				continue;
			for (int j = 0; j < w; ++j)
				if (s[j] == 'X') {
					x = j;
					y = i;
				}
        }
        w -= 2;
		h -= 2;
		--x;
		--y;
        
        int up = d / h + 1, right = d / w + 1;
		
		set<Fraction> fSet;
		
		for (int i = - up; i <= up; ++i) {
			for (int j = - right; j <= right; ++j) {
				if (i == 0 && j == 0)
					continue;
				int r = j * w;
				r += j % 2 == 0 ? x : w - x - 1;
				int down = i * h;
				down += i % 2 == 0 ? y : h - y - 1;
				
				r -= x;
				down -= y;
				if (r * r + down * down <= d2) {
					Fraction f(r, down);
					f.reduce();
					fSet.insert(f);
				}
			}
		}
        
        
        
        
        
        
        cout << fSet.size();
		cout << endl;
	}

#ifdef IDBG
        putchar('\n')
            ;
    fclose(stdin);
    fclose(stdout);
#endif
}

