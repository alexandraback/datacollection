#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a, all) for(typeof((all).begin()) a = (all).begin(); a != (all).end(); ++a)

#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define dforsn(a,s,n) for(int a = (n)-1; a>=(s); --a)
#define dforall(a, all) for(typeof((all).rbegin()) a = (all).rbegin(); a != (all).rend(); ++a)

#define contains(mask, bit) ((mask & (1LL<<bit)) != 0LL)

typedef long long tint;

string l; int n;

bool isvowel(char c){
	string s = "aeiou";
	return s.find(c) != -1;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	cin >> T;
	
	forn(p,T){
		cin >> l >> n;
		
		int cnt = 0;
		tint ret = 0;
		forn(i, l.size()){
			if(isvowel(l[i]))
				cnt = 0;
			else{
				cnt++;
				if(cnt < n) continue;
				else{
					ret += l.size()-i;
					int rc = cnt;
					//cout << ret << endl;
					if(cnt > n) continue;
					for(int j = i-cnt; j >= 0; --j){
						if(isvowel(l[j])) rc = 0;
						else rc++;
						
						if(rc >= n) break;
						ret += l.size()-i;
					}
				}
			}
		}
		
		printf("Case #%i: %lld\n", p+1, ret);
	}
	return 0;
}
