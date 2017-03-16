#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    int N;
    cin >> TIME;
    double w1[1000], w2[1000];
    double u1[1000], u2[1000];
    for (int t = 0 ; t < TIME; t++) {
	cin >> N;
	int y,z;
	y = z = 0;
	for (int i = 0 ; i < N; ++i) {
	    cin >> w1[i];
	}
	for (int i = 0 ; i < N; ++i) {
	    cin >> w2[i];
	}
	sort(w1, w1+N);
	sort(w2, w2+N);
	reverse(w1,w1+N);
	reverse(w2,w2+N);
	for (int i = 0 ; i < N; ++i) {
	    u1[i] = u2[i] = 1;
	    //cout << w1[i] << " " << w2[i] << endl;
	}
	int max_1, max_2;
	int min_1, min_2;
	int now_1;
	max_1 = max_2 = 0;
	min_1 = min_2 = N-1;
	int remain;
	int use;
	for (int i = 0 ; i < N-1; ++i) {
	    if (w1[max_1] > w2[max_2]) {
		u1[max_1] = 0;
		max_1++;
		while (u1[max_1]==0)
		    max_1++;
		u2[min_2] = 0;
		min_2--;
		z++;
	    }
	    else { // w1[max_1] < w2[max_2]
		int head = max_2;
		int tail = min_2;
		int mid = (head+tail)/2;
		while (head+1<tail) {
		    mid = (head+tail)/2;
		    if (w2[mid] > w1[max_1]) {
			head = mid;
		    }
		    else {
			tail = mid;
		    }
		}
		use = -1;
		for (int j = tail; j>=max_2; --j) {
		    if (u2[j] == 1 && w2[j] > w1[max_1]) {
			use = j;
		    }
		    if (use!=-1) {
			break;
		    }
		}
		/*
		for (int j = max_2; j< N; ++j) {
		    if (u2[j] == 1 && w2[j] > w1[max_1]) {
			use = j;
		    }
		    if (w2[j] < w1[max_1])
			break;
		}*/
		u1[max_1] = 0;
		max_1++;
		while (u1[max_1]==0)
		    max_1++;
		u2[use] = 0;
		if (use == max_2) {
		    while (u2[max_2]==0)
			max_2++;
		}
	    }
	}
	z += (w1[max_1]>w2[max_2])?1:0;
	max_1 = 0;
	max_2 = 0;
	min_1 = N-1;
	min_2 = N-1;
	int count = 0;
	use = 0;
	do {
	    if (w1[min_1] < w2[min_2]) {
		max_2++;
		min_1--;
	    }
	    else {
		y++;
		min_1--;
		min_2--;
	    }
	} while (min_1>=max_1);

	
	//output
	printf("Case #%d: %d %d\n",t+1, y, z);
    }
    return 0;
}
