#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <string>
#include <iostream>
#include <algorithm>

#include <vector>
#include <map>
#include <set>
#include <queue>

#define dbg(a) cout << a << endl

using namespace std;

string resp;

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t, x, y;
	bool norte, leste;
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		printf("Case #%d: ", caso);
		scanf("%d %d", &x, &y);
		resp = "";

		if(x < 0){
			leste = false;
			x = -x;
		}else{
			leste = true;
		}
		if(y < 0){
			norte = false;
			y = -y;
		}else{
			norte = true;
		}

		for(int i = 0; i < x; i++){
			if(leste){
				resp += "WE";
			}else{
				resp += "EW";
			}
		}

		for(int i = 0; i < y; i++){
			if(norte){
				resp += "SN";
			}else{
				resp += "NS";
			}
		}

		cout << resp << "\n";
	}

	return 0;
}
