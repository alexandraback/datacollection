#include <iostream>
#include <math.h>
using namespace std;

int tc;
int r, c, w;

int main(){
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	cin >> tc;
	for (int i = 0; i < tc; i++){
		cin >> r >> c >> w;
		if (c%w == 0){
			cout << "Case #" << i + 1 << ": " << r*(c/w) + w - 1 << endl;
		} else {
			cout << "Case #" << i + 1 << ": " << r*floor(c/w) + w << endl;
		}
	}
	
	
	
	
}
