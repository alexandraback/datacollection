/*
 * b.cpp
 *
 *  Created on: May 3, 2014
 *      Author: AhmedSamir
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef _MSC_VER
#define rep(i,m) for(decltype(m) i=0;i<m;i++)
#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#else
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define repI(i,m) for(__typeof(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(__typeof(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define EPS (1e-9)
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

#define SMALL_INPUT
//#define LARGE_INPUT

int main()
{
	freopen("b.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("b-small-attempt0.in", "rt", stdin);
	freopen("b-small.txt", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("b-large.in", "rt", stdin);
	freopen("b-large.txt", "wt", stdout);
#endif
	int tc;
	scanf("%d", &tc);
	rep(T,tc)
	{

		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int cnt = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
			{
				cnt += ((i & j) < c);
			}
		printf("Case #%d: %d\n", T + 1, cnt);

#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}
