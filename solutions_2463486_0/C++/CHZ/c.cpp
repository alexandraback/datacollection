#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    int ans[5] = {1,4,9,121,484};
    cin >> TIME;
    int From, To;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> From >> To;
	for (int i = 0 ; i < 5; ++i) {
	    if (From <= ans[i] && ans[i] <=To)
		answer++;
	}
	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
