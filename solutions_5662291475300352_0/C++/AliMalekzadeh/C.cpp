#include<iostream>
using namespace std;

int n, tt;
int s[100], deg[100];

int main(){
	ios::sync_with_stdio(0);
	cin >> tt;
	for (int ti=0 ; ti<tt ; ti++){
		n = 0;
		int tg;
		cin >> tg;
		for (int i=0 ; i<tg ; i++){
			int x, y, z;
			cin >> x >> y >> z;
			for (int j=0 ; j<y ; j++){
				deg[n] = x;
				s[n] = z + j;
				n++;
			}
		}
		int J = 0;
		if (n==2){
			if (s[0] < s[1]){
				swap(s[0], s[1]);
				swap(deg[0], deg[1]);
			}
			long double t = (360 - deg[0])/360.0 * s[0];
			long double z = deg[1] + t / s[1] * 360;
			if (z + 1e-12 > 360 * 2 ) J = 1;
		}
		cout << "Case #" << ti+1 << ": " << J << endl;
	}
}
