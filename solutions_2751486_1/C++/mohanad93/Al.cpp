#include <iterator>
#include <cstring>
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
#include <numeric>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
using namespace std;

#define SZ(v)                   (int)v.size()
#define FOR(i,a,b)				for(int i=(a);i<(b);++i)
#define rev(i,a,b)				for(int i=(b);i>=(a);--i)
#define sz(v)                   (int)v.size()
#define all(v)					v.begin(), v.end()
#define rall(v)					v.rbegin(), v.rend()
#define pb						push_back
#define mp						make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
const int OO = 1 << 28;

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
#define Nd 0
#define Ed 1
#define Sd 2
#define Wd 3

char vow[] = {'a', 'e', 'i', 'o', 'u'};

int cons[1000005];
vector<int> v;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
		freopen("out.out", "wt", stdout);
#endif
	int t;
	cin >> t;
	FOR(cs,1,t+1){
		string s,str;
		v.clear();
		ll n, res = 0,cnt;
		cin >> s >> n;
		cons[SZ(s)]=0;
		rev(i,0,SZ(s)-1){
			if(find(vow,vow+5,s[i])!=vow+5)
				cons[i]=0;
			else{
				cons[i]=cons[i+1]+1;
				if(cons[i] >=n)
					v.pb(i);
			}
		}
		sort(all(v));
//		FOR(i,0,SZ(v))
//			cout << v[i]<< " ";
//		cout << endl;
		FOR(i,0,SZ(s)){
			int e = lower_bound(all(v),i)-v.begin();
			if(e>=SZ(v))
				continue;
			res += SZ(s)-(v[e]+n-1);
		}
		cout << "Case #" << cs << ": " << res << "\n";
	}
	return 0;
}




