//#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; i++)
#define range(i,a,b) for(int i=(a),_b=(b); i<_b; i++)

typedef int nint;
typedef long long lld;
#define int lld

const int oo = 1<<28;
const lld INF = 100000000000000000;

struct rt {
	int low, high, mid;
	int minh;
	bool dirty;
	rt *lc, *rc;

	rt(int low, int high, int h) : low(low), high(high), mid((low+high)/2), minh(h), dirty(true), lc(NULL), rc(NULL) {}

	void children() {
		if(!lc) {
			lc = new rt(low,mid,minh);
			rc = new rt(mid,high,minh);
		}
	}

	void update(int start, int end, int h) {
		if(low>=end || high<=start) return;
		if(minh>=h) return;

		if(start<=low && end >= high) {
			dirty = true;
			minh = h;
		} else {
			children();
			if(dirty) lc->update(low,mid,minh), rc->update(mid,high,minh), dirty=false;
			lc->update(start,end,h);
			rc->update(start,end,h);
			minh = min(lc->minh,rc->minh);
		}

	}

	int getmin(int start, int end) {
		if(end==start) return INF;
		if(start>=high || end<=low) return INF;
		if(dirty) return minh;
		if(start<=low && end>=high) return minh;
		return min(lc->getmin(start,end), rc->getmin(start,end));
	}
};


int d[1100], n[1100], w[1100], e[1100], s[1100], dd[1100], dp[1100], ds[1100];

typedef pair<int,int> pr;
typedef pair<int,pr> upd;


ifstream cin("in.txt"); ofstream cout("out.txt");

int solve() {
	int N;
	cin>>N;
	priority_queue<pr,vector<pr>,greater<pr> > attacks;
	fo(i,N) {
		cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];
		attacks.push(pr(d[i],i));
	}

	rt *range = new rt(-oo,oo,0);
	queue<upd> update;
	int successes = 0;

	int lastday = 0;

	while(attacks.size()) {
		int tribe = attacks.top().second, day = attacks.top().first; attacks.pop();

		if(day > lastday) {
			while(update.size()) {
				//cout<<"Updating: ["<<update.front().second.first<<", "<<update.front().second.second<<")\n";
				range->update(update.front().second.first,update.front().second.second,update.front().first);
				update.pop();
			}
		}

		int iter = (day-d[tribe])/dd[tribe];
		int start = w[tribe]+iter*dp[tribe], end = e[tribe]+iter*dp[tribe];
		int strength = s[tribe]+iter*ds[tribe];

		//cout<<day<<' '<<tribe<<": ("<<start<<", "<<end<<") "<<strength<<" vs "<<range->getmin(start,end)<<'\n';

		if(iter<n[tribe]-1) attacks.push(pr(day+dd[tribe],tribe));

		if(strength > range->getmin(start,end)) {
			successes += 1;
			update.push(upd(strength,pr(start,end)));
		}

		lastday = day;
	}


	return successes;
}



nint main() {
	int T; cin>>T;
	fo(i,T) cout<<"Case #"<<(i+1)<<": "<<solve()<<'\n';
}
