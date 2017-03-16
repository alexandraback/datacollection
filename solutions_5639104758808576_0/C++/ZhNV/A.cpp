#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int M = 1e5 + 10;
const ld Q = 1e9 + 15.;
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tq = 1; tq <= t; tq++){
		int n;
		char s[2000];
		int a[2000];
		scanf("%d%s", &n, s);
		n++;
		for (int i = 0; i < n; i++){
			a[i] = s[i] - '0';
		}
		
		int pl;
		for (pl = 0;;pl++){
			a[0] += pl;
			int cou = a[0];
			bool ok = true;
			for (int i = 1; i < n; i++){
				if (cou < i){
					ok = false;
					break;
				}
				cou += a[i];
			}
			if (ok)
				break;
			else
				a[0] -= pl;
		}
		printf("Case #%d: %d\n", tq, pl);
		cerr << "test " << tq << " done\n";
	}
	return 0;       
}                                              	