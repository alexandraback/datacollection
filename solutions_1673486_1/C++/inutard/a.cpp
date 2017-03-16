#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

typedef double ld;

vector<ld> input;
vector<ld> prob;
ld p;
int N, S, k, c=0;

ld solve() {
	//keep trying
	ld op1 = prob[k-1] * (S - k + 1) + (1-prob[k-1]) * (2 * S - k + 2);
	//cerr << op1 << endl;
	
	//enter right away
	ld op2 = S+2;
	//cerr << op2 << endl;
	
	//backspace r times;
	ld op3 = S+2, newop;
	ld pr;
	for (int i = 0; 2*i <= k+1; i++) {
		if (k-i-1 >= 0) pr = prob[k-i-1];
		else pr = 1;
		
		newop = pr*(S-k+2*i+1)+(1-pr)*(2*S+2*i+2-k);
		op3 = min(op3, newop);
		//cerr << newop << endl;
	}
	
	return min(op1, min(op2, op3));
}

int main() {
	cin >> N;
	
	while (N --> 0) {
	c++;
	cin >> k >> S;
	input.clear();
	prob.clear();
	
	for (int i = 0; i < k; i++) {
		cin >> p;
		input.push_back(p);
	}
	
	prob.push_back(input[0]);
	for (int i = 1; i < k; i++) {
		prob.push_back(input[i] * prob[i-1]);
	}
	
	printf("Case #%d: %.6f\n", c, solve());
	}
}
