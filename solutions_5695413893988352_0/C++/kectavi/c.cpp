#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> P2;
typedef pair<ll, ll> P2l;

#define INF 1000000

int main()
{
	int debug = 0;
	if(debug){
		//freopen("out_1.txt", "r", stdin);
		//srand((int)time(NULL));
		return 0;
	}
	
	freopen("B-small-attempt1.in", "r", stdin);//B-small-attempt0.in
	freopen("out-B.txt", "w", stdout);
	ll infz=1000000000000000000;

	int T; cin>>T;
	forn(i,T) {
		string s1,s2; cin>>s1>>s2;
		int N = s1.size();
		
		queue<ll> c1,c2,ct;
		c1.push(0);
		ct.push(0);
		forn(j,N){
			if(s1[j]=='?') {
				while(c1.size()) {ll t=c1.front();c1.pop(); forn(z,10) c2.push(t*10+z);}
				c1=c2; while(c2.size()) c2.pop();
			}
			else {
				while(c1.size()) {ll t=c1.front();c1.pop(); c2.push(t*10+(s1[j]-'0'));}
				c1=c2; while(c2.size()) c2.pop();
			}
			if(s2[j]=='?') {
				while(ct.size()) {ll t=ct.front();ct.pop(); forn(z,10) c2.push(t*10+z);}
				ct=c2; while(c2.size()) c2.pop();
			}
			else {
				while(ct.size()) {ll t=ct.front();ct.pop(); c2.push(t*10+(s2[j]-'0'));}
				ct=c2; while(c2.size()) c2.pop();
			}
		}

		vector<ll> pp1,pp2;
		while(c1.size()) {pp1.push_back(c1.front()); c1.pop();}
		while(ct.size()) {pp2.push_back(ct.front()); ct.pop();}

		ll val=infz, a1, a2;
		forn(j,pp1.size()) {forn(z, pp2.size()) 
			if(abs(pp1[j]-pp2[z])<val) {val=abs(pp1[j]-pp2[z]); a1=pp1[j]; a2=pp2[z];}
			else if(abs(pp1[j]-pp2[z])==val) {
				if(pp1[j]<a1) {a1=pp1[j]; a2=pp2[z];}
				else if(pp1[j]==a1 && pp2[z]<a2) {a1=pp1[j]; a2=pp2[z];}
			}
		}

		stack<int> si;
		cout<<"Case #"<<i+1<<": ";
		forn(i,N) {si.push(a1%10); a1/=10;}
		while(si.size()) {cout<<si.top();si.pop();}
		cout<<" ";
		forn(i,N) {si.push(a2%10); a2/=10;}
		while(si.size()) {cout<<si.top();si.pop();}
		cout<<endl;
	}

	return 0;
}


