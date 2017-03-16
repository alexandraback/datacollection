//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

int N;
vvi G, rG;
int ans[111111];

int count(int n) {
	int &ret = ans[n];

	if(ret > -1)
		return ret;

	ret = 0;

	for(auto &x: rG[n])
		ret += count(x);

	return ret;
}

int main()
{
	int T;
	read(T);

	forab(test, 1, T) {
		read(N);
		CL(ans, -1);
		G.clear();
		rG.clear();
		G.resize(N+1);
		rG.resize(N+1);

		forab(a, 1, N) {
			int m;
			read(m);

			while(m--) {
				int b;
				read(b);
				G[b].pb(a);
				rG[a].pb(b);
			}
		}

		bool flag = false;
/*
		cout << "Graph: \n";
		forab(i, 1, N) {
			cout << i << ": ";
			for(auto &x: G[i])
				cout << x << " ";
			cout << endl;
		}
		cout << endl << "Reverse Graph: "<< endl;
		forab(i, 1, N) {
			cout << i << ": ";
			for(auto &x: rG[i])
				cout << x << " ";
			cout << endl;
		}
		cout << endl;
*/
		vi in0, out0;

		forab(i, 1, N) {
			if(G[i].empty())
				out0.pb(i);
			if(rG[i].empty())
				in0.pb(i);
		}

		for(auto & x: in0) {
			if (flag)
				break;
			for(auto &y: out0) {
				if(flag)
					break;
				CL(ans, -1);
				ans[x] = 1;
				if(count(y) > 1)
					flag = true;
				ans[x] = 0;
			}
		}

		forab(i, 1, N)	if(G[i].empty()) {
			if(count(i) > 1) {
				flag = true;
				break;
			}
		}

		Pf("Case #%d: %s\n", test, (flag ? "Yes": "No"));
////		cout << endl;
	}
	
	return 0;
}

