#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int w, h, a[100][100];

bool f(int ax, int ay, int k){
	bool flag = false;
	for(int y = 0; y < h; y++){
		if( y == ay ) continue;
		if( k < a[y][ax] ) flag = true;
	}
	for(int x = 0; x < w; x++){
		if( x == ax ) continue;
		if( k < a[ay][x] && flag ) return false;
	}
	return true;
}

bool solve(){
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			if( !f(x, y, a[y][x]) ) return false;
		}
	}
	return true;
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> h >> w;
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				cin >> a[y][x];
			}
		}
		bool ans = solve();
		cout << "Case #" << t << ": " << (ans? "YES" : "NO") << endl;
	}
}

