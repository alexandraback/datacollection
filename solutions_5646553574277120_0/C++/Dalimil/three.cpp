#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int C, D, V;
vector<int> p;

int isSol(vector<int> ns){
	//p
	vector<int> muj = p;
	for(int i=0;i<ns.size();i++){
		int pr = ns[i];
		for(int j=V;j>=pr;j--){
			if(muj[j-pr] == 1) muj[j] = 1;
		}
	}
	int done = true;
	for(int j=0;j<muj.size();j++){
		if(muj[j] == 0) {
			done = false;
			break;
		}
	}
	return done;
}

int gen(int siz, vector<int> &use, vector<int> akt){
	if(siz == 0){
		return isSol(akt);
	}
	for(int i=0;i<use.size();i++){
		vector<int> nov = akt;
		nov.push_back(use[i]);
		int ok = gen(siz-1, use, nov);
		if(ok) return true;
	}
	return false;
}


int main(){
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d", &C, &D, &V);
		vector<int> v;

		for(int i=0;i<D;i++){
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}

		//vector<pair<int, vector<int> > > p(V+1, pair<int, vector<int> >(0));
		p = vector<int>(V+1, 0);

		p[0] = 1;
		for(int i=0;i<D;i++){
			int pr = v[i];
			for(int j=V;j>=pr;j--){
				if(p[j-pr] == 1) p[j] = 1;
			}
		}


		int done = true;
		for(int i=0;i<p.size();i++){
			if(p[i] == 0) {
				done = false;
				break;
			}
		}
		int ans;

		if(done){
			ans = 0;
		}else{
			vector<int> w;
			for(int i=1;i<=V;i++){
				int is = false;
				for(int j=0;j<v.size();j++){
					if(v[j] == i){
						is = true;
						break;
					}
				}	
				if(is) continue;

				w.push_back(i);
			}
			int siz = 1;
			while(true){
				int ok = gen(siz, w, vector<int>());
				if(ok){
					ans = siz;
					break;
				}
				siz++;
			}
		}
			
		
		printf("Case #%d: %d\n", t, ans);
	}
}
