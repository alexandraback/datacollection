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
const ll prime = 1000000007;

int p[maxn];
string a[maxn];
int n;
bool mark[maxn];
ll fact[maxn];

ll fac(int n){
	if(fact[n] != -1)
		return fact[n];
	if(n == 0)
		return 1;
	fact[n] = ((ll)n*fac(n-1))%prime;
	return fact[n];
}

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

typedef pair<string, int> pis;

bool ispartial(string s){
	rep(i, s.length())
		if(s[0] != s[i])
			return true;
	return false;
}

pis* validate(vector<pis> &v, char ch){
	vector<pis> par;
	string tmp="";
	ll count = 1;
	for(pis &p :v){
		count *= p.second;
		count %= prime;
		if(ispartial(p.first))
			par.pb(p);
		else
			tmp+=p.first;
		if(par.size() > 2)
			return NULL;
	}
	string s1 = (par.size())?par[0].first:"";
	string s2 = (par.size()>1)?par[1].first:"";
	if(s2.size() > 0){
		if(s2[0] != ch)
			swap(s1,s2);
	}else if(s1.size() > 0 && s1[0] == ch)
		swap(s1, s2);
	if(!valid(s1+s2))
		return NULL;
//	cout << s1 << " " << s2 << endl;
	count *= fac((int)v.size()-par.size());
	count %= prime;
	string res = s1+tmp+s2;
	if(!valid(res))
		return NULL;
	return new pis(res, count);
}

int main() {
	memset(fact, -1, sizeof(fact));
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
		multiset<pis> h;
		rep(i,n)
			h.insert(pis(a[i], 1));
		bool ok = true;
		for(int i = 'a'; i<='z';i++){
			vector<pis> v;
			for(auto &kv : h){
				if(kv.first.find((char)i) !=std::string::npos)
					v.pb(kv);
			}
			if(v.size() <= 1)
				continue;
			rep(i, v.size())
				h.erase(v[i]);
//			cout <<"validating " << (char)i << endl;
			pis *q = validate(v, (char)i);
			if(q == NULL){
				ok = false;
				break;
			}else{
				h.insert(*q);
			}
		}
			//cout <<"hello" <<endl;
		if(!ok)
			cout << 0 << endl;
		else{
			ll ans = fac(h.size());
			for(auto &p : h){
				ans *= p.second;
				ans %= prime;
			}
			cout << ans  << endl;
		}
		/*rep(i,n)
			p[i] = i;
		int ans = 0;
		do{
			string s = "";
			rep(i,n)
				s+= a[p[i]];
			if(valid(s))
				ans++;
		}while(next_permutation(p,p+n));
		cout << ans << endl;*/
	}
	return 0;
}
