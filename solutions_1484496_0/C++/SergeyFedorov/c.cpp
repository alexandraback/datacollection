#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

char buf[100100];

int n;
int a[100100];
map<int, int> used;

void write(int x){
	forn(i, n)
		if (x & (1 << i))
			cout << a[i] << " ";
	cout << endl;
}

void write(int m1, int m2){
	forn(i, n)
		if (m1 & (1 << i))
			if (m2 & (1 << i)){
				m1 -= (1 << i);
				m2 -= (1 << i);
			}
	write(m1);
	write(m2);
}

void solve(){
	used.clear();
	cin >> n;
	int s = 0;
	forn(i, n){
     	cin >> a[i];
     	s += a[i];
     }
     forn(j, (1 << n)){
     	if (j == 0) continue;
     	int now = 0;
     	forn(i, n)
     		if (j & (1 << i))
     			now += a[i];
		if (used[now]){
			int m1 = used[now];
			int m2 = j;
			write(m1, m2);
			return;
		}
		used[now] = j;
	}
     puts("Impossible");
}

int main ()
{
	int n;
	cin >> n;
	gets(buf);
	forn(i, n){
		printf("Case #%d:\n", i + 1);
		solve();
	}

	
	return 0;
}
