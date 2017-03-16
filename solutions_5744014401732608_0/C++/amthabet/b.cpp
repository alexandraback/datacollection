#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;

#define SMALL 1
//#define LARGE 1

bool g[100][100];

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small_2.i", "rt", stdin);
	freopen("b_small_2.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		long long b, m;
		cin>>b>>m;
		cout<<"Case #"<<tt<<": ";
		if((1LL<<(b-2)) < m) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<"POSSIBLE"<<endl;
		memset(g, 0, sizeof(g));
		for(int i=0;i+1<b;i++) {
			g[i][i+1] = 1;
		}
		int x;
		for(x=61;x>=0;x--) {
			if(!((m>>x)&1)) continue;
			break;
		}
		for(int i=0;i<=x;i++) {
			int j = b-2-i;
			for(int z=j+1;z<b;z++)
				g[j][z] = 1;
		}
		for(int i=0;i<x;i++) {
			if((1LL<<i)&m) {
				g[0][b-2-i] = 1;
			}
		}
		for(int i=0;i<b;i++) {
			for(int j=0;j<b;j++)
				cout<<g[i][j];
			cout<<endl;
		}
	}

	return 0;
}
