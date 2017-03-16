#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, to) for(int i=0; i<to; ++i)

vector<int> V;
int sum = 0;
double res[256];

void bin_search(double from, double to){
	if(to - from < 0.00000001) return;
	double mid = (from + to) / 2.0; 

	double au=0.0; 
	REP(i, V.size()){
		res[i] = max(0.0, (mid - V[i]) / (double) sum); 
		au += res[i];
	}
	if(au > 1.0) bin_search(from, mid);
	else bin_search(mid, to); 
}

int main()
{
	int T;
	cin >> T;
	REP(t, T){
		V.clear();
		sum = 0;
		int N;
		double m=0.0; 
		cin >> N;
		REP(i, N){
			int x;
			cin >> x;
			V.push_back(x);
			sum += x; 
		}
		bin_search(0, 1000000.0);
		printf("Case #%d:", t+1);
		REP(i, N) printf(" %.7lf", res[i]*100.0); 
		printf("\n"); 
	}
  	return 0;
}
