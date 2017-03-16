#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REV(i,a,b) for(long long i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo 2e9
#define MAX 1001
#define sz(v) (long long)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))

typedef long long ll;
typedef vector<long long> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<long long, long long> pi;
typedef vector<pi> vpi;
long long N,T,arr[105],A;
long long dp[105];

pair<long long,long long> diff(long long x,long long y)
{
	long long num = 0;
	while(x <= y)
	{
		x += (x - 1);
		if(num > N)
			return make_pair(1LL,(1LL<<23));
		num++;
	}
	return make_pair(x + y,num);
}

long long sol(long long ind,long long mass)
{
	if(ind == N)
		return 0;
	if(dp[ind] != -1)
		return dp[ind];
	pair<long long,long long> p = diff(mass,arr[ind]);
	long long ans = min(N - ind,sol(ind + 1,p.first) + p.second);
	return dp[ind] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
		freopen("o.txt", "wt", stdout);
#endif
	int TEST = 1;
	cin >> T;
	while (T--)
	{
		memset(dp,-1,sizeof dp);
		cin >> A >> N;
		for(long long i = 0 ; i < N; ++i)
			cin >> arr[i];
		sort(arr,arr+N);
		cout << "Case #"<<TEST++<<": ";
		cout << sol(0,A) << endl;
	}

	return 0;
}
