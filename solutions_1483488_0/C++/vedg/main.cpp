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
#include <set>

using namespace std;

int arr[9];

void decompose(int n) {
	for (int i = 0; n > 0; ++i) {
		arr[i] = n % 10;
		n /= 10;
	}
}

int main() {
#ifdef IDBG
    freopen("cin", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	int cases;
	cin>>cases;
	for (int cas=1;cas<=cases;++cas){		
		cout<<"Case #"<<cas<<": ";
		
		int a, b;
		cin>>a>>b;
		int count = 0;
		if (a < 12)
			a = 12;
		for (int i = 0; i< 9;++i)
			arr[i]=0;
		decompose(a);
		int last;
		for (int i = 0; i < 9; ++i) {
			if (arr[i] != 0)
				last = i;
		}
		int big = 1;
		for (int i = 0; i <= last; ++i) {
			big *= 10;
		}
		int small = big / 10;
		for (int n = a; n <= b; ++n) {
			decompose(n);
			if (n == big) {
				++last;
				big *= 10;
				small *= 10;
			}
			set<int> s;
			int p = n;
			for (int i = 0; i < last; ++i) {
				p = p / 10 + arr[i] * small;
				if (arr[i] != 0 && p > n && p <= b)
					s.insert(p);
			}
			count += s.size();			
		}
		cout<<count;
		cout<<endl;
	}
		
#ifdef IDBG
	putchar('\n');
    fclose(stdin);
	fclose(stdout);    
#endif
}

