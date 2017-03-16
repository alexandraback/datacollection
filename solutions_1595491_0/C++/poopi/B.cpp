								/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("B.in");
ofstream fout("B.out");

#define cin fin
#define cout fout

int n, s, p;

int main(){
	int T, test = 0;
	for(cin >> T; T--; ){
		int a, b, cnt = 0;
		cin >> n >> s >> p;
		for(int i = 0; i < n; i++){
			cin >> a;
			b = (a + 2) / 3;
			if(b >= p)
				cnt++;
			if(b == p - 1 && a % 3 != 1 && a != 0 && s > 0){
				s--;
				cnt++;
			}
		}
		cout << "Case #" << ++test << ": " << cnt << endl;
	}
	return 0;
}
