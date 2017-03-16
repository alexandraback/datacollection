#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl
#define sp system("pause")

typedef long long ll;

int _max(int a, int b, int c){
	return max(a, max(b,c));
}
int _min(int a, int b, int c){
	return min(a, min(b,c));
}

int main() {
	
	freopen("Bin.txt", "r", stdin);
	freopen("Bout.txt", "w", stdout);
	
	int T, n, s, p;//m number; s surprising; p point
	int a[200];
	int K[10];
	int ans = 0;
	bool r1, r2, r3;
	cin>>T; 
	for(int t = 1; t <= T; ++t) {
		cin>>n>>s>>p;
		memset(K, 0, sizeof(K));
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
			r1 = r2 = r3 = false;
			
			for(int x = p; x <= 30; ++x) {
				for(int y = max(0, x-2); y <= min(30, x+2); ++y)
					for(int z = max(0, x-2); z <= min(30, x+2); ++z) 
						if(x+y+z == a[i] && _max(x,y,z)-_min(x,y,z) <= 2) {
							int cha = _max(x,y,z)-_min(x,y,z);
							r1 = true;
							
							if(cha == 2)
								r2 = true; // arrive & S
							else
								r3 = true; // arrive & !S
						}
			}
			
			if(r1) {
				if(r2&r3) ++K[1];
				if(r2&!r3)	++K[2];
				if(!r2&r3)	++K[3];
			} else {
				if(a[i] < 2 || a[i] > 28) {
					++K[5];
				} else {
					++K[4];
				}
			}
		//see(K[1]);see(K[2]);see(K[3]);see(K[4]);see(K[5]);sp;
		}
		if(s<=K[2])
			ans = K[1]+s+K[3];
		else if(s<=K[2]+K[4]+K[1])	// k2<s<=
			ans = K[1]+K[2]+K[3];
		else
			ans = -1;
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}	
	return 0;
}
