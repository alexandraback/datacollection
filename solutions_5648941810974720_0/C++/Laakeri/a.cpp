#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<string, int> ns;

set<int> in[300];
int ct[300];
int need[300];

int has(int n){
	for (auto t:ns){
		if (t.S==n){
			for (char c:t.F) need[c]++;
			int f=0;
			for (char c:t.F){
				if (ct[c]<need[c]) f=1;
			}
			for (char c:t.F) need[c]--;
			return !f;
		}
	}
	abort();
}

void solve(){
	string s;
	cin>>s;
	set<char> cs;
	for (char c:s){
		ct[c]++;
		cs.insert(c);
	}
	set<int> can;
	for (int i=0;i<=9;i++) can.insert(i);
	vector<int> v;
	while((int)can.size()>0){
		vector<int> rm;
		for (int i:can){
			if (has(i)==0) rm.push_back(i);
		}
		for (int i:rm) can.erase(i);
		for (char i:cs){
			int ff=0;
			if (ct[i]>0){
				int f=0;
				for (int a:in[i]){
					if (can.count(a)>0) f++;
				}
				if (f==1){
					for (int a:in[i]){
						if (can.count(a)>0){
							ff==1;
							for (auto t:ns){
								if (t.S==a){
									for (char cc:t.F){
										ct[cc]--;
									}
								}
							}
							v.push_back(a);
							break;
						}
					}
				}
			}
			if (ff) break;
		}
	}
	sort(v.begin(), v.end());
	for (int i=0;i<(int)v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ns["ZERO"]=0;
	ns["ONE"]=1;
	ns["TWO"]=2;
	ns["THREE"]=3;
	ns["FOUR"]=4;
	ns["FIVE"]=5;
	ns["SIX"]=6;
	ns["SEVEN"]=7;
	ns["EIGHT"]=8;
	ns["NINE"]=9;
	for (auto t:ns){
		for (char c:t.F){
			assert((int)c>0);
			in[c].insert(t.S);
		}
	}
	int tcs;
	cin>>tcs;
	for (int tc=1;tc<=tcs;tc++){
		cout<<"Case #"<<tc<<": ";
		solve();
	}
}