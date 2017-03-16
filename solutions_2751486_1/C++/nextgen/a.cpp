#pragma comment(linker, "/STACK:36777216")
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <ctime>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define rep(i,n) for (int i=0; i<n; i++)
#define ll long long

using namespace std;

const int INF=~(1<<31);
const double EPS=1;
const double PI=3.141592653589793;

vint v;

bool is_cons(char a) {
	if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return 0;
	return 1;
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	rep(t,T) {
		int n;
		string s;
		cin>>s>>n;
		ll ans=0;
		ll a=0,b=0,la=0;
		while (1) {
			while (a<s.sz && (!is_cons(s[a]))) {
				a++;
			}
			if (a==s.sz) break;
			b=max(b,a);
			bool br=0;
			while(b<s.sz && b-a+1<n) {
				if (!is_cons(s[b])) {
					a=b+1;br=1;break;
				}
				b++;
			}
			if (!is_cons(s[b]) && b-a+1==n) {
				a=b+1;br=1;
			}
			if (br) continue;
			ans+=(a+1-la)*(s.sz-b);
			la=a+1;
			a++;
		}
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}