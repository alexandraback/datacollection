#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
void win(){
	cout << "RICHARD" << endl;
}
void lose(){
	cout << "GABRIEL" << endl;
}
main() {
	FILE *fin = freopen("D-small-attempt0.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("D-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int x, r, c;
		cin >> x >> r >> c;
		if(c < r) swap(r,c);
		if((r*c) % x != 0){
			win(); continue;
		}
		if(x == 1 || x == 2){
			lose(); continue;
		}
		if(x > c){
			win(); continue;
		}
		if((x >= (r*2+1))){
			win(); continue;
		}
		if(x == 4 && (r == 2) && (c == 4)){
			win(); continue;
		}
		lose(); continue;

	}
	exit(0);
}