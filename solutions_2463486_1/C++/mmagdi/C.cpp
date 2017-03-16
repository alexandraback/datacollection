/*
 TASK:B
 LANG:C++
 Muhammad Magdi Muhammad
 Email: moh_magdi@acm.org
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<(int)m;i++)
#define REP(i,k,m)      for(int i=k;i<(int)m;i++)
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((int)1e9)
#define MAX 100000

typedef long long ll;

int diri[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dirj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int compare(double d1, double d2) {
	if (fabs(d1 - d2) < 1e-9)
		return 0;
	if (d1 < d2)
		return -1;
	return 1;
}
int I, J;
inline bool valid(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

using namespace std;

//#define SMALL
#define LARGE
int T;

bool isPal(ll ind) {
	stringstream ss;
	ss << ind;
	string res, t;
	ss >> res;
	t = res;
	reverse(all(t));
	return t == res;
}
ll arr[] = { 1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 14641ll, 40804ll,
		44944ll, 1002001ll, 1234321ll, 4008004ll, 100020001ll, 102030201ll,
		104060401ll, 121242121ll, 123454321ll, 125686521ll, 400080004ll,
		404090404ll, 10000200001ll, 10221412201ll, 12102420121ll, 12345654321ll,
		40000800004ll, 1000002000001ll, 1002003002001ll, 1004006004001ll,
		1020304030201ll, 1022325232201ll, 1024348434201ll, 1210024200121ll,
		1212225222121ll, 1214428244121ll, 1232346432321ll, 1234567654321ll,
		4000008000004ll, 4004009004004ll, 100000020000001ll, 100220141022001ll,
		102012040210201ll, 102234363432201ll, 121000242000121ll,
		121242363242121ll, 123212464212321ll, 123456787654321ll,
		400000080000004ll };
int main() {
	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large-1.in","rt",stdin);
	freopen("C-large-1.out","wt",stdout);
#endif

	cin >> T;
	rep(tt,T) {
		printf("Case #%d: ", tt + 1);
		ll a, b, ans = 0;
		cin >> a >> b;
		for(int i = 0 ; i < 48 ; i++){
			if(arr[i] >= a && arr[i] <= b)ans++;
		}
		cout << ans << endl;
		cerr << tt << endl;
	}
	return 0;
}
//end

