#include <iostream>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int digsum3(int n){
	if(n == 0)return 0;
	return (n%3)+digsum3(n/3);
}

int pos(int n, int a){
	REP(i, a)n/=3;
	return n%3;
}


int main(){
	int tests;
	cin >> tests;
	REP(t, tests){
		int d, p[7];
		int max = 0;
		cin >> d;
		REP(i, d){
			cin >> p[i];
			if(p[i] > max) max = p[i];
		}

		int min = max;

		REP(i, 729){
			if(digsum3(i) >= max)continue;
			vector<int> x;
			REP(j, d){
				int poss = pos(i, j);
				if(poss == 0)x.push_back(p[j]);
				if(poss == 1){
					x.push_back(p[j]/2);
					x.push_back(p[j] - p[j]/2);
				}
				if(poss == 2){
					x.push_back(p[j]/3);
					x.push_back((p[j]+1)/3);
					x.push_back((p[j]+2)/3);
				}
			}
			int tmp = 0;
			REP(k, x.size())if(x[k] > tmp)tmp = x[k];
			if(digsum3(i) + tmp < min)min = digsum3(i) + tmp;
		}

		cout << "Case #" << t+1 <<": " << min << endl;
	}
	return 0;
}
