#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int X, R, C;
set< set< PAR > > S[10];
set< set< PAR > > S2[10];
bool F[40][40];
bool ans[10][22][22];

bool can_place( int x, int y, set< PAR > & s )
{
	for (set< PAR >::iterator it = s.begin(); it != s.end(); it++)
		if (!F[(*it).first+x][(*it).second+y])
			return false;
	return true;
}

void place( int x, int y, set< PAR > & s )
{
	for (set< PAR >::iterator it = s.begin(); it != s.end(); it++)
		F[(*it).first+x][(*it).second+y] = false;
}

void unplace( int x, int y, set< PAR > & s )
{
	for (set< PAR >::iterator it = s.begin(); it != s.end(); it++)
		F[(*it).first+x][(*it).second+y] = true;
}

bool dfs( int bx, int by )
{
	FOR(x,bx,10+R) FOR(y,(x==bx?by:11),10+C) if (F[x][y])
	{
		for (set< set< PAR > >::iterator it = S2[X].begin(); it != S2[X].end(); it++)
		{
			set< PAR > s = (*it);
			for (set< PAR >::iterator it = s.begin(); it != s.end(); it++)
			{
				int xx = x-(*it).first, yy = y-(*it).second;
				if (can_place( xx, yy, s ))
				{
					place( xx, yy, s );
					if (dfs( x, y )) return true;
					unplace( xx, yy, s );
				}
			}
		}
		return false;
	}
	return true;
}

void insert_normalized( int ind, set< PAR > ss )
{
	set< PAR > s[8];
	for (set< PAR >::iterator it = ss.begin(); it != ss.end(); it++)
	{
		int x = (*it).first, y = (*it).second;
		s[0].insert( MP( x, y ) );
		s[1].insert( MP( x, -y ) );
		s[2].insert( MP( -x, y ) );
		s[3].insert( MP( -x, -y ) );
		s[4].insert( MP( y, x ) );
		s[5].insert( MP( y, -x ) );
		s[6].insert( MP( -y, x ) );
		s[7].insert( MP( -y, -x ) );
	}
	set< PAR > s_mi;
	for (int a=0; a<8; a++)
	{
		set< PAR > sss;
		PAR t = *s[a].begin();
		for (set< PAR >::iterator it = s[a].begin(); it != s[a].end(); it++)
			sss.insert( MP( (*it).first - t.first, (*it).second - t.second ) );
		if (s_mi.empty() || sss < s_mi) s_mi = sss;
		S2[ind].insert( sss );
	}
	S[ind].insert( s_mi );
}

void init()
{
	set< PAR > s;
	s.insert( MP( 0, 0 ) );
	S[1].insert( s );
	S2[1].insert( s );

	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	FOR(a,1,5)
		for (set< set< PAR > >::iterator it = S[a].begin(); it != S[a].end(); it++)
		{
			set< PAR > ss = (*it);
			for (set< PAR >::iterator it2 = ss.begin(); it2 != ss.end(); it2++)
				FOR(b,0,3)
				{
					PAR nw = MP( (*it2).first + dx[b], (*it2).second + dy[b] );
					if (!ss.count( nw ))
					{
						set< PAR > sss = ss;
						sss.insert( nw );
						insert_normalized( a+1, sss );
					}
				}
		}

	FOR(a,1,6) cerr << SZ(S[a]) << " " << SZ(S2[a]) << "\n";

	FOR(x,3,6) FOR(r,1,20) FOR(c,1,20) if (r<=c) if ((r*c)%x==0)
	{
		cerr << x << " " << r << " " << c << " ";
		bool total_ans = true;
		bool do_check = true;
		// dozen of hacks
		FOR(a,1,r) FOR(b,1,c) if (a<r || b<c) if (ans[x][a][b]) do_check = false;
		if (r<(x+1)/2) { total_ans = false; do_check = false; }
		if (x==4 && r==2) { total_ans = false; do_check = false; }
		if (x==6 && r==3) { total_ans = false; do_check = false; }

		if (do_check)
			for (set< set< PAR > >::iterator it = S[x].begin(); it != S[x].end(); it++)
			{
				X = x; R = r; C = c;
				bool flag = false;
				set< PAR > s = (*it);
				CLR(F);
				FOR(a,1,r) FOR(b,1,c) F[10+a][10+b] = true;
				FOR(a,1,r) FOR(b,1,c)
					if (can_place( 10+a, 10+b, s ))
					{
						place( 10+a, 10+b, s );
						if (!flag)
							if (dfs( 11, 11 ))
								flag = true;
						unplace( 10+a, 10+b, s );
					}
				swap( R, C );
				CLR(F);
				FOR(a,1,r) FOR(b,1,c) F[10+b][10+a] = true;
				FOR(a,1,r) FOR(b,1,c)
					if (can_place( 10+b, 10+a, s ))
					{
						place( 10+b, 10+a, s );
						if (!flag)
							if (dfs( 11, 11 ))
								flag = true;
						unplace( 10+b, 10+a, s );
					}
				if (!flag)
				{
					total_ans = false;
					break;
				}
			}
		ans[x][r][c] = total_ans;
		ans[x][c][r] = total_ans;
		cerr << (total_ans ? "YES" : "NO") << "\n";
		/*static int ttt = 0;
		cout << "ans[" << x << "][" << r << "][" << c << "]=" << (total_ans ? "true" : "false") << ";";
		cout << "ans[" << x << "][" << c << "][" << r << "]=" << (total_ans ? "true" : "false") << ";";
		ttt++; if (ttt%3==0) cout << "\n";*/
	}

	cerr << "time=" << clock() << "\n";
}

string sol()
{
	if (X>=7) return "RICHARD";
	if ((R*C)%X > 0) return "RICHARD";
	if (X<=2) return "GABRIEL";

	return ans[X][R][C] ? "GABRIEL" : "RICHARD";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	init();

	int t=0;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";
		cin >> X >> R >> C;
		cout << "Case #" << a << ": ";
		cout << sol();
		cout << "\n";
	}
	return 0;
}
