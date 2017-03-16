#include <iostream>
#include <string>
#include <algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;
#define sz(s) (int)(s).size()
struct state {
	int d, w, e, s;
	state(int d, int w, int e, int s):d(d), w(w), e(e), s(s){}
	bool operator < (const state & c)const{
		return d < c.d;
	}
	state(){}
};
state a[2000000];
int h[2000000];
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int tests;
	cin >> tests;
	forn(test, tests) {
		int ans = 0;
		int n;
		cin >> n;
		int sza = 0;
		memset(h, 0, sizeof h);
		forn(i, n){
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
			forn(j, ni){
				a[sza++] = state(di + j * delta_di, wi + j * delta_pi + 1000, ei + j * delta_pi + 1000, si + j * delta_si); 
			}
		}
		sort(a, a + sza);
		forn(i, sza){
			int j = i;
			while(j < sza && a[i].d == a[j].d)
				j++;
			for(int k = i; k < j; k++) {
				for(int hd = a[k].w; hd < a[k].e; hd++)
					if(h[hd] < a[k].s){
						ans++;
						break;
					}
			}
			for(int k = i; k < j; k++) {
				for(int hd = a[k].w; hd < a[k].e; hd++)
					if(h[hd] < a[k].s){
						h[hd] = a[k].s;
					}
			}
			i = j - 1;
		}
		printf("Case #%d: %d\n", test+1, ans);
	}
	return 0;
}