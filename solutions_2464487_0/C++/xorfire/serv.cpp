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
const ll maxi = 2e9;
int main()
{
   int tourist; cin>>tourist;
   FOR(i, 0, tourist)
   {
      ll r, t; cin>>r>>t;
      ll a = 2*r - 1;
      ll left = 1, right = maxi;
      while(left<right)
      {
	 ll mid = (left+right)/2;
	 if(left == mid) break;
	 ll comp = (mid*2 + a);
	 if(comp <= t / mid ) left = mid;
	 else right = mid;
      }
      printf("Case #%d: %lld\n", i+1, left);
   }
}