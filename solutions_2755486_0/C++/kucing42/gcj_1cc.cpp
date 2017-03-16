#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define NOL 1000
int t,n;
vector<pair<int,pair<int,pair<int,int> > > > kya;
int d,m,w,e,s,dd,dp,ds;
int h[100000];
bool sukses[1005];
int main(){
	scanf("%d",&t);
	for (int tc = 1; tc <=t; ++tc){
		scanf("%d",&n);
		kya.clear();
		memset(sukses,0,sizeof(sukses));
		memset(h,0,sizeof(h));
		for (int i = 0; i <n; ++i){
			scanf("%d%d%d%d%d%d%d%d",&d,&m,&w,&e,&s,&dd,&dp,&ds);
			for (int j = 0; j <m; ++j){
				kya.pb(mp(d,mp(s,mp(w,e))));
				d+=dd; s+=ds; w+=dp; e+=dp;
			}
		}
		sort(kya.begin(),kya.end());
		int l = 0;
		int ans = 0;
		for (int i = 0; i <kya.size(); ++i){
			
			vector<pair<int,int> > lawan;
			for (int j = 0; j < i; ++j){
				if (kya[i].fi == kya[j].fi)
					break;
				if (kya[j].se.fi < kya[i].se.fi) continue;
				if (!sukses[j]) continue;
				if (kya[j].se.se.se>=kya[i].se.se.fi && kya[j].se.se.fi <=kya[i].se.se.se)
					lawan.pb(mp(max(kya[i].se.se.fi,kya[j].se.se.fi),min(kya[i].se.se.se,kya[j].se.se.se)));
			}
			if (lawan.size() < 1) {sukses[i] = 1;++ans;continue;}
			sort(lawan.begin(),lawan.end());
			if (lawan[0].fi > kya[i].se.se.fi){sukses[i] = 1; ++ans;continue;}
			bool mati = 1;
			int rm = lawan[0].se;
			for (int j = 1; j < lawan.size(); ++j){
				if (lawan[j].fi > rm) {mati = 0;break;}
				rm = max(rm,lawan[j].se);
			}
			if (rm <kya[i].se.se.se) mati = 0;
			if (!mati ) sukses[i] = 1;
			if (!mati) ans++;
			//cout << i <<" "<< kya[i].fi <<" "<< kya[i].se.fi <<"    "<< kya[i].se.se.fi <<" "<< kya[i].se.se.se <<"  ~  "<< mati <<" "<< lawan.size() << "  "<< ans << endl;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}