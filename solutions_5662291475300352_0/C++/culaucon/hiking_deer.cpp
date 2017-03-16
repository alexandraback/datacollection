#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

vector<pair<int, int> > v;
int main() {
	freopen("hiking_deer.in","r",stdin);
	freopen("hiking_deer.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int n;
		cin>>n;
		v.clear();
		for (int i=0;i<n;i++) {
			int ang, num, f;
			cin>>ang>>num>>f;
			for (int j=0;j<num;j++) v.push_back(make_pair(ang,f+j));
		}
		cout<<"Case #"<<nt++<<": ";
		if (v.size()<2) cout<<0<<endl;
		else {
			sort(v.begin(),v.end());
			if (v[0].first==v[1].first) swap(v[0], v[1]);
			double t=v[0].second/360.*(360-v[0].first);
			double t2=v[1].second/360.*(360-v[1].first);
			double eps=1e-9;
			double f=max(t,t2);
			if (t+v[0].second>f+eps && t2+v[1].second>f+eps) cout<<0<<endl;
			else {
				if (t+2*v[0].second>t2+eps || t2+2*v[1].second>t+eps) cout<<1<<endl;
				else cout<<2<<endl;
			} 
		}
	}
}
