#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void expAfterDel(int a, int b, const vector<double>& ps, vector<double>& result){
	double p = 1;
	for(int n = a; n >= 0; n--){
		result.push_back(n + p * (b - a + n + 1) + (1-p) * (2 * b - a + n + 2));
		if(n > 0) p *= ps[a-n];
	}
}

int main(){
	int T;
	scanf("%d\n", &T);
	for(int q = 1; q <= T; q++){
		int a, b;
		cin >> a >> b;
		vector<double> ps;
		double p;
		for(int i = 0; i < a; i++){
			cin >> p;
			ps.push_back(p);
		}
		vector<double> possible;
		expAfterDel(a, b, ps, possible);
		possible.push_back(b+2);
		printf("Case #%d: %f\n", q, 
			*min_element(possible.begin(), possible.end()));
	}
}
