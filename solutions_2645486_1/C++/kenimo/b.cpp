#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
void run(int Case)
{
	LL sum=0;
	LL E, R, N;
	cin >> E >> R >> N;
	vector<LL> vs;
	vector<P> order;
	FOR(i,0,N){
		LL v;
		cin >> v;
		vs.push_back(v);
		order.push_back(P(-v,i));
	}
	sort(order.begin(),order.end());
	set<LL> done;
	FOR(i,order.begin(),order.end()){
		LL pos=i->second;
		LL s0=sum;
		if (done.empty()){
			sum+=E*vs[pos];
		}
		else if (*done.rbegin() < pos){
			LL e=min(E,(pos-*done.rbegin())*R);
			e=max(e,0LL);
			sum+=e*vs[pos];
		}
		else
		{
			LL u=*done.upper_bound(pos);
			if (pos<*done.begin()){
				LL e=min(E,(u-pos)*R);
				e=max(e,0LL);
				sum+=e*vs[pos];
			}
			else {
				LL l=*(--done.upper_bound(pos));
				LL e=min(E,(u-pos)*R);
				e=min(e,(pos-l)*R);
				e=min(e, (u-l)*R-E);
				e=max(e,0LL);
				sum+=e*vs[pos];
			}
		}
		done.insert(pos);
		//cout << pos << ": " << sum-s0 << ", ";
	}
	cout << "Case #" << Case << ": " << sum << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		run(t);
	}
}
