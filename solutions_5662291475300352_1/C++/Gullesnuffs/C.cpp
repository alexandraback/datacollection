#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

struct Hiker{
	int pos;
	double speed;
};

vector<Hiker> hikers;

void addHiker(int pos, double speed){
	Hiker h;
	h.pos=pos;
	h.speed=speed;
	hikers.push_back(h);
}

vector<double> t;

int test(double T){
	int ret=0;
	rep(i,0,hikers.size()){
		Hiker h=hikers[i];
		double newpos=h.pos+h.speed*T;
		if(newpos <= 360+1e-10)
			++ret;
		if(newpos >= 720-1e-10){
			ret += floor((newpos-(720-1e-10))/360+1);
		}
	}
	return ret;
}

void solve(){
	int n;
	hikers.clear();
	scanf("%d", &n);
	rep(i,0,n){
		int d, h, m;
		scanf("%d%d%d", &d, &h, &m);
		rep(j,0,h)
			addHiker(d, 360.0/(m+j));
	}
	for(int i=0; i < hikers.size(); ++i){
		for(int j=1; j <= 12; ++j){
			t.push_back((360.0*j-hikers[i].pos)/hikers[i].speed+1e-8);
			t.push_back((360.0*j-hikers[i].pos)/hikers[i].speed+1e-8);
		}
	}
	int ans=1000000;
	for(int i=0; i < t.size(); ++i){
		ans=min(ans, test(t[i]));
	}
	printf("%d\n", ans);
	/*if(t[1] > t[0]+1e-9){
	//if(hikers[0].pos+hikers[0].speed*dt > 360+1e-10){
		printf("0\n");
		return;
	}
	else{
		printf("1\n");
		return;
	}*/
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
