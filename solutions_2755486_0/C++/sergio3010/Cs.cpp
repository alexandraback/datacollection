#include <bits/stdc++.h>


using namespace std;


#define fr(i,a,b) for(int i=a;i<b;++i)
#define mp make_pair
#define F first
#define S second
int t,n;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;


struct ev{
	ll d;
	ll ini, fim, st;
	ev(){}
	ev(ll D, ll INI, ll FIM, ll ST){d = D, ini = INI, fim = FIM, st = ST; }
	bool operator <(const struct ev &lhs) const{
		if(d == lhs.d){
			if(ini == lhs.ini){ 
				if(fim == lhs.fim) return st < lhs.st;
				return fim < lhs.fim;
			}
			return ini < lhs.ini;
		}
		return d < lhs.d;
	}
}e[1001000], up[1001000];
int ne,nup;

set<pii> pts;


ll w[10000];




bool worked(int ind){
	fr(i,e[ind].ini, e[ind].fim){
		if(w[i] < e[ind].st) return true;
	}
	return false;
}




void update(int ind){
	fr(i,up[ind].ini,up[ind].fim){
		w[i] = max(w[i], up[ind].st);
	}
}





int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		memset(w, 0, sizeof w);
		pts.clear();
		ne = 0;
		pts.insert(mp(-oo, 0));
		pts.insert(mp(oo, 0));
		scanf("%d",&n);
		fr(i,0,n){
			ll di, wi, ei, si, ddi, dpi, dsi;
			int ni;
			scanf("%lld %d %lld %lld %lld %lld %lld %lld",&di,&ni,&wi,&ei,&si,&ddi,&dpi,&dsi);
			fr(j,0,ni){
				e[ne++] = ev(di + ddi*j, wi + dpi*j+1000, ei+dpi*j+1000, si + dsi*j);
			}
		}
		sort(e, e+ne);
		int nwork = 0;
		fr(i,0,ne){
			int j = i;
			nup = 0;
			while(j < ne && e[j].d == e[i].d){
				if(worked(j)){ 
					nwork++;
					up[nup++] = e[j];
				}
				j++;
			}
			fr(k,0,nup){
				update(k);
			}
			i = j-1;
		}
		printf("Case #%d: %d\n",cas,nwork);
	}
	return 0;
}
