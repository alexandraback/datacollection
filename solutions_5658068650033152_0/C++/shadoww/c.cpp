
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <list>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <deque>
#include <climits>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define S(x) scanf("%d",&x)
#define IS(x) cin>>x
#define ISF(x) getline(cin,x)
#define pii pair<int,int>
#define ppi pair<pii, int>
#define pll pair<ll,ll>
#define ppl pair<ll,pll>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second
#define MOD 1000000007
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

map <ppi, int> m;

void pre()
{
	m[ppi(pii(3, 3), 5)] = 4;
	m[ppi(pii(3, 3), 6)] = 5;
	m[ppi(pii(3, 3), 7)] = 6;
	m[ppi(pii(3, 3), 8)] = 7;
	m[ppi(pii(3, 3), 9)] = 8;

	m[ppi(pii(3, 4), 5)] = 4;
	m[ppi(pii(3, 4), 6)] = 5;
	m[ppi(pii(3, 4), 7)] = 6;
	m[ppi(pii(3, 4), 8)] = 6;
	m[ppi(pii(3, 4), 9)] = 7;
	m[ppi(pii(3, 4), 10)] = 8;
	m[ppi(pii(3, 4), 11)] = 9;
	m[ppi(pii(3, 4), 12)] = 10;

	m[ppi(pii(3, 5), 5)] = 4;
	m[ppi(pii(3, 5), 6)] = 5;
	m[ppi(pii(3, 5), 7)] = 6;
	m[ppi(pii(3, 5), 8)] = 6;
	m[ppi(pii(3, 5), 9)] = 7;
	m[ppi(pii(3, 5), 10)] = 8;
	m[ppi(pii(3, 5), 11)] = 8;
	m[ppi(pii(3, 5), 12)] = 9;
	m[ppi(pii(3, 5), 13)] = 10;
	m[ppi(pii(3, 5), 14)] = 11;
	m[ppi(pii(3, 5), 15)] = 12;


	m[ppi(pii(3, 6), 5)] = 4;
	m[ppi(pii(3, 6), 6)] = 5;
	m[ppi(pii(3, 6), 7)] = 6;
	m[ppi(pii(3, 6), 8)] = 6;
	m[ppi(pii(3, 6), 9)] = 7;
	m[ppi(pii(3, 6), 10)] = 8;
	m[ppi(pii(3, 6), 11)] = 8;
	m[ppi(pii(3, 6), 12)] = 9;
	m[ppi(pii(3, 6), 13)] = 10;
	m[ppi(pii(3, 6), 14)] = 10;
	m[ppi(pii(3, 6), 15)] = 11;
	m[ppi(pii(3, 6), 16)] = 12;
	m[ppi(pii(3, 6), 17)] = 13;
	m[ppi(pii(3, 6), 18)] = 14;


	m[ppi(pii(4, 4), 5)] = 4;
	m[ppi(pii(4, 4), 6)] = 5;
	m[ppi(pii(4, 4), 7)] = 6;
	m[ppi(pii(4, 4), 8)] = 6;
	m[ppi(pii(4, 4), 9)] = 7;
	m[ppi(pii(4, 4), 10)] = 7;
	m[ppi(pii(4, 4), 11)] = 8;
	m[ppi(pii(4, 4), 12)] = 9;
	m[ppi(pii(4, 4), 13)] = 9;
	m[ppi(pii(4, 4), 14)] = 10;
	m[ppi(pii(4, 4), 15)] = 11;
	m[ppi(pii(4, 4), 16)] = 12;

	m[ppi(pii(4, 5), 5)] = 4;
	m[ppi(pii(4, 5), 6)] = 5;
	m[ppi(pii(4, 5), 7)] = 6;
	m[ppi(pii(4, 5), 8)] = 6;
	m[ppi(pii(4, 5), 9)] = 7;
	m[ppi(pii(4, 5), 10)] = 8;
	m[ppi(pii(4, 5), 11)] = 8;
	m[ppi(pii(4, 5), 12)] = 9;
	m[ppi(pii(4, 5), 13)] = 9;
	m[ppi(pii(4, 5), 14)] = 9;
	m[ppi(pii(4, 5), 15)] = 10;
	m[ppi(pii(4, 5), 16)] = 10;
	m[ppi(pii(4, 5), 17)] = 11;
	m[ppi(pii(4, 5), 18)] = 12;
	m[ppi(pii(4, 5), 19)] = 13;
	m[ppi(pii(4, 5), 20)] = 14;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("in2.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cs = 0;
	int t, n, mm, c;
	cin >> t;
	pre();
	while (t--) {
        cs++;
        cout << "Case #" << cs << ": ";
		cin >> n >> mm >> c;
		if (n <= 2 || mm <= 2 || c < 5) {
			cout << c << endl;
			continue;
		}

		if (n > mm) swap(n, mm);

		cout << m[ppi(pii(n, mm), c)] << endl;
	}

	return 0;
}


