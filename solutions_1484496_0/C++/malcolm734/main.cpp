#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>

#define var(x) #x
#define forn(i, n) for (int i = 0; i < ((int) n); ++i)
#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) (x)*(x)
#define all(x) x.begin(), x.end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#define sp ' '
#define elif else if
#define len(x) ((int) (x).size())
#define last(x) ((x)[(len(x))-1])
#define plast(x) ((x)[(len(x))-2])

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

template<typename type>
inline static void _cutedebug(const type &a){
	cerr << a;
}
template<typename type1, typename type2>
inline static void _cutedebug(const pair<type1, type2> &a){
	cerr << "("; _cutedebug(a.fs); cerr << ", "; _cutedebug(a.sc); cerr << ")";
}
template<typename type>
inline static void _cutedebug(const vector<type> &a){
	cerr << "[";
	bool flag = true;
	for (typename vector<type>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		_cutedebug(*i);
	}
	cerr << "]";
}
template<typename type>
inline static void _cutedebug(const set<type> &a){
	cerr << "{";
	bool flag = true;
	for (typename set<type>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		_cutedebug(*i);
	}
	cerr << "}";
}
template<typename type1, typename type2>
inline static void _cutedebug(const map<type1, type2> &a){
	cerr << "{";
	bool flag = true;
	for (typename map<type1, type2>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		cerr << "(";
		_cutedebug((*i).fs);
		cerr << ": ";
		_cutedebug((*i).sc);
		cerr << ")";
	}
	cerr << "}";
}
#ifdef CUTEBMAING
template<typename type>
inline static void _cutedebug_(const type &a, string name, int ln = __LINE__){
	cerr << "Line " << ln << " : " << name << " = "; _cutedebug(a); cerr << ";" << endl;
}
#define debug(x) _cutedebug_(x, var(x), __LINE__)
#endif
#ifndef CUTEBMAING
#define debug(x) ({})
#endif

const char* fin = "input.txt";
const char* fout = "output.txt";

const int inf = (1 << 30);
const int64 linf = (int64(1) << 61);
const ld eps = 1e-12;

int n;
vector<int> a;
vector<pair<int, int> > p;

void run(int t){
    cout << "Case #" << t << ":\n";
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    p.clear();
    for (int i = (1 << n)-1; i >= 1; i--){
        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)) > 0)
                sum += a[j];
        p.pb(mp(sum, i));
    }
    sort(all(p));
    for (int i = len(p)-2; i >= 0; i--)
        if (p[i].fs == p[i+1].fs){
            int mask1 = p[i].sc, mask2 = p[i+1].sc;
            int d = mask1 & mask2;
            mask1 ^= d; mask2 ^= d;
            for (int j = 0; j < n; j++)
                if ((mask1 & (1 << j)) > 0)
                    cout << a[j] << ' ';
            cout << endl;
            for (int j = 0; j < n; j++)
                if ((mask2 & (1 << j)) > 0)
                    cout << a[j] << ' ';
            cout << endl;
            return;
        }
    cout << "Impossible" << endl;
}

int main(){
    #ifdef CUTEBMAING
    assert(freopen(fin, "r", stdin));
    assert(freopen(fout, "w", stdout));
    #endif
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
		run(i);
    return 0;
}

