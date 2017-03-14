#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i = (a); i != b; i++)
#define Rep(i,n) For(i,0,n)
#define debug(x) cout<<#x<<": "<<x<<endl
#define Pb push_back
#define Mp make_pair

template<class T>void show(T a,int n) {Rep(i,n)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int n,int m) {Rep(i,n){Rep(j,m)cout<<a[i][j]<<' ';cout<<endl;}}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a%b);
	}
}

int main() {
	int T;
	char line[64], ch;
	scanf("%d", &T);
	gets(line);
	//debug(line);

	Rep(iT, T) {
		printf("Case #%d: ", iT+1);

		int H, W, D, ret = 0, x, y, a, b, d;
		scanf("%d%d%d", &H, &W, &D);
		gets(line);
		//debug(line);
		//while ((ch=getchar()) != '#') {}
		Rep(i, H) {
			gets(line);
			//debug(line);
			Rep(j,W) {
				if (line[j] == 'X') {
					b = i;
					a = j;
				}
			}
		}
		d = D * 2;
		x = (W - 2) * 2;
		y = (H - 2) * 2;
		a = a * 2 - 1;
		b = b * 2 - 1;
		//printf("%d %d %d %d %d ", x,y,a,b,d);
		int d2 = d * d, m, n, dx, dy;
		set<pair<int,int> > spi;
		for (m = -(d/2/x+5); m < (d/2/x+5); m++) {
			for (n = -(d/2/y+5); n < (d/2/y+5); n++) {
				//if (m == 0 && n == 0) continue;
				dx = 2*x*m, dy = 2*y*n;
				if ((dx != 0 || dy != 0) && (dx*dx+dy*dy<=d2)) {
					int gc = gcd(dx,dy);
					if (gc < 0) gc = -gc;
					spi.insert(make_pair(dx/gc,dy/gc));
				}
				dx = 2*x*m-2*a, dy = 2*y*n;
				if ((dx != 0 || dy != 0) && (dx*dx+dy*dy<=d2)) {
					int gc = gcd(dx,dy);
					if (gc < 0) gc = -gc;
					spi.insert(make_pair(dx/gc,dy/gc));
				}
				dx = 2*x*m, dy = 2*y*n-2*b;
				if ((dx != 0 || dy != 0) && (dx*dx+dy*dy<=d2)) {
					int gc = gcd(dx,dy);
					if (gc < 0) gc = -gc;
					spi.insert(make_pair(dx/gc,dy/gc));
				}
				dx = 2*x*m-2*a, dy = 2*y*n-2*b;
				if ((dx != 0 || dy != 0) && (dx*dx+dy*dy<=d2)) {
					int gc = gcd(dx,dy);
					if (gc < 0) gc = -gc;
					spi.insert(make_pair(dx/gc,dy/gc));
				}
			}
		}

		ret = spi.size();
		printf("%d\n", ret);
	}
	return 0;
}
