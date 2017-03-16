#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>

#define ll long long
#define pii pair<int, int>
#define MAX 1000000005

using namespace std;

int n, zt;
priority_queue<pii, vector<pii>, greater<pii> > q;

int tribes[1005][8]; //holy bowser please help me
int c[1005];
int sor[2000005], sl, tsl, ct;
int seg[16000005];

map<int, int> m;
vector<int> ind;

int check_min(int p, int lo, int hi, int target_lo, int target_hi) {
    //printf("%d %d %d %d %d\n", p, lo, hi, target_lo, target_hi);
    //i don't remember how to write these
    
    if (lo > target_hi || hi < target_lo) return MAX;
    if (target_lo <= lo && hi <= target_hi) return seg[p];
    
    seg[2*p] = max(seg[2*p], seg[p]);
    seg[2*p + 1] = max(seg[2*p + 1], seg[p]);
    
    return min(check_min(2*p, lo, (lo + hi)/2, target_lo, target_hi),
	       check_min(2*p + 1, (lo + hi)/2 + 1, hi, target_lo, target_hi));
}

void set_min(int p, int lo, int hi, int target_lo, int target_hi, int v) {
    //i don't remember how to write these
    
    if (lo > target_hi || hi < target_lo) return;
    
    if (target_lo <= lo && hi <= target_hi) {
	seg[p] = max(seg[p], v);
	return;
    }
    
    set_min(2*p, lo, (lo + hi)/2, target_lo, target_hi, v);
    set_min(2*p + 1, (lo + hi)/2 + 1, hi, target_lo, target_hi, v);
    
    seg[p] = max(seg[p], min(seg[2*p], seg[2*p + 1]));
}

int main() {
    scanf("%d", &zt);
    
    for (int kt=0; kt<zt; ++kt) {
	scanf("%d", &n);
	
	sl = tsl = ct = 0;
	m.clear();
	memset(c, 0, sizeof(c));
	memset(seg, 0, sizeof(seg));
	
	for (int i=0; i<n; ++i) {
	    for (int j=0; j<8; ++j) {
		scanf("%d", &tribes[i][j]);
	    }
	    
	    q.push(make_pair(tribes[i][0], i));
	    for (int j=0; j<tribes[i][1]; ++j) {
		sor[sl] = tribes[i][2] + j * tribes[i][6]; ++sl;
		sor[sl] = tribes[i][3] + j * tribes[i][6]; ++sl;
	    }
	}
	sort(sor, sor + sl);
	for (int i=0; i<sl; ++i) {
	    if (!i || sor[i] != sor[i-1]) {
		m[sor[i]] = 2*tsl;
		sor[tsl] = sor[i];
		++tsl;
	    }
	}
	
	while (q.size()) {
	    pair<int, int> p = q.top();
	    //printf("processing time %d\n", p.first);
	    ind.clear();
	    
	    while (q.size() && q.top().first == p.first) {
		int x = q.top().second;
		int owx = tribes[x][2] + c[x] * tribes[x][6], oex = tribes[x][3] + c[x] * tribes[x][6];
		int wx = m[owx], ex = m[oex];
		int s = tribes[x][4] + c[x] * tribes[x][7];
		
		//printf("min in range %d - %d: %d\n", wx, ex, check_min(1, 0, 2*(tsl-1), wx, ex));
		if (check_min(1, 0, 2*(tsl-1), wx, ex) < s) {
		    //printf("pushing %d\n", x);
		    ind.push_back(x);
		    ++ct;
		}
		//printf("%d %d %d\n", x, c[x]+1, tribes[x][1]);
		
		++c[x];
		if (c[x] < tribes[x][1]) {
		    q.push(make_pair(tribes[x][0] + tribes[x][5] * c[x], x));
		}
		
		q.pop();
	    }
	    
	    for (int i=0; i<ind.size(); ++i) {
		int x = ind[i];
		int owx = tribes[x][2] + (c[x] - 1) * tribes[x][6], oex = tribes[x][3] + (c[x] - 1) * tribes[x][6];
		int wx = m[owx], ex = m[oex];
		int s = tribes[x][4] + (c[x] - 1) * tribes[x][7];
		
		//printf("setting %d - %d to %d\n", wx, ex, s);
		set_min(1, 0, 2*(tsl-1), wx, ex, s);
	    }
	}
	
	printf("Case #%d: %d\n", kt+1, ct);
    }
}