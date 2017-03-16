#include<iostream>
#include<algorithm>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<deque>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORC(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a-1; i>=b; --i)
#define FORDC(i, a, b) for(int i=a; i>=b; --i)
#define endl '\n'
#define pb push_back
#define size(v) (int)((v).size())
#define all(v) (v).begin(), (v).end()
#define DREP(v) sort(all(v)); v.erase(unique(all(v)), (v).end())
#define F first
#define S second
#define mp make_pair
#define VI vector<int>
#define index(a, val) (lower_bound(all(a), val)-(a).begin())
#define iter(i, c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define PII pair<int, int>
#define ll long long
#define ini(arr, val) memset(arr, val, sizeof(arr))
#define debug(a) cerr<<"DEBUG: "<<#a<<" = "<<a<<endl
#define deb debug("gauss")
int ans(int A, int a[], int n)
{
	sort(a, a+n);
	int curr = 0, rem = n, add = 0; int mini = n;
	while(curr < n)
	{
		while(curr != n and A > a[curr]) { A += a[curr]; ++curr; --rem; }
		mini = min(mini, add + rem);
		if(curr == n or A == 1) break;
		A += A-1; ++add;
	}
	return mini;
}
int main()
{
	int tourist; cin>>tourist;
	FORC(i, 1, tourist)
	{
		int A, n; cin>>A>>n; int a[n]; FOR(j, 0, n) cin>>a[j];
		printf("Case #%d: %d\n", i, ans(A, a, n));
	}
	return 0;
}