#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int T, N;
struct Tribe {
	int d;
	int n;
	int w, e, s, delta_d, delta_s, delta_p;
};
vector<Tribe> tribes;
map<int,int> wh;

int sim(){
	int ans = 0;
	wh.clear();
	while(true){
		int ld = 700000;
		int ldi = -1;
		for(int i = 0; i < N; ++i){
			if(tribes[i].n && tribes[i].d < ld)
				ld = tribes[i].d, ldi = i;
		}
		if(ldi == -1) return ans;
		for(int i = 0; i < N; ++i) if(tribes[i].n && tribes[i].d == ld){
//			cout <<"d=" << ld <<" ,tid=" << i << ", w=" << tribes[i].w << ", e=" << tribes[i].e << " ,s=" << tribes[i].s << " ";
			bool succ = false;
			for(int k = tribes[i].w; k < tribes[i].e; k++)
				if(wh[k] < tribes[i].s) succ = true;
			if(succ) ans++;
	//	cout << ", succ=" << succ << endl;
		}
		for(int i = 0; i < N; ++i) if(tribes[i].n && tribes[i].d == ld){
			for(int k = tribes[i].w; k < tribes[i].e; k++)
				if(wh[k] < tribes[i].s) wh[k] = tribes[i].s;
		}
		for(int i = 0; i < N; ++i) if(tribes[i].n && tribes[i].d == ld){
			tribes[i].n--;
			tribes[i].d += tribes[i].delta_d;
			tribes[i].s += tribes[i].delta_s;
			tribes[i].w += tribes[i].delta_p;
			tribes[i].e += tribes[i].delta_p;
		}
	}
}
int main(){
	cin >> T;
	for(int c = 1; c <= T; c++){
		cin >> N;
		tribes.clear();
		for(int i = 0; i < N; ++i) {
			Tribe t;
			cin >> t.d >> t.n >> t.w >> t.e >> t.s >> t.delta_d >> t.delta_p >> t.delta_s;
			tribes.push_back(t);
		}
		cout << "Case #" << c << ": " << sim() << endl;
	}
	return 0;
}
