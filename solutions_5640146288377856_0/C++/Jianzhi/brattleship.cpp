#include <iostream>
#include <math.h>
using namespace std;

int tc;
int r, c, w;

int main(){
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	cin >> tc;
	for (int i = 0; i < tc; i++){
		cin >> r >> c >> w;
		if (c%w == 0){
			cout << "Case #" << i + 1 << ": " << (c/w) + w - 1 << endl;
		} else {
			cout << "Case #" << i + 1 << ": " << floor(c/w) + w << endl;
		}
	}
	
	
	
	
}
