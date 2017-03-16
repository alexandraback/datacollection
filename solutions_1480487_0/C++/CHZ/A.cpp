#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    double P[200];
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	int N,sum,min,min2,tmp;
	cin >> N;
	sum = 0;
	for (int i = 0 ; i < N; ++i) {
	    cin >> P[i];
	    sum += P[i];
	}

	//output
	printf("Case #%d:",t+1);
	double avg;
	avg = (double) sum / (double) N;
	int count;
	double osum;
	count = 0;
	osum = 0.0;
	for (int i = 0 ; i < N; ++i) {
	    if (P[i] >= (avg*2.0)) {
		count++;
		osum += P[i];
	    }
	}
	double out = (sum * 2.0 - osum)/ (double)(N-count);
	for (int i = 0 ; i < N; ++i) {
	    if (P[i] >= out)
		printf(" %lf",0.0);
	    else 
		printf(" %lf",((double)(out-P[i])/(double)sum*100.0));
	}
	cout << endl;
    }
    return 0;
}
