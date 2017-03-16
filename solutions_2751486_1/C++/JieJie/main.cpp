#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>

#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SIZE(v) ((int)(v).size())
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
typedef long long ll;
using namespace std;

string s;
ll n;
set<char> setv;

void solve2(){
	cin>>s;
	cin>>n;
	ll sum=0;
	FOR(i,0,s.length()){
	
	}
	ll i=0,curlen=0;
	vector<ll> v,vv;
	while (true){
		if (i>=s.length())	break;
		if (setv.find(s[i]) == setv.end()){
			curlen=1;
			i++;
			while (i<s.length() && (setv.find(s[i]) == setv.end())){
				i++;
				curlen++;
			}
			if (curlen>=n){
				v.push_back(i-1);
				vv.push_back(curlen);
			}
		}
		else{
			i++;
		}
	}
	ll res=0,len=s.length();
	ll prev=0;
	FOR(ii,0,v.size()){
		ll q=(v[ii]-(n-1)+1)-prev;
		prev=v[ii]-(n-1)+1;
		res+=(len-v[ii])*q;
		ll num=vv[ii]-n;
		res+=num*(2*q-num-1)/2;
	}
	cout<<res<<endl;
	
}

void solve(){
	cin>>s;
	cin>>n;
	int sum=0;
	FOR(i,0,s.length())
		FOR(j,i+n-1,s.length()){
			if (j>=s.length())	break;
			bool ok=false;
			int maxlen=0;
			FOE(k,i,j){
				if (setv.find(s[k]) != setv.end()){
					maxlen=0;
				}
				else{
					maxlen++;
					if (maxlen>=n){
						ok=true;
						break;
					}
				}
			}
			if (ok)	sum++;
		}

	cout<<sum<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("A-large.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	setv.insert('a');
	setv.insert('e');
	setv.insert('i');
	setv.insert('o');
	setv.insert('u');
	int t;
	cin>>t;
	FOR(i,0,t){
		cout<<"Case #"<<i+1<<": ";
		solve2();
	}
	return 0;
}
