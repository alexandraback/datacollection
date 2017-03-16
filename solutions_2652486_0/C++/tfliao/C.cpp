#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXK 7
#define MAXM 5

struct Combine
{
	int n ;
	int f[6];
};

vector<vector<Combine> > comb;

void fact(int idx, int r, int st, Combine c)
{
	if ( st > MAXM ) return;
	if ( r == 1 ) {
		comb[idx].push_back(c);
		return ;
	}
	fact(idx, r, st+1, c);
	for ( int i=st;i<=MAXM;++i ) {
		if ( r%i == 0 ) {
			c.f[c.n++] = i;
			fact(idx, r/i, st, c);
			c.n--;
		}
	}
}


void pre_calc()
{
	Combine c;  c.n = 0;

	comb.resize(126);
	comb[1].push_back(c);
	for ( int i=2;i<=125;++i ) {
		c.n = 0;
		fact(i,i,2, c);
	}
}

int T, nCase = 1 ;
int R, N, M, K ;
int k[MAXK] ;

char ans[4];

Combine merge(Combine c1, Combine c2 )
{
	Combine c ; c.n = 0;
	int i = 0, j = 0;
	while ( i<c1.n && j<c2.n ) {
		if ( c1.f[i] == c2.f[j] ) {
			c.f[c.n++] = c1.f[i];
			++i, ++j ;
		} else if ( c1.f[i] < c2.f[j] ) {
			c.f[c.n++] = c1.f[i++];
		} else {
			c.f[c.n++] = c2.f[j++];
		}
	}
	while ( i<c1.n) {
		c.f[c.n++] = c1.f[i++];
	}
	while ( j<c2.n) {
		c.f[c.n++] = c2.f[j++];
	}
	if ( c.n > 3 ) c.n = -1 ;
	return c;
	
}

bool solv_r(int idx, Combine c)
{
	if ( idx == K ) {
		if ( c.n == 2 ) { c.f[2] = c.f[1]; c.f[1] = c.f[0]; c.f[0] = 2; }
		if ( c.n == 1 ) { c.f[2] = c.f[0]; c.f[1] = c.f[0] = 2; }
		if ( c.n == 0 ) { c.f[2] = c.f[1] = c.f[0] = 2; }
		sprintf	(ans, "%d%d%d", c.f[0], c.f[1], c.f[2]);
		return true;
	}
	int kk = k[idx];
	for ( int i=0;i<comb[kk].size();++i ) {
		Combine cx = comb[kk][i];
		Combine cpass = merge(cx, c) ;
		if ( cpass.n < 0 ) continue;
		if ( solv_r(idx+1, cpass) ) return true;
	}
	return false;
}


void solv()
{
	for ( int i=0;i<K;++i) cin >> k[i];
	Combine c; c.n = 0;
	if (!solv_r(0, c) ){
		ans[0] = ans[1] = ans[2] = '2'; ans[3] = 0;
	}
	cout << ans << endl;
}

int main()
{
	pre_calc();
	cin >> T;
	while ( T-- ) {
		cin >> R >> N >> M >> K ;
		cout << "Case #" << nCase ++ << ":" << endl;
		for ( int i=0;i<R;++i ) {
			solv() ;

		}
	}
	return 0;
}