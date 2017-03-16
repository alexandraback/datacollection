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
	if(hikers.size() == 1 || hikers[0].speed == hikers[1].speed){
		printf("0\n");
		return;
	}
	if(hikers[0].speed > hikers[1].speed)
		swap(hikers[0], hikers[1]);
	/*double dPos=hikers[0].pos-hikers[1].pos;
	double dSpeed=hikers[1].speed-hikers[0].speed;
	double dt=dPos/dSpeed;
	while(hikers[0].pos*dt+hikers[1].pos <= 360){
		dPos += 360;
		dt=dPos/dSpeed;
	}*/
	double t[2];
	for(int i=0; i < 2; ++i){
		t[i]=(360.0*(i+1)-hikers[i].pos)/hikers[i].speed;
	}
	if(t[1] > t[0]+1e-9){
	//if(hikers[0].pos+hikers[0].speed*dt > 360+1e-10){
		printf("0\n");
		return;
	}
	else{
		printf("1\n");
		return;
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
