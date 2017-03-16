#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int tests;
	cin >> tests;
	REP(t, tests){
		int d, p[1001];
		int maxx[32][1001];
		int divs[32][1001];
		cin >> d;

		p[0] = 0;
		REP(i, d){
			cin >> p[i+1];
		}
		sort(p, p+d+1);

		REP(i, 32){
			maxx[i][0] = 0;
			divs[i][0] = 0;
		}

		for(int i = 1; i <=d; i++){
			int cur = p[i];
			REP(div, 32){
				int b = 99999999;
				int bd = -1;
				int bm = -1;
				for(int divv = 0; divv <= div; divv++){
					if(divs[divv][i-1] + div + max(maxx[divv][i-1], (cur+div)/(div+1)) < b){
						b = divs[divv][i-1] + div + max(maxx[divv][i-1], (cur+div)/(div+1));
						bd = divs[divv][i-1] + div;
						bm = max(maxx[divv][i-1], (cur+div)/(div+1));
					}
				}
				maxx[div][i] = bm;
				divs[div][i] = bd;
			}
		}

		int b = 9999999;
		REP(i, 32)b = min(b, divs[i][d] + maxx[i][d]);

		cout << "Case #" << t+1 <<": " << b << endl;


	}

	return 0;

}
