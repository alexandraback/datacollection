#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long LL;
char a[5][5];
int main(){
	int T;
	cin>>T;
	int cas = 0;
	while (T--){
		int i;
		for (int i = 0; i<4; i++){
			cin>>a[i];
		}
		bool x = false, o = false;
		for(int i = 0; i<4; i++){
			int cnt = 0;
			for (int j = 0; j<4; j++) if (a[i][j] == 'X' || a[i][j] == 'T') cnt++;
			if (cnt == 4) x = true;
			cnt = 0;
			for (int j = 0; j<4; j++) if (a[i][j] == 'O' || a[i][j] == 'T') cnt++;
			if (cnt == 4) o = true;
			cnt = 0;
			for (int j = 0; j<4; j++) if (a[j][i] == 'X' || a[j][i] == 'T') cnt++;
			if (cnt == 4) x = true;
			cnt = 0;
			for (int j = 0; j<4; j++) if (a[j][i] == 'O' || a[j][i] == 'T') cnt++;
			if (cnt == 4) o = true;
		}
		int cnt = 0;
		for (int i = 0; i<4; i++) if (a[i][i] == 'X' || a[i][i] == 'T') cnt++;
		if (cnt == 4) x = true;
		cnt = 0;
		for (int i = 0; i<4; i++) if (a[i][i] == 'O' || a[i][i] == 'T') cnt++;
		if (cnt == 4) o = true;
		cnt = 0;
		for (int i = 0; i<4; i++) if (a[i][3-i] == 'X' || a[i][3-i] == 'T') cnt++;
		if (cnt == 4) x = true;
		cnt = 0;
		for (int i = 0; i<4; i++) if (a[i][3-i] == 'O' || a[i][3-i] == 'T') cnt++;
		if (cnt == 4) o = true;

		bool fini = true;
		for (int i = 0; i<4; i++) for (int j = 0; j<4; j++) if (a[i][j] == '.') fini = false;

		cas++;
		cout<<"Case #"<<cas<<": ";
		if (x && !o){
			puts("X won");
		}else
		if (!x && o){
			puts("O won");
		}else
		if (!x && !o && !fini){
			puts("Game has not completed");
		}else
			puts("Draw");
	}

}
