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

int e,r,n,a[222222],g;
multiset<pair<int,int> >S;
multiset<pair<int,int> >::iterator it;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> e >> r >> n;
		for (int i=0;i<n;i++)cin >> a[i];
		S.clear();
		long long ans=0;
		long long sz=0;
		for (int i=n-1;i>=0;i--){
			S.insert(mp(a[i],e));
			sz+=e;
			while (sz>e){
				pair<int,int>w=*(S.begin());
				S.erase(S.begin());
				if (w.S>sz-e){
					w.S-=sz-e;
					sz=e;
					S.insert(w);
					break;
				}else{
					sz-=w.S;
				}
			}
			if (i==0)g=e;else g=r;
			for(;;){
				if (S.empty())break;
				it=S.end();
				it--;
				pair<int,int>w=*it;
				S.erase(it);
				if (g<w.S){
					ans+=w.F*1ll*g;
					w.S-=g;
					sz-=g;
					S.insert(w);
					break;
				}else{
					ans+=w.F*1ll*w.S;
					g-=w.S;
					sz-=w.S;
				}
			}
		}
		cout << "Case #" << E << ": " << ans << endl;
	}
	return 0;
}


