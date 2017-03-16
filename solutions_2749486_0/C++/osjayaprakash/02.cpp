
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int x, y;


int solve(){
	cin >> x >> y;
	int cx=0, cy=0;
	int fx=0, fy=0;
	if(x>0) fx = 1;
	if(y>0) fy = 1;
	for(int i=1;i<=500;i++){
		if(cx!=x){
			if(fx){
				cout << 'W';
				cx -= i; fx ^= 1;
			}else{
				cout << 'E';
				cx += i; fx ^= 1;
			}
		}else if(cy!=y){
			if(fy){
				cout << 'S';
				cy -= i; fy ^= 1;
			}else{
				cout << 'N';
				cy += i; fy ^= 1;
			}
		}else
			break;
	}
}

int main() {
	int tc,z;
	cin >> tc;
	z = tc;
	while(tc--){
		cout << "Case #"<< (z-tc) << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
