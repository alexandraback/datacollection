#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

map<pair<pair<int,int>,int>,long long> dp;
int a,b,k;

long long count(long long maxa, long long maxb, long long maxk) {
	if (dp.find(make_pair(make_pair(maxa,maxb),maxk))!=dp.end()) {
		return dp[make_pair(make_pair(maxa,maxb),maxk)];
	}
	if (maxa<10&&maxb<10) {
		int cnt=0;
		for (int i=0;i<=maxa;i++) {
			for (int j=0;j<=maxb;j++) {
				if ((i&j) <= maxk)
					cnt++;
			}
		}
		return dp[make_pair(make_pair(maxa,maxb),maxk)] = cnt;
	}
	if (maxk>=min(maxa,maxb)) {
		return dp[make_pair(make_pair(maxa,maxb),maxk)] = (maxa + 1) * (maxb + 1);
	}
	int bt=0;
	for (;;bt++) {
		long long st=(1<<bt);
		if (st>maxa&&st>maxb)
			break;
	}
	long long st=(1<<(bt-1));
	int abit=((maxa&st) ? 1 : 0);
	int bbit=((maxb&st) ? 1 : 0);
	int kbit=((maxk&st) ? 1 : 0);
	long long res=0;
	if (abit==1&&bbit==1) {
		if (kbit==1) {
			res+=count(maxa-st,maxb-st,maxk-st);
			res+=count(st-1,maxb-st,st-1);
			res+=count(maxa-st,st-1,st-1);
			res+=count(st-1,st-1,st-1);
		} else {
			res+=count(st-1,maxb-st,maxk);
			res+=count(maxa-st,st-1,maxk);
			res+=count(st-1,st-1,maxk);
		}
	}
	else if (abit==1&&bbit==0) {
		if (kbit==1) {
			res+=count(maxa-st,maxb,st-1);
			res+=count(st-1,maxb,st-1);
		} else {
			res+=count(maxa-st,maxb,maxk);
			res+=count(st-1,maxb,maxk);
		}
	}
	else if (abit==0&&bbit==1) {
		if (kbit==1) {
			res+=count(maxa,maxb-st,st-1);
			res+=count(maxa,st-1,st-1);
		} else {
			res+=count(maxa,maxb-st,maxk);
			res+=count(maxa,st-1,maxk);
		}
	}
	return dp[make_pair(make_pair(maxa,maxb),maxk)] = res;
}

void solve(int t) {
	dp.clear();
	cin>>a>>b>>k;
	a--,b--,k--;
	printf("Case #%d: ",t);
	cout << count(a,b,k) << endl;
}

int main() {

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		solve(i+1);
	}
	return 0;
}