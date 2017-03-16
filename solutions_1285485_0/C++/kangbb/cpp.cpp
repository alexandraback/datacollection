#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef long long int uint64;
#define MAXN 35
#define MAXC 410
#define MID (MAXC / 2)

int H, W, D;
int X, Y;

char s[MAXN];
bool grid[MAXC][MAXC];

int ans;
struct VEC{
	int x, y;

	int gcd( int a, int b ){
		if(a == 0) return b;
		return gcd(b%a, a);
	}

	VEC(int xin, int yin){
		int d = gcd( abs(xin), abs(yin));
		x = xin / d;
		y = yin / d;
	}

	bool operator< (const VEC vin) const{
		return (vin.x < x || (vin.x == x && vin.y < y));
	}
};

map<VEC, bool> map_count;



void set( int x, int y ){
	grid[x + MID][y + MID] = true;
}

bool isset( int x, int y ){
	return grid[x + MID][y + MID];
}

void buildgrid( int x, int y, int up, int down, int left, int right )
{
	int dx = x - X;
	int dy = y - Y;
	if( abs(dx) > D || abs(dy) > D ) return;
	if( isset(x, y) ) return;
	if( ((dx)*(dx) + (dy)*(dy)) > D*D ) return;


	set( x, y );
	if(x!=X||y!=Y){
		VEC v(dx, dy);
		if(map_count[v] == false){
			map_count[v] = true;
			ans++;
			//printf("set: %d, %d [%d, %d, %d, %d]\n", x, y,up, down, left, right );
		}
		//else{
		//	printf("= set: %d, %d [%d, %d, %d, %d]\n", x, y,up, down, left, right );
		//}
	}
	// up ways
	//printf("up\n");
	buildgrid( (2 * up - x), y, up + H, up, left, right);
	// down
	//printf("down\n");
	buildgrid( (2 * down - x), y, down, down - H, left, right);
	// left
	//printf("left\n");
	buildgrid( x, (2 * left - y), up, down, left - W, left);
	// right
	//printf("right\n");
	buildgrid( x, (2 * right - y), up, down, right , right + W);
}

int main() {

	int cases;
	int caseindex = 0;

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {
		ans = 0;
		map_count.clear();
		memset(grid, false, sizeof(grid));
		// read information
		scanf("%d%d%d", &H, &W, &D);

		// read grid
		for( int i = 0;i < H; i++ ){
			scanf("%s", s);
			for( int j = 0;j < W; j++ ){
				if(s[j] == 'X'){
					X = (i - 1) * 2 + 1;
					Y = (j - 1) * 2 + 1;
				}
			}
		}

		H = (H - 2) * 2 ;
		W = (W - 2) * 2 ;
		D *= 2;

		//printf("%d %d %d, %d %d\n", H, W, D, X, Y);

		// solve
		buildgrid(X, Y, H, 0, 0, W);

//		for( int i = -20; i <= 20; i++ ){
//			for( int j = -20; j <= 20; j++ ){
//
//				printf("%d ", isset(i, j) ? 1:0);
//			}
//			printf("\n");
//		}
		caseindex++;
		printf("Case #%d: %d\n", caseindex, ans);
		fflush(stdout);
	}

	return 0;
}
