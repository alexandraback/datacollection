#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
int H, W, D;

vector<string> a;
vector< pair<int,int> > p;
set< pair<int,int> > S;

int dist( int x1, int y1, int x2, int y2 )
	{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	}

int main()
	{

	int T;
	cin >> T;

	for( int t = 0 ; t< T; ++t )
		{
		p.clear(); S.clear();
		cin >> H >> W >> D;
		a.resize(H);
		for( int i = 0; i < H; ++i )
			cin >> a[i];

		int sx = 0, sy = 0;
		for( int i = 0; i < H; ++i ) for( int j = 0; j < W; ++j )
			if( a[i][j] == 'X' )
				{sx = i; sy = j;}
		//cout << sx << " " << sy << endl;
		
		int lx = 2*(H - sx - 1) - 1;
		int ly = 2*(W - sy - 1) - 1;
		int dx = H-2, dy = W - 2;
		//cout << dx << " " << dy << endl;		
		//cout << lx << " " << ly << endl;
		int sol = 0;
		
		for( int i = sx - 50; i <= sx + 50; ++i )
			for ( int j = sy - 50; j <= sy + 50; ++j )
				if( dist(i,j,sx,sy) <= D*D && dist(i,j,sx,sy) > 0)
					{
					int tx = i-sx; while( tx < 0 ) tx += 2*dx;
					int ty = j-sy; while( ty < 0 ) ty += 2*dy;
					int ok1 = 0, ok2 = 0;
					if( tx % (2*dx) == 0 || tx %(2*dx) == lx ) ok1 = 1;
					if( ty % (2*dy) == 0 || ty %(2*dy) == ly ) ok2 = 1;
					if( ok1 && ok2 ) 
						p.push_back(make_pair(i,j));						
					}
	
		for( int i = 0; i < p.size(); ++i )	
			{
			bool ubacio = false;
			for( set<pair<int,int> >::iterator it = S.begin(); it!= S.end(); ++it )
				{
				bool kol = false;
				if((p[i].first - sx)*(it->second - sy) == (it->first - sx)*(p[i].second - sy))
					kol = true;
				bool side = false;
				if( (p[i].first - sx) * (it->first -sx) < 0 || (p[i].second - sy)*(it->second -sy ) <0 )
					side = true;
				if( kol && !side )
					{
					if( dist(p[i].first, p[i].second, sx, sy ) < dist(it->first, it->second, sx, sy ) )
						{ S.erase(it); S.insert(p[i]);}
					ubacio = true;
					break;
					}
				}
			if(!ubacio) S.insert(p[i]);
			}
		sol = S.size();
		//for( set<pair<int,int> >::iterator it = S.begin(); it!= S.end(); ++it )
		//	cout << it->first << " " << it->second << endl;
		printf("Case #%d: %d\n",t+1,sol);
		}

	return 0;
	}
