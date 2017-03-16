#include<iostream>
#include<cstdio>

using namespace std;

int DP[1000][1000];

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    int E, R, N;
    int value[1000];
    int tmp;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> E >> R >> N;
	for (int i = 0 ; i < N; ++i) {
	    for (int j = 0 ; j <=E; ++j) {
		DP[i][j] = 0;
	    }
	}
	for (int i = 0 ; i < N; ++i) {
	    cin >> value[i];
	}
	// first step
	for (int i = 0; i <= E; ++i) {
	    DP[0][E-i] = i * value[0];
	}
	int mamE;
	//second to end
	for (int i = 1; i < N; ++i) {
	    for (int j = 0; j <= E; ++j) {
		tmp = DP[i-1][j];
		if (j+R > E) mamE = E;
		else mamE = j+R;
		for (int k = 0; k <= mamE; ++k) {
		    if (tmp + k * value[i] > DP[i][mamE - k])
			DP[i][mamE-k] = tmp + k * value[i];
		}
	    }
	}
/*	for (int i = 0 ; i < N; ++i) {
	    for (int j = 0; j < E; ++j) {
		cout << DP[i][j] << " ";
	    }
	    cout << endl;
	}*/

	for (int i = 0; i <=E; ++i) {
	    if (answer < DP[N-1][i])
		answer =  DP[N-1][i];
	}

	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
