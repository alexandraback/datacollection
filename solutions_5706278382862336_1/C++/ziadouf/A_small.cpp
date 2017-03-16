#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

ll gcd (ll a , ll b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}

bool IsPowerOfTwo(ll x)
{
    return (x & (x - 1)) == 0;
}

int solve (ll P , ll Q , int steps)
{
	ll GCD = gcd(P,Q);
	P /= GCD;
	Q /= GCD;
	if (steps > 40 || !IsPowerOfTwo(Q)) return -1<<30;
	
	if (2*P >= Q) return 1;
	
	return 1+solve(2*P,Q,steps+1);
}

int main ()
{
	freopen("A_small.in","r",stdin);
	freopen("A_large.out","w",stdout);
	
	int TC;
	cin >> TC;
	int CC=1;
	
	while (TC--)
	{
		ll P,Q;
		scanf("%lld/%lld",&P,&Q);
		printf("Case #%d: ",CC++);
		
		int ans =  solve(P,Q,1);
		if (ans < 0) cout << "impossible" << endl;
		else cout << ans << endl;
	}
}
