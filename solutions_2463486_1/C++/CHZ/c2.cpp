#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
//    int ans[5] = {1,4,9,121,484};
    long long int ans[39] = 
{ 1, 2, 3, 11, 22, 101, 111, 121, 202, 212,
1001, 1111, 2002, 10001, 10101, 10201, 11011,
11111, 11211, 20002, 20102, 100001, 101101, 110011,
111111, 200002, 1000001, 1001001, 1002001, 1010101,
1011101, 1012101, 1100011, 1101011, 1102011, 1110111,
1111111, 2000002, 2001002};
    cin >> TIME;
    long long int From, To;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> From >> To;
	for (int i = 0 ; i < 39; ++i) {
	    if (From <= ans[i]*ans[i] && ans[i]*ans[i] <=To)
		answer++;
	}
	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
