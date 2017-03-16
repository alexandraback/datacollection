#include<iostream>
#include<cstdio>

using namespace std;

    char names[1000001];
int main(int artc, char* argv[]) {

    int TIME;// number of test
    long long int answer;// Final answer
    cin >> TIME;
    int N;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> names >> N;
	int index = 0;
	while (names[index]!='\0') {
	    index++;
	}
	int num_c;
	int head_c = 0;
	num_c = 0;
	int first_c;
	int second_c;
	int prev_c;
	first_c = second_c = prev_c = -1;
	for (int i = 0 ; i< index; ++i) {
//	    cout << i << " " << " " << names[i] << " " <<num_c << endl;
	    if (
		    names[i]!='a' &&
		    names[i]!='e' &&
		    names[i]!='i' &&
		    names[i]!='o' &&
		    names[i]!='u' ) {
		num_c++;
	    }
	    else {
		num_c =0;
	    }
	    if (num_c >= N) {
		first_c = i;
//		cout << (first_c +1 -N - prev_c)  << " " <<  (index - first_c) << endl;
		answer += (first_c +1 -N - prev_c) * (index - first_c);
		prev_c = i - N + 1;
	    }
	    /*
	    if (num_c >= N) {
		if (first_c == -1) {
		    first_c = i;
		}
		else {
		    second_c = i;
		    answer += (first_c+1 - N + 1) * (index - first_c);
		    prev_c = first_c;
		    first_c = second_c;
		}
	    }*/
	}
	/*
	if (second_c != -1) {
	    answer += (first_c - prev_c)* (index - first_c) ;
	}
	else { // second == -1
	    if (first_c == -1){
		answer = 0;
	    }
	    else {
		answer += (first_c  -N +2) * (index - first_c);
	    }
	}*/
	//output
	printf("Case #%d: %lld\n",t+1, answer);
    }
    return 0;
}
