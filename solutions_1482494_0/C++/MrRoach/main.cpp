#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int t;
int level1[2010];
int level2[2010];

int main(){
	cin >> t;
	for (int time  = 0; time < t ; ++ time) {
		int n;
		cin >> n;
		memset(level1, 0, sizeof(level1));
		memset(level2, 0, sizeof(level2));
		int maxl2 = 0;
		int a, b;
		for (int i =0 ;i < n; ++i){
			cin>>a >> b;
			level1[a] ++;
			level2[b] ++;
			if (b > maxl2) maxl2 = b;
		}
		int h = 0;
		int l2c = level2[0]*2;
		int l1c = level1[0];
		int mingame = n;
		while (h < maxl2) {
			if (l2c > 0) {
				l2c -- ;
				h ++;
				l2c += level2[h]*2;
				l1c += level1[h];
			} else if (l1c > 0) {
				l1c --;
				h ++;
				l2c += level2[h]*2;
				l1c += level1[h];
				mingame ++;
			} else {
				mingame = -1;
				break;
			}
		}

		cout <<"Case #" << (time + 1) << ": ";
		if (mingame == -1){
			cout <<"Too Bad";
		} else {
			cout << mingame;
		}
		cout << endl;
	}
	return 0;
}