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

vector<int> mq1,mq2,mq3;

int chk(int j, int p, int s, int k){
	vector<int> vs(s), jvs(j*s), pvs(p*s);
	forn(z1,s) vs[z1]=0;
	forn(z1,j*s) jvs[z1]=0;
	forn(z1,p*s) pvs[z1]=0;
	int st=0, ans=0;
	forn(z1, j) forn(z2, p){
		int cm=st;
		forn(z3,k) {
			if(vs[st]<k && jvs[z1*s+st]<k && pvs[z2*s+st]<k) {
				vs[st]++; mq1.push_back(z1); mq2.push_back(z2); mq3.push_back(st); ans++;
				jvs[z1*s+st]++;
				pvs[z2*s+st]++;
			}
			if(st==s-1) st=0; else st++;
			if(st==cm) break;
		}
	}

	return ans;
}

int main()
{	
	freopen("C-small-attempt1.in", "r", stdin);//test.txt
	freopen("out_3.txt", "w", stdout);
	
	int T; cin>>T;
	forn(i,T) {
		int j,p,s,k; cin>>j>>p>>s>>k;
		int cl[6][3]={j,p,s,j,s,p,p,j,s,p,s,j,s,p,j,s,j,p};
		int ans[6], maxv=-1, kj;
		vector<int> q1[6],q2[6],q3[6];
		forn(z, 6){
			mq1.clear();mq2.clear();mq3.clear();
			int ans1 = chk(cl[z][0],cl[z][1],cl[z][2],k);
			q1[z]=mq1;q2[z]=mq2;q3[z]=mq3;
			if(ans1>maxv) {maxv=ans1; kj=z;}
		}

		cout<<"Case #"<<i+1<<": "<<maxv<<endl;
		forn(z, maxv) {
			cout<<q1[kj][z]+1<<" "<<q2[kj][z]+1<<" "<<q3[kj][z]+1<<endl;
		}

	}

	return 0;
}
