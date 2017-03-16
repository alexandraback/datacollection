#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;
int H, N, M;
int c[100][100], f[100][100];
int xx[] = {0,1,0,-1};
int yy[] = {1,0,-1,0};

bool ok(int x, int y){
	if( x < 0 || x >= M || y < 0 || y >= N ) return false;
	return true;
}

bool canPass(int sx, int sy, int dx, int dy){
	if( f[dy][dx] + 50 > c[dy][dx] ) return false;
	if( f[sy][sx] + 50 > c[dy][dx] ) return false;
	if( f[dy][dx] + 50 > c[sy][sx] ) return false;

	return true;
}

bool dostepne(int x, int y){
	return (c[y][x]-50 >= H);
}

double kiedy(int x, int y){
	int level = c[y][x] - 50;

//cerr << "level: " << level << " # " << (H-level) << endl;

	return max(0.0, (double)(H - level)/10.0);
}

double czasPrzejscia(double kiedy, int x, int y){
	double level = max((double)f[y][x], (double)H - (double)kiedy * 10);
//cerr << "czasPrzejscia # level: " << level << " kiedy: " << kiedy << " f[y][x]: " << f[y][x] << " ### ( (double)f[y][x] - level >= 20.0 ): " << ( (double)f[y][x] - level >= 20.0 ) <<endl;
	if( (double)level - f[y][x] >= 20.0 ) return 1.0;
	return 10.0;
}

double go(int _x, int _y){
	bool v[100][100];
	memset(v,0,sizeof v);

	multimap<double, pair<int,int> > mapa;

	mapa.insert(make_pair(0.0, make_pair(_y,_x)));

	double res = 0.0;

	for(multimap<double, pair<int,int> >::iterator it = mapa.begin(); it!=mapa.end(); it++){
		int y = it->second.first, x = it->second.second;
		double czas = it->first;

		if( v[y][x] ) continue;
		v[y][x] = 1;
	
//cerr << y << " " << x << " czas: " << czas << endl;	
		
		if( y == N-1 && x == M-1 ) res = czas;

		for(int i=0; i<4; i++){
			if( ok(x+xx[i], y+yy[i]) ){
				if( canPass(x,y, x+xx[i], y+yy[i]) ){
					if( czas == 0.0 && dostepne(x+xx[i], y+yy[i]) ){
						mapa.insert(make_pair(0.0, make_pair(y+yy[i], x+xx[i])));
					} else {
						double kiedyDostepne = max(czas, kiedy(x+xx[i], y+yy[i]));

						double reachLevel = kiedyDostepne + czasPrzejscia(kiedyDostepne, x, y);
//cerr << y+yy[i] << " " << x+xx[i] << " ## kiedyDostepne: " << kiedyDostepne << " reachLevel: " << reachLevel << endl;
						mapa.insert(make_pair(reachLevel, make_pair(y+yy[i], x+xx[i])));
					}
				}
			}
		}
	}

	return res;
}

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		scanf("%d%d%d", &H, &N, &M);

		fu(a,N) fu(b,M){
			scanf("%d", &c[a][b]);
		}
		fu(a,N) fu(b,M){
			scanf("%d", &f[a][b]);
		}

		printf("%.6f\n", go(0,0));
	}

	return 0;
}
