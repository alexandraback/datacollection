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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
		freopen("out.out", "wt", stdout);
#endif
	int t;
	cin >> t;
	FOR(cs,1,t+1){
		string s,str;
		int n, res = 0,cnt;
		cin >> s >> n;
		FOR(i,0,SZ(s)){
			FOR(j,i,SZ(s)){
				str = s.substr(i,j-i+1);
				cnt = 0;
				FOR(k,0,SZ(str)){
					if(find(vow,vow+5,str[k])!=vow+5){
						cnt = 0;
						continue;
					}
					cnt++;
					if(cnt == n){
						res++;
//						cout << str << endl;
						break;
					}
				}
			}
		}
		cout << "Case #" << cs << ": " << res << "\n";
	}
	return 0;
}




