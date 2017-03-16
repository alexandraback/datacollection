/*
 * C
 * Apr 14, 2012,
 * Another buggy code by Khaled Samy;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)					(int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)
#define MOD(a,b) ((((a)%(b))+(b))%(b))
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 2e9;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

set<pair<int, int> > v;

void can(int a, int b) {
	string A = "", B = "";
	stringstream ss;
	ss << a;
	ss >> A;
	loop2(i,0,SZ(A)) {
		string f = A.substr(i);
		string s = A.substr(0, i);
		string B = f + s;
		if (atoi(B.c_str()) > a && atoi(B.c_str()) <= b)
			v.insert(make_pair(a, atoi(B.c_str())));
	}
}
int main() {
	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);
	int t;
	cin >> t;
	loop(tt,t) {
		int a, b;
		cin >> a >> b;
		v.clear();
		for (int i = a; i <= b; i++)
			can(i, b);
		printf("Case #%d: ", tt + 1);
		cout << SZ(v) << endl;
	}
	return 0;
}
