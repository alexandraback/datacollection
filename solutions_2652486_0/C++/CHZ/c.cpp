#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    int R, N, M, K;
    int factor[9][4];
    int ratio[4] = {2,3,5,7};
    long long int tmp;
    long long int Kset[12];
    cin >> R >> N >> M >> K;
    for (int i = 2; i <=M; ++i) {
	tmp = i;
	for (int j = 0 ; j < 4; ++j) {
	    factor[i][j] = 0;
	    while (tmp!=1 && tmp%ratio[j]==0) {
		tmp/=ratio[j];
		factor[i][j]++;
	    }
//	    cout << factor[i][j] << " ";
	}
//	cout << endl;
    }
    int total_factor[12][4];
    int out_counter[9];
    int total_num;
	printf("Case #1:\n");
    for (int T = 0 ; T < R; ++T) {
	total_num = 0;
	for (int i = 0 ; i < 9; ++i) out_counter[i] = 0;
	for (int i = 0 ; i < K; ++i) {
	    cin >> Kset[i];
//	    cout << Kset[i] << endl;
	    tmp = Kset[i];
	    for (int j = 0 ; j < 4; ++j) {
		total_factor[i][j] = 0;
		while (tmp!=1 && tmp%ratio[j]==0) {
		    tmp/=ratio[j];
		    total_factor[i][j]++;
		}
//		cout << total_factor[i][j] << " ";
	    }
//	    cout << endl;
	}
	int local_max[4];
	for (int i = 0 ; i < 4; ++i) local_max[i] = 0;
	for (int i = 0 ; i < K; ++i) {
	    for (int j = 0 ; j < 4; ++j) {
		if (local_max[j] < total_factor[i][j])
		    local_max[j] = total_factor[i][j];
	    }
	}
//	for (int i = 0 ; i < 4; ++i) cout << local_max[i] << " ";
//	cout << endl;
	total_num+= local_max[2] + local_max[3];
	out_counter[5] = local_max[2];
	out_counter[7] = local_max[3];
	if (total_num + local_max[0] + local_max[1] <= N) { // simple case
	    out_counter[2] = local_max[0] + N - (total_num + local_max[0] + local_max[1]);
	    out_counter[3] = local_max[1];
	}
	else {
	    if (M<=5) {
		out_counter[3] = local_max[1]; // 3 is ok
		total_num += local_max[1];
		out_counter[4] = total_num + local_max[0] - N;
		out_counter[2] = local_max[0] - 2 * out_counter[4];
	    }
	}
/*	for (int i = 1 ; i <=M; ++i) {
	    cout << out_counter[i] << " ";
	}
	cout << endl;
*/	

	for (int i = 2 ; i <= M; ++i) {
	    for (int j = 0 ; j < out_counter[i]; ++j) cout << i;
	}
	cout << endl;

    }

    return 0;
}
