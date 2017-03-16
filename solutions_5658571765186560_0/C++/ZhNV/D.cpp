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
string ans[2] = {"RICHARD", "GABRIEL"};
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tq = 1; tq <= t; tq++){
		int x, r1, c1, r, c;
		scanf("%d%d%d", &x, &r1, &c1);
		r = min(r1, c1);
		c = max(r1, c1);
		int a;
		if (x == 1){
			a = 1;
		}
		if (x == 2){
			if ((r * c) % 2)
				a = 0;
			else
				a = 1;	
		}	
		if (x == 3){
			if (r == 1 || (r * c) % 3)
				a = 0;
			else
				a = 1;	
		}
		if (x == 4){
			if ((r * c) % 4 || r <= 2)
				a = 0;
			else
				a = 1;
		}
		cout << "Case #" << tq << ": " << ans[a] << endl;
		
	}
	return 0;       
}                                              	