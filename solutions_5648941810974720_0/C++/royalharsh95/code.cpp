#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
 
using namespace std;

#define MAX 1000008
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define pb push_back
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define itr(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> lli;
typedef pair<int,pii> i3;
 
 


 bool solve(map<char, int> m, string a) {
	for(int i=0;i<a.size();i++) {
		if(m[a[i]]==0)
		return false;
	}
	return true;
}
 
int main() {
    read; write;
    int t;
    gi(t);
    for(int tt = 1; tt <= t; tt++) {
        string a;
        cin >> a;
        map <char, int> m;
        for(int i=0;i<26;i++) {
            m['A'+i]=0;
        }
        int sz = (int) a.size();
        for(int i=0;i<sz;i++) {
            m[a[i]]++;
        }
        map <int, string> s;
        s[0] = "ZERO";
        s[1] = "ONE";
        s[2] = "TWO";
        s[3] = "THREE";
        s[4] = "FOUR";
        s[5] = "FIVE";
        s[6] = "SIX";
        s[7] = "SEVEN";
        s[8] = "EIGHT";
        s[9] = "NINE";
        vector <int> nums;
        while(solve(m, s[0])) {
        	nums.pb(0);
        	string as = s[0];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[6])) {
        	nums.pb(6);
        	string as = s[6];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[7])) {
        	nums.pb(7);
        	string as = s[7];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[5])) {
        	nums.pb(5);
        	string as = s[5];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[8])) {
        	nums.pb(8);
        	string as = s[8];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[2])) {
        	nums.pb(2);
        	string as = s[2];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[3])) {
        	nums.pb(3);
        	string as = s[3];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[4])) {
        	nums.pb(4);
        	string as = s[4];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[9])) {
        	nums.pb(9);
        	string as = s[9];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        while(solve(m, s[1])) {
        	nums.pb(1);
        	string as = s[1];
			for(int i=0;i<as.size();i++) {
				m[as[i]]--;
			}
        }
        sort(nums.begin(), nums.end());
        printf("Case #%d: ", tt);
        for(int i=0;i<nums.size();i++) {
        	printf("%d", nums[i]);
        }
        printf("\n");
    }
	return 0;
}