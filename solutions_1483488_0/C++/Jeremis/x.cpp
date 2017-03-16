#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

pair <int,int> len(int x) {
	int l = 0, ans = 1;
	while (x/=10) {
		ans*=10;
		l++;
	}
	return make_pair(l,ans);
}

void main(){

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	pair <int,int> x;
	int n;
	cin >> n;
	for (int z=0;z<n;z++) {
		int a,b,ans = 0,lead = 0;
		cin >> a >> b;
		for (int i=a;i<=b;i++) {
			x = len(i);
			int prev = i , next;
			set <int> was;
			for (int j=0;j<x.first;j++) {
				int oldest = prev/x.second;
				next = (prev%x.second)*10 + oldest;
				if ( i<next && next<=b && was.find(next)==was.end()) {
					++ans;
					was.insert(next);
				} else 
				if (next/x.second == 0 && next<i && next>=a && was.find(next)==was.end()) {
					++lead;
					was.insert(next);
				}
				prev = next;
			}
		}
		cout << "Case #" << z+1 << ": " << ans+lead << endl;
	}
}