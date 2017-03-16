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

int a[4][4]={{0,1,2,3}, {1,0,3,2}, {2,3,0,1}, {3,2,1,0}};
int b[4][4]={{1,1,1,1}, {1,-1,1,-1}, {1,-1,-1,1}, {1,1,-1,-1}};
map<char, int> mp;

int main() {
	freopen("dijkstra.in","r",stdin);
	freopen("dijkstra.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	mp['1']=0;
	mp['i']=1;
	mp['j']=2;
	mp['k']=3;
	while (tc--) {
		LL n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		cout<<"Case #"<<nt++<<": ";
		int v0=mp[s[0]], dir0=1;
		for (int i=1;i<n;i++) {
			dir0*=b[v0][mp[s[i]]];
			v0=a[v0][mp[s[i]]];
		}

		int v=0, dir=1;
		int mx;
		for (;(1ll<<mx)<=k;mx++);
		mx--;
		for (int i=mx;i>=0;i--) {
			if ((1ll<<i)&k) {
				dir*=b[v][v0]*dir0;
				v=a[v][v0];
			}
			if (i>0) {
				dir=b[v][v];
				v=a[v][v];
			}
		}
		
		//cout<<v<<" "<<dir<<"   "<<v0<<" "<<dir0<<" "<<mx<<endl;
		
		if (v!=0 || dir!=-1) {
			cout<<"NO"<<endl;
			continue;
		}
		
		v=0;
		dir=1;
		int x, y;
		for (int i=0;i<min(k,10ll);i++) {
			for (int j=0;j<n;j++) {
				dir*=b[v][mp[s[j]]];
				v=a[v][mp[s[j]]];
				if (v==1 && dir==1) {
					x=i;
					y=j;
					break;
				}
			}
			if (v==1 && dir==1) break;
		}
		if (v!=1 || dir!=1) {
			cout<<"NO"<<endl;
			continue;
		}
		
		v=0;
		dir=1;
		for (int j=y+1;j<n;j++) {
			dir*=b[v][mp[s[j]]];
			v=a[v][mp[s[j]]];
			if (v==2 && dir==1) break;
		}
		if (v==2 && dir==1) {
			cout<<"YES"<<endl;
			continue;
		}
		for (int i=x+1;i<min(x+11ll,k);i++) {
			for (int j=0;j<n;j++) {
				dir*=b[v][mp[s[j]]];
				v=a[v][mp[s[j]]];
				if (v==2 && dir==1) break;
			}
			if (v==2 && dir==1) break;
		}
		if (v==2 && dir==1) {
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;		
	}
}
