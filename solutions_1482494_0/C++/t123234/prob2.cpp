#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	int t, n, i, j, o, m, r, c;
	int l[1001][2];
	bool f[1001][2];
	bool isFinish, isFail;
	cin >> t;
	for (i=0; i<t; i++) {
		cin >> n;
		for (j=0; j<n; j++) {
			cin >> l[j][0] >> l[j][1];
		}
		memset(f, 0, sizeof(bool)*2*n);
		
		c = 0;
		r = 0;
		
		isFail = false;
		isFinish = false;
		while (!isFinish) {
			o = -1;
			m = -1;
			
			for (j=0; j<n; j++) {
				if (l[j][1]<=c && f[j][1]==false) {
					o = j;
					break;
				} else if (l[j][0]<=c && f[j][0]==false && l[j][1]>m) {
					o = j;
					m = l[j][1];
				}
			}
			
			if (o<0) {
				isFail = true;
				break;
			} else {
				if (l[o][1]<=c) {
					if (f[o][0]) {
						f[o][1] = true;
						c++;
					} else {
						f[o][0] = true;
						f[o][1] = true;
						c += 2;
					}
				} else {
					f[o][0] = true;
					c++;
				}
				r++;
			}

			isFinish = true;
			for (j = 0; j<2*n; j++) {
				if (!f[j>>1][j&1]) {
					isFinish = false;
					break;
				}
			}
		}
		
		if(isFail || !isFinish){
			cout << "Case #" << (i+1) <<": Too Bad"<<endl;
		} else {
			cout << "Case #" << (i+1) <<": "<<r<<endl;
		}

	}
	
	return 0;
}