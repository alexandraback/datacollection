#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	char map[200][200] = {{0}};
	char s[256];
	for (int i = 0; i< T; i++) {
		int w,h,d;
		cin >> h >> w >> d;
		int px,py;
		cin.get();
		for (int y=0;y<h;y++) {
			cin.getline(s,sizeof(s));
			// cout << s << endl;
			for (int x=0; x<w ; x++) {
				if (s[x]=='X') {
					px = x; py = y;
				}
			}
		}
		// cout << px << "," << py << endl;
		int ans = 0;
		vector<double> degs;
		for (int y=-55; y<55; y++) {
			for (int x=-55; x<55; x++) {
				if (x == 0 && y==0) continue;
				int tx = (w-2)*x + ((x%2)?((w-2)-(px)):(px-1)) + 1;
				int ty = (h-2)*y + ((y%2)?((h-2)-(py)):(py-1)) + 1;
				
				//cout  << "X? "  << tx << "," << ty << endl;
				if ( (tx-px)*(tx-px) + (ty-py)*(ty-py) <= d*d ) {
					// cout  << "X "  << tx << "," << ty << endl;
					double d = atan2(tx-px*1.0,ty-py*1.0);
					for (auto it=degs.begin(); it!=degs.end(); ++it) {
						if (abs(*it-d) < 0.00000000000001) {
							d = 99;
							break;
						}
					}
					if (d < 10.0) {
						ans++;
						degs.push_back(d);
					}
				}
			}
		}

		cout << "Case #" << (i+1) << ": " << ans << endl;
	}
	
	
	return 0;
}


