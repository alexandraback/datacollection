#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    int T,S,P;
    for (int t = 0 ; t < TIME; t++) {
	cin >> T >> S >>P;
	int now, num_p, num_p_s, mod, P3;
	P3 = P * 3;
	num_p = num_p_s = 0;
	for (int i = 0 ; i < T; ++i) {
	    cin >> now;
	    if (now==0) {
		if (P==0) num_p++;
		continue;
	    }
	    mod = now%3;
	    switch (mod){
		case 0: if (now>=P3) {
			    num_p++;
			}
			else {
			    if (now>=P3-3) 
				num_p_s++;
			}
			break;
		case 1: if (now>=P3-2) {
			    num_p++;
			}
			break;
		case 2: if (now>=P3-1) {
			    num_p++;
			}
			else {
			    if (now>=P3-4) 
				num_p_s++;
			}
			break;
	    }
	}
	answer = num_p + (num_p_s>=S?S:num_p_s);

	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
