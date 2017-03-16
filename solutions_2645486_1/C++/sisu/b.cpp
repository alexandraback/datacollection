#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MN = 1<<20;
P ps[MN];
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		ll E,R;
		int N;
		cin>>E>>R>>N;
		for(int i=0; i<N; ++i) {
			int x;cin>>x;
			ps[i] = P(x,i);
		}
		sort(ps,ps+N);
		ll res = 0;
		set<int> used;
		for(int i=N-1; i>=0; --i) {
			P p = ps[i];
			int n = p.second;
			ll x = p.first;
			if (used.empty()) {
				res += x * E;
				used.insert(n);
				continue;
			}
			set<int>::iterator next = used.lower_bound(n), prev=next;
			if (prev==used.begin()) {
				ll dist = *next - n;
				ll recover = R * dist;
				ll y = min(recover, E);
				res += x * y;
				used.insert(n);
			} else {
				--prev;
				if (next==used.end()) {
					ll dist = n - *prev;
					ll rec = R * dist;
					ll y = min(rec, E);
					res += x*y;
					used.insert(n);
				} else {
					ll tdist = *next - *prev;
					ll trec = tdist * R;
					if (trec <= E) continue;
					ll pd = n-*prev, ad = *next-n;
					ll rec = R*min(pd,ad);
					ll y = min(trec-E, min(rec, E));
					res += x*y;
					used.insert(n);
				}
			}
		}

		cout<<"Case #"<<a<<": "<<res<<'\n';
	}
}
