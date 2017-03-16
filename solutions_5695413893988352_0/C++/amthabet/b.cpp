#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<sstream>
#include<cassert>
using namespace std;

#define SMALL 1
//#define LARGE 1

string ra, rb;
long long best;

void f(string a, string b, int i, bool e, bool g) {
	if(i == a.size()) {
		stringstream ss;
		ss<<a<<" "<<b;
		long long aa, bb;
		ss>>aa>>bb;
		long long cur = abs((long long)(aa-bb));
		if(best == -1 || best > cur) {
			best = cur;
			ra = a;
			rb = b;
		}
		return ;
	}
	if(a[i] != '?' && b[i] != '?') {
		f(a, b, i+1, e && (a[i] == b[i]), g || (e && a[i] > b[i]));
		return;
	}
	if(e) {
		if(a[i] == b[i]) {
			string aa = a;
			aa[i] = '0';
			f(aa, b, i, e, g);
			string bb = b;
			bb[i] = '0';
			f(a, bb, i, e, g);
			return;
		}
		if(a[i] == '?') {
			if(b[i] != '0') {
				a[i] = b[i]-1;
				f(a, b, i+1, 0, 0);
			}
			a[i] = b[i];
			f(a, b, i+1, e, g);
			if(b[i] != '9') {
				a[i] = b[i]+1;
				f(a, b, i+1, 0, 1);
			}
		} else {
			if(a[i] != '0') {
				b[i] = a[i]-1;
				f(a, b, i+1, 0, 1);
			}
			b[i] = a[i];
			f(a, b, i+1, e, g);
			if(a[i] != '9') {
				b[i] = a[i]+1;
				f(a, b, i+1, 0, 0);
			}
		}
		return ;
	}
	if(a[i] == '?') {
		if(g) a[i] = '0';
		else a[i] = '9';
	}
	if(b[i] == '?'){
		if(g) b[i] = '9';
		else b[i] = '0';
	}
	f(a, b, i+1, 0, g);
}

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small_7.i", "rt", stdin);
	freopen("b_small_7.o", "wt", stdout);
#else
	//freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		string a, b;
		cin>>a>>b;
		best = -1;
		/*int e = 1;
		int greater = 0;
		for(int i=0;i<a.size();i++) {
			//cerr << e << " " << greater <<endl;
			assert(!(e && greater));
			if(a[i] != '?' && b[i] != '?') {
				greater = (greater || (e && (a[i] > b[i])));
				e = (e && (a[i] == b[i]));
				continue;
			}
			if(e) {
				if(a[i] == b[i]) {
					a[i] = b[i] = '0';
				} else if(a[i] == '?') {
					a[i] = b[i];
				} else {
					b[i] = a[i];
				}
			} else {
				if(a[i] == '?') {
					if(greater) a[i] = '0';
					else a[i] = '9';
				}
				if(b[i] == '?'){
					if(greater) b[i] = '9';
					else b[i] = '0';
				}
			}
		}*/
		f(a, b, 0, 1, 0);
		cout<<"Case #"<<tt<<": "<<ra<<" "<<rb<<endl;
	}

	return 0;
}
