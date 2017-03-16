#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;

class Event {
	public:
		int u, d;
		int a, b, type;
		//type0: split
		//type1: join
		//type2: race
		Event(int _u=0, int _d=0, int _a=0, int _b=0, int _type=0) {
			u=_u; d=_d; a=_a; b=_b; type=_type;
		}
		bool operator < (const Event &e) const {
			if(u*1LL*e.d != d*1LL*e.u)
				return u*1LL*e.d < d*1LL*e.u;
			if(type==0) return e.type==1 || e.type==2;
			if(type==2) return e.type==1;
			return false;
			//return type < e.type;
		}
};
int pos[55], S[55], P[55];

class Group{
	public:
		//orientation: head car is at L(0) or R(1)
		int who[55], m, orientation, changable;
		Group() { m=0; orientation=0; changable=0; }
		void add(int x) {
		//	printf("grup add %d\n", x);
			who[m++] = x;
		}
		bool add(int x, int ori) {
			if(m==0) orientation = ori;
			who[m++] = x;
			return true;
		}
} g[1005];
int gn = 0;
int inGroup[55];
bool cmpByPos(int x, int y) {
	if(P[x] != P[y]) return P[x] > P[y];
	return S[x] > S[y];
}
bool strictlyTouch(int x, int y) {
	return (abs(P[x]-P[y]) < 5);
}
void build_start_state() {
	gn = 0;
	g[gn]=Group();
	vector<int> srt;
	for(int i=0;i<n;i++) srt.push_back(i);
	sort(srt.begin(), srt.end(), cmpByPos);
	for(int ii=0;ii<n;ii++) {
		int i = srt[ii];
		if(ii>0 && strictlyTouch(i, srt[ii-1])) {
			;
		} else if(g[gn].m > 0) {
			if(g[gn].m == 1) g[gn].changable = gn;
			else g[gn].changable = -1;
			gn++;
			g[gn]= Group();
		}
		g[gn].add(i, pos[i]);
	}
	if(g[gn].m == 1) g[gn].changable = gn;
	else g[gn].changable = -1;
	++gn;
}
void make_in_group() {
	//printf("make gn=%d\n", gn);
	/*for(int i=0;i<gn;i++) {
		printf("Group %d[ori=%d, cha=%d]: ", i, g[i].orientation, g[i].changable);
		for(int j=0;j<g[i].m;j++)
			printf("%d ", g[i].who[j]);
		puts("");
	}*/
	
	for(int i=0;i<gn;i++)
		for(int j=0;j<g[i].m;j++)
			inGroup[g[i].who[j]] = i;
}

bool handle_event(Event &e) {
//	puts("");
//	printf(">> Event %d %d type=%d time=%f\n", e.a, e.b, e.type, (double)e.u/e.d);
	make_in_group();	
/*	for(int i=0;i<n;i++) {
		printf("inGroup[%d]=%d\n", i, inGroup[i]);
	}*/
	
	if(e.type == 0) { //split
		int a = e.a, b = e.b;
		if(inGroup[a] != inGroup[b]) return true; //stupid
		int grp = inGroup[a];
		for(int j=0;j<g[grp].m;j++) {
			if(g[grp].who[j] == a) {
				if(g[grp].who[j+1] != b) {
					puts("QQXXX"); //stupid?
				}
				for(int gg = gn-1; gg > grp; gg--) {
					g[gg+1] = g[gg];
					if(g[gg+1].changable > grp) g[gg+1].changable++;
				}
				++gn;
				g[grp+1] = Group();
				
				for(int gj = j+1; gj < g[grp].m; gj++) {
					g[grp+1].add(g[grp].who[gj]);
				}
				g[grp].m = j+1;
				g[grp+1].changable = g[grp].changable;
				g[grp+1].orientation = g[grp].orientation ^ ((j+1)%2);

				if(g[grp+1].m <= 1) g[grp+1].changable = grp+1;
				if(g[grp].m <= 1) g[grp].changable = grp;
				return true;
			}
		}
	} else if(e.type == 1) { //join
		int a = e.a, b = e.b;
		swap(a, b);
		//printf("Gb=%d, Ga=%d\n", inGroup[b], inGroup[a]);
		if(inGroup[b] != inGroup[a]+1) return false; //something broken
		int grp = inGroup[a];
		if(g[grp].changable == -1) {
			if(g[grp+1].changable == -1) {
				if(g[grp].orientation ^ g[grp+1].orientation ^ (g[grp].m%2)) return false;
			} else {
				if(g[grp+1].changable != grp+1 && g[grp+1].changable != g[grp].changable)
				{ printf("QQQQ changable = %d %d\n", g[grp].changable, g[grp+1].changable);	} //...
				
				int odd = g[grp].orientation ^ (g[grp].m%2);
				for(int GP=grp+1;GP<gn && g[GP].changable == grp+1; GP++) {
					g[GP].changable = -1;
					g[GP].orientation = odd;
					odd ^= (g[GP].m%2);
				}
			}
		} else {
			if(g[grp+1].changable == -1) {
				int odd = g[grp+1].orientation;
				for(int GP=grp; GP >= g[grp].changable; GP--) {
					odd ^= (g[GP].m%2);
					g[GP].changable = -1;
					g[GP].orientation = odd;
				}
			} else if(g[grp].changable != g[grp+1].changable) {
				if(g[grp+1].changable != grp+1) { puts("QQ2"); } //...
				int odd = g[grp].orientation ^ (g[grp].m%2);
				for(int GP=grp+1;GP<gn && g[GP].changable == grp+1; GP++) {
					g[GP].changable = g[grp].changable;
					g[GP].orientation = odd;
					odd ^= (g[GP].m%2);
				}
			} else if(g[grp].changable == g[grp+1].changable) {
				if(g[grp].orientation ^ (g[grp].m%2) ^ g[grp+1].orientation) return false;
			}
		}
		//printf("g[grp+1].siz=%d\n", g[grp+1].m);
		for(int i=0;i<g[grp+1].m;i++)
			g[grp].add(g[grp+1].who[i]);
		for(int GP=grp+2;GP<gn;GP++) {
			g[GP-1] = g[GP];
			if(g[GP-1].changable >= grp+1) --g[GP-1].changable;
		}
		--gn;
		return true;
	} else if(e.type == 2) { //race
		int a = e.a, b = e.b;
		if(inGroup[a] != inGroup[b]) return true; //stupid
		int grp = inGroup[a];
		for(int j=0;j<g[grp].m;j++) {
			if(g[grp].who[j] == b) {
				if(g[grp].who[j+1] != a) {
					puts("QQ"); //stupid?
				}
				swap(g[grp].who[j], g[grp].who[j+1]);
				g[grp].orientation ^= 1;
				return j==0;
			}
		}
	} else {
		puts("QQWW");
	}
	return true;
}

void solve() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		char x[10];
		scanf("%s%d%d", x, &S[i], &P[i]);
		if(x[0]=='L') pos[i] = 0;
		else pos[i] = 1;
	}
	vector<Event> e;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			if(P[i]+5 <= P[j] && S[i] > S[j]) {
				//join
				int tu = P[j]-P[i]-5, td = S[i]-S[j];
				e.push_back(Event(tu, td, i, j, 1));
			}
			if(P[i] < P[j] && S[i] > S[j]) {
				//race
				int tu = P[j]-P[i], td = S[i]-S[j];
				e.push_back(Event(tu, td, i, j, 2));
			}
			if(P[i]-5 < P[j] && S[i] > S[j]) {
				//split
				int tu = P[j]-P[i]+5, td = S[i]-S[j];
				e.push_back(Event(tu, td, i, j, 0));
			}
		}
	sort(e.begin(), e.end());
	int flag = 1;
	double ans = 0;
	build_start_state();
	for(int i=0;i<(int)e.size();i++) {
		if(!handle_event(e[i])) {
			flag = 0;
			ans = e[i].u / (double)e[i].d;
			break;
		}
	}
	static int cs=0;
	printf("Case #%d: ", ++cs);
	if(flag) { puts("Possible"); }
	else printf("%.9f\n", ans);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
