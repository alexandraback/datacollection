#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    long long int r, tt;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> r >> tt;
//	cout << r << " " << tt << endl;
	do {
	    tt -=(r+1)*(r+1)-r*r;
	    if (tt >=0)
		answer++;
	    r+=2;

	} while ( tt > 0);
	/*
	do {
	    paints -= ((radius+1.0)*(radius+1.0)-radius*radius);
	    radius+=2.0;
	    if (paints > 0.0)
		answer++;
	} while ( paints > 0.0);*/

	//output
	printf("Case #%d: %d\n",t+1, answer);
    }
    return 0;
}
