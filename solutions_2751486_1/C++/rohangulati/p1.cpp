/*
ID: rohangu1
LANG: C++
TASK: 
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <cstdio>
#include <iterator>

using namespace std;

typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef long long LL;

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORr(i,a,b) for(i=a;i>=b;i--)
#define tr(c, it) \
		for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
#define max(a,b) (a>b?(a):(b))
#define min(a,b) (a>b?(b):(a))
#define all(a) (a).begin(),(a).end()
#define mp(i,j) make_pair(i,j)
#define sz(a) a.size()
#define pb(i) push_back(i) 
#define lb(i) lower_bound(i)
#define ub(i) upper_bound(i)
#define bs(i) binary_search(i)
#define fx first
#define sx second
#define MOD 1000000007

int gcd(int x, int y)
{
    while (y > 0) {
        int z = y;
        y = x % y;
        x = z;
    }
    return x;
}

ifstream in("p1l.in",ifstream::in);
ofstream out("p1l.out",ios::out);

// cout<<"Case #"<<c<<": "<<ans<<endl;

char m[30];
char a[1000010];
int dp[1000010];
LL ans[1000010];

int main(){
	int i,j,n,c,k;
	LL ans1;
	int cases;
	in>>cases;
	m['a'-'a'] = 1;
	m['e'-'a'] = 1;
	m['i'-'a'] = 1;
	m['o'-'a'] = 1;
	m['u'-'a'] = 1;
	FOR(c,1,cases){
		in>>a+1;
		in>>n;
		int l = strlen(a+1);
		memset(dp,0,sizeof(dp));
		memset(ans,0,sizeof(ans));
		ans1 = 0;
		FOR(i,1,l){
			if(m[a[i]-'a']==0){
				dp[i] = dp[i-1]+1;
			}
		}
		FOR(i,1,l){
			if(dp[i]<n){
				ans[i]+= ans[i-1];
			}
			else{
				ans[i] += (i-n+1); 
			}
		}
		FOR(i,1,l)
			ans1 += ans[i];
		out<<"Case #"<<c<<": "<<ans1<<endl;
	}
	return 0;
}
