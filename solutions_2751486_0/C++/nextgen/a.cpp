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
		rep(a,s.sz) {
			for(int b=a; b<s.sz; b++) {
				int r=0;
				for (int i=a; i<=b; i++) {
					if (is_cons(s[i])) r++;
					else r=0;
					if (r>=n) {
						ans++;
						break;
					}
				}
			}
		}
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}