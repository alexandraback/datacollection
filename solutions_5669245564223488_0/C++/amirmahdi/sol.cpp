#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

const int maxn = 110;

int p[maxn];
string a[maxn];
int n;
bool mark[maxn];

bool valid(string s){
	memset(mark, 0, sizeof(mark));
	rep(i,s.size()){
		if(mark[s[i]-'a'] && s[i-1] != s[i])
			return false;
		mark[s[i]-'a'] = 1;
	}
	return true;
}

bool validate(){
	rep(i,n)
		if(!valid(a[i]))
			return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" << g+1 << ": ";
		cin >> n;
		rep(i,n)
			cin >> a[i];
		if(!validate()){
			cout << 0 << endl;
			continue;
		}
		rep(i,n)
			p[i] = i;
		int ans = 0;
		do{
			string s = "";
			rep(i,n)
				s+= a[p[i]];
			if(valid(s))
				ans++;
		}while(next_permutation(p,p+n));
		cout << ans << endl;
	}
	return 0;
}
