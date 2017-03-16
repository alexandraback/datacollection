#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

unsigned long long r,q,c,t,ans,l,s;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> s >> q;
		l=0;
		r=1e18;
		while (l<r){
			c=(l+r+1)/2;
			double p=c+(s+s+(s+(c-1)*2.)*2.)*1.*c/2;
			t=c+(s+s+(s+(c-1)*2)*2)*c/2;
			if (p<3e18&&t<=q)l=c;else r=c-1;
		}
		ans=l;
		cout << "Case #" << E << ": " << ans << endl;
	}
	return 0;
}


