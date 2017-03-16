#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <string.h>
#include <boost/regex.hpp>

using namespace std;


int N;
vector<long long> bnum;
vector<long long> btyp;
int M;
vector<long long> tnum;
vector<long long> ttyp;
vector< vector< map< long long, map< long long, long long> > > > memo;

long long solve(int bi, long long bn, int mi, long long mn)
{
	if ( bi >= bnum.size() || mi >= tnum.size() ) return 0;
	
	map< long long, map< long long, long long> >::iterator itr;
	if ( (itr=memo[bi][mi].find( bn )) != memo[bi][mi].end() ) {
		map< long long, long long>::iterator itr2;
		if ( (itr2= itr->second.find(mn)) != itr->second.end() ) {
			return itr2->second;
		}
	}
	long long tm1 = 0;
	if ( bi < bnum.size() - 1 && (bi == 0 || btyp[bi] != btyp[bi-1]) ) {
		int bii = bi + 1;
		while ( bii < bnum.size() && btyp[bi] == btyp[bii] ) bii++;
		tm1 = solve(bi+1,0,mi,mn);
	}
	
	long long tm2 = 0;
	if ( btyp[bi] == ttyp[mi] ) {
		if ( bnum[bi] - bn >= tnum[mi] - mn && tnum[mi] - mn > 0 ) {
			assert(tnum[mi] - mn> 0);
			tm2 += tnum[mi] - mn;
			tm2 += solve( bi, bn + tm2, mi + 1, 0);
		} else if ( bnum[bi] - bn < tnum[mi] - mn && bnum[bi] - bn > 0 ) {
			assert(bnum[bi] - bn> 0);
			tm2 += bnum[bi] - bn;
			tm2 += solve( bi+1, 0, mi, mn + tm2);
		}
		
	}
	long long tm3 = 0;
	if ( mi < tnum.size() - 1 && (mi == 0 || ttyp[mi] != ttyp[mi-1]) ) {
		int mii = mi + 1;
		while ( mii < tnum.size() && ttyp[mi] == ttyp[mii] ) mi++;
		tm3 = solve(bi,bn,mi+1,0);
	}

	long long ret = max(tm1,max(tm2,tm3));


//	map< long long, map< long long, long long> >::iterator itr;
	if ( (itr=memo[bi][mi].find( bn )) != memo[bi][mi].end() ) {
		itr->second.insert( pair< long long, long long>( mn, ret));
	} else {
		 map< long long, long long>m;
		 m.insert( pair< long long, long long>( mn, ret));
		 memo[bi][mi].insert( pair< long long, map< long long, long long> >( bn, m));
	}
	return ret;
}

int main(int argc, char* argv[])
{
	int	casenum;
	cin >> casenum;
	for ( int c = 1; c <= casenum; c++ ) {
		memo.clear();
		for ( int i = 0; i < 101; i++ ) {
			vector< map< long long, map< long long, long long> > > v;
			memo.push_back(v);
			for ( int j = 0; j < 101; j++ ) {
				map< long long, map< long long, long long> > m2;
				memo[i].push_back(m2);
			}
		}
		cin >> N >> M;
		bnum.clear();
		btyp.clear();
		tnum.clear();
		ttyp.clear();
		for ( int j = 0; j < N; j++ ) {
			long long n,t;
			cin >> n >> t;
			bnum.push_back(n);
			btyp.push_back(t);
		}
		for ( int j = 0; j < M; j++ ) {
			long long n,t;
			cin >> n >> t;
			tnum.push_back(n);
			ttyp.push_back(t);
		}

		cout << "Case #" << c << ": " << solve(0,0,0,0) << endl;
	}

	return 0;
}
