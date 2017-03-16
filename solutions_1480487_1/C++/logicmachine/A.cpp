#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int main(){
	cout << setiosflags(ios::fixed) << setprecision(10);
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int N;
		cin >> N;
		vector<int> J(N);
		for(int i = 0; i < N; ++i){ cin >> J[i]; }
		double X = accumulate(J.begin(), J.end(), 0);
		cout << "Case #" << caseNum << ":";
		for(int i = 0; i < N; ++i){
			double left = 0.0, right = X;
			for(int iter = 0; iter < 1000; ++iter){
				double center = (left + right) / 2.0;
				double remains = (X - center);
				double score = J[i] + center;
				for(int j = 0; j < N; ++j){
					if(i == j){ continue; }
					if(J[j] < score){
						remains -= score - J[j];
					}
				}
				if(remains < 0.0){
					right = center;
				}else{
					left = center;
				}
			}
			cout << " " << left / X * 100;
		}
		cout << endl;
	}
	return 0;
}
