#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <functional>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;

template<class T>
string tostring(T a){ stringstream ss; ss << a; return ss.str(); }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int dec(int x){
	return ((x - 1) + 10) % 10;
}
int inc(int x){
	return (x + 1) % 10;
}

struct ret{
	LL a, b;
	LL diff;
	ret(LL a, LL b, LL diff) :a(a), b(b), diff(diff){}
};

LL read(const VI &v){
	ostringstream ss;
	for(int x : v){
		assert(x >= 0);
		assert(x < 10);
		ss << x;
	}
	istringstream iss(ss.str());
	LL r;
	iss >> r;
	return r;
}

ret tr(VI a, VI b){
	VI orig_a = a;
	VI orig_b = b;
	int n = SZ(a);
	ret mi = ret(numeric_limits<LL>::max(), numeric_limits<LL>::max(), numeric_limits<LL>::max());
	//FOR(spl, n){
	for(int spl = -1; spl < n; spl++){
		a = orig_a;
		b = orig_b;

		int i;
		bool no = false;
		for(i = 0; i < spl; i++){
			if(a[i] == -1){
				if(b[i] == -1){
					a[i] = b[i] = 0;
				} else {
					a[i] = b[i];
				}
			} else { // a[i] != -1
				if(b[i] == -1){
					b[i] = a[i];
				} else {
					if(a[i] != b[i]){
						no = true;
						break;
					}
				}
			}
		}
		if(no){
			continue;
		}
		if(i < n && spl != -1){
			if(a[i] != -1 && b[i] != -1){
				if(a[i] > b[i])
					continue;
			} else {
				if(a[i] == -1 && b[i] == -1){
					a[i] = 0;
					b[i] = 1;
				} else {
					if(a[i] == -1){
						a[i] = dec(b[i]);
					} else {
						assert(b[i] == -1);
						b[i] = inc(a[i]);
					}
				}
			}
		}
		if(spl != -1){
			i++;
		}
		for(; i < n; i++){
			if(a[i] == -1 && b[i] == -1){
				a[i] = 9;
				b[i] = 0;
			} else if(a[i] == -1 && b[i] != -1){
				a[i] = 9;
			} else if(a[i] != -1 && b[i] == -1){
				b[i] = 0;
			} else { // a[i] != -1 && b[i] != -1
				//semmi
			}
		}
		
		LL ar = read(a);
		LL br = read(b);
		//assert(ar <= br);
		if(ar <= br){
			if(br - ar < mi.diff ||
				(br - ar == mi.diff && ar < mi.a) ||
				(br - ar == mi.diff && br < mi.b)){
				mi = ret(ar, br, br - ar);
			}
		}
	}
	return mi;
}

ret eq(VI a, VI b){
	FOR(i, SZ(a)){
		if(a[i] == -1 && b[i] == -1){
			a[i] = 0;
			b[i] = 0;
		} else if(a[i] == -1 && b[i] != -1){
			a[i] = b[i];
		} else if(a[i] != -1 && b[i] == -1){
			b[i] = a[i];
		} else { // a[i] != -1 && b[i] != -1
			if(a[i] != b[i]){
				return ret(-1, -1, -1);
			}
		}
	}
	LL ar = read(a);
	LL br = read(b);
	return ret(ar, br, 0);
}

int main(){
	ifstream be("B-large.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		string as, bs;
		be >> as >> bs;

		VI a, b;
		for(char c : as){
			if(c == '?')
				a.push_back(-1);
			else
				a.push_back(c - '0');
		}
		for(char c : bs){
			if(c == '?')
				b.push_back(-1);
			else
				b.push_back(c - '0');
		}

		ret r1 = tr(a, b);
		ret r2 = tr(b, a);

		ret r3 = eq(a, b);

		//ki << setfill('0') << setw(SZ(as));
		if(r3.diff == 0){
			ki << "Case #" << tt + 1 << ": " << setfill('0') << setw(SZ(as)) << r3.a << " " << setfill('0') << setw(SZ(as)) << r3.b << endl;
		} else {

			if(r1.diff < r2.diff){
				ki << "Case #" << tt + 1 << ": " << setfill('0') << setw(SZ(as)) << r1.a << " " << setfill('0') << setw(SZ(as)) << r1.b << endl;
			} else if(r1.diff > r2.diff){
				ki << "Case #" << tt + 1 << ": " << setfill('0') << setw(SZ(as)) << r2.b << " " << setfill('0') << setw(SZ(as)) << r2.a << endl;
			} else {
				if(r1.a < r2.a){
					ki << "Case #" << tt + 1 << ": " << setfill('0') << setw(SZ(as)) << r1.a << " " << setfill('0') << setw(SZ(as)) << r1.b << endl;
				} else {
					ki << "Case #" << tt + 1 << ": " << setfill('0') << setw(SZ(as)) << r2.b << " " << setfill('0') << setw(SZ(as)) << r2.a << endl;
				}
			}
		}

		//ki<<"Case #"<<tt+1<<": "<< <<endl;
	}

	ki.close();
	return 0;
}