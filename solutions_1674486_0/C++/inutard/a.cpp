#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<double> input;
vector<double> sol;
int S, s;
int T, N;

int main() {
	cin >> T;
	
	int c = 0, C = 0;
	double w = 0;
	while (T --> 0) {
	c++;
	cin >> N;
	input.clear();
	S = 0;
	w = 0;
	C = N;
	
	for (int i = 0; i < N; i++) {
		cin >> s;
		input.push_back(s);
		S+=s;
	}
	
	for (int i = 0; i < N; i++) {
		sol.push_back(100*(2.0/N - input[i]/S));
		if (100*(2.0/N - input[i]/S) < 0) {
			w -= 100*(2.0/N - input[i]/S);
			C--;
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (sol[i] < 0) sol[i] = 0;
		else sol[i] += w/C;
	}
	
	printf("Case #%d: ", c);
	for (int i = 0; i < N-1; i++) {
		printf("%.6f ", 100*(2.0/N - input[i]/S));
	}
	printf("%.6f\n", max(100*(2.0/N - input[N-1]/S), 0.0));
	
	}
}
