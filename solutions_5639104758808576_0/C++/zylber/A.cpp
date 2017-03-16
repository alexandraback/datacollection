#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

int main()
{
#ifdef ACMTUYO
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int Smax;
		cin >> Smax;
		string s;
		cin >> s;
		
		int add=0, sum=0;
		forn(i, Smax+1){
			add=max(add, i-sum);
			sum+=s[i]-'0';
		}
		
		cout << "Case #" << tc+1 << ": " << add << endl;
	}
	return 0;
}
