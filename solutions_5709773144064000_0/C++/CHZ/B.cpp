#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    double answer;// Final answer
    double C, F, X;
    cin >> TIME;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0.0;
	cin >> C >> F >> X;
	int count = 1;
	double pre_t, now_t, farm_t, now_r;
	now_r = 2.0;
	farm_t = 0.0;
	now_t = X/now_r;
	do {
	    pre_t = now_t;
	    farm_t += C/now_r;
	    now_r += F;
	    now_t = farm_t + X/now_r;
	} while (pre_t > now_t);

	answer = pre_t;
	//output
	printf("Case #%d: %.7lf\n",t+1, answer);
    }
    return 0;
}
