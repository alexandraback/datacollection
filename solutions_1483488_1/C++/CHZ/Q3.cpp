#include<iostream>
#include<cstdio>

using namespace std;
bool ocure[2000001];

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    for (int t = 0 ; t < TIME; t++) {
	int low,high;
	cin >> low >> high;
	answer = 0;
	int now,pre;
	int dig;
	int shift[9] = {1,1,
	                  10,
			  100,
			  1000,
			  10000,
			  100000,
			  1000000,
			  2000001};
	int lb,hb,tmp_ans;
	for (int i = low; i <= high; ++i) {
	    ocure[i] = false;
	}
	for (int i = low; i <= high; ++i) {
	    if (ocure[i] == true) continue;
	    ocure[i] = true;
	    tmp_ans = 0;
	    dig = 1;
	    now = i;
	    while (now > shift[dig+1]) {
		dig++;
	    };
	    lb = shift[dig];
	    hb = shift[dig+1]-1;
	    for (int j = 0 ; j < dig-1; ++j) {
		pre = now;
		now = pre / 10 + (pre%10) * shift[dig];
		if (now >=lb && now <= hb && now >=low && now <= high && ocure[now]==false ) {
		    ocure[now] = true;
//		    cout << now << " " << pre << endl;
		    tmp_ans++;
		}
	    }
	    answer+= tmp_ans * (tmp_ans + 1)/2;
	}

	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
