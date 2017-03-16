#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1 << 20;

struct el {
	int l , r;
	int s;
	
	el () {}
	el ( int _l , int _r , int _s ) {
		l = _l; r = _r; s = _s;
	}
};

struct tree {
	int l , r;
	int down , val , st;
};

int n;
vector < el > a[MAX];
vector < int > t;

tree f[1 << 23];

int temp[1 << 23];

void read() {
	int di , ni , wi , ei , si , ddi , dpi , dsi;
	int i;
	
	t.clear();
	for (i = 0; i < MAX; i++) a[i].clear();
	
	scanf ( "%d" , &n );
	
	while ( n -- ) {
		scanf ( "%d%d%d%d%d%d%d%d" , &di , &ni , &wi , &ei , &si , &ddi, &dpi , &dsi );
		
		while ( ni -- ) {
//			printf ( "%d   %d %d   %d\n" , di , wi , ei - 1 , si );
			a[di].push_back ( el ( wi , ei - 1 , si ) );
			
			di += ddi;
			wi += dpi;
			ei += dpi;
			si += dsi;
		}
	}
}

void init ( int l , int r , int p ) {
	f[p].l = l;
	f[p].r = r;
	f[p].down = 0;
	f[p].val = 0;
	f[p].st = 0;
	
	if ( l != r ) {
		int mid = (l + r) / 2;
		
		init ( l , mid , p * 2 );
		init ( mid + 1 , r , p * 2 + 1 );
	}
}

int ask ( int l , int r , int p ) {
	int ans = 1 << 30;for (; l <= r; l++) ans = min ( ans , temp[l+10000] );return ans;
	if ( f[p].l > r || f[p].r < l ) return 1 << 30;
	
//	printf ( " --- %d %d    %d\n" , f[p].l , f[p].r , f[p].val );
	
	if ( l <= f[p].l && f[p].r <= r ) return f[p].val;
	
	if ( f[p].down ) {
		f[p * 2].st = max ( f[p * 2].st , f[p].st );
		f[p * 2 + 1].st = max ( f[p * 2 + 1].st , f[p].st );
		f[p * 2].val = max ( f[p * 2].val , f[p].st );
		f[p * 2 + 1].val = max ( f[p * 2 + 1].val , f[p].st );
		f[p].down = 0;
		f[p * 2].down = f[p * 2 + 1].down = 1;
	}
	
	return min ( ask ( l , r , p * 2 ) , ask ( l , r , p * 2 + 1 ) );
}

void ins ( int l , int r , int s , int p ) {
	for (; l <= r; l++) temp[l+10000] = max ( temp[l+10000] , s );return ;
	
	if ( f[p].l > r || f[p].r < l ) return ;
	if ( l <= f[p].l && f[p].r <= r ) {
		if ( f[p].st < s ) {
			f[p].down = 1;
			f[p].st = s;
		}
		f[p].val = max ( f[p].val , f[p].st );
		return ;
	}
	
	if ( f[p].down ) {
		f[p * 2].st = max ( f[p * 2].st , f[p].st );
		f[p * 2 + 1].st = max ( f[p * 2 + 1].st , f[p].st );
		f[p * 2].val = max ( f[p * 2].val , f[p].st );
		f[p * 2 + 1].val = max ( f[p * 2 + 1].val , f[p].st );
		f[p].down = 0;
		f[p * 2].down = f[p * 2 + 1].down = 1;
	}
	
	ins ( l , r , s , p * 2 );
	ins ( l , r , s , p * 2 + 1 );
	
	f[p].val = min ( f[p * 2].val , f[p * 2 + 1].val );
}

void solve() {
	int i , j;
	int ans = 0;
	int pow = 1;
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < (int)a[i].size(); j++) {
			t.push_back ( a[i][j].l );
			t.push_back ( a[i][j].r );
		}
	}
	
	memset ( temp , 0 , sizeof temp );
	
	sort ( t.begin() , t.end() );
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < (int)a[i].size(); j++) {
//			a[i][j].l = lower_bound ( t.begin() , t.end() , a[i][j].l ) - t.begin() + 1;
//			a[i][j].r = lower_bound ( t.begin() , t.end() , a[i][j].r ) - t.begin() + 1;
			
//			printf ( "%d   %d %d  %d\n" , i , a[i][j].l , a[i][j].r , a[i][j].s );
		}
	}
	
	while ( pow < (int)t.size() ) pow *= 2;
	
	init ( 1 , pow , 1 );
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < (int)a[i].size(); j++) {
//			printf ( "%d %d  %d     %d\n\n" , a[i][j].l , a[i][j].r , a[i][j].s , ask ( a[i][j].l , a[i][j].r , 1 ) );
			if ( ask ( a[i][j].l , a[i][j].r , 1 ) < a[i][j].s ) {
				++ ans;
			}
		}
		
		for (j = 0; j < (int)a[i].size(); j++) {
			ins ( a[i][j].l , a[i][j].r , a[i][j].s , 1 );
		}
	}
	
	printf ( "%d\n" , ans );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
	}
	
	return 0;
}
