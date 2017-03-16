#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    int X, Y;
    for (int t = 0 ; t < TIME; t++) {
	//output
	printf("Case #%d: ",t+1);
	cin >> X >> Y;
	if (X > 0) {
	    for (int i = 0 ; i < X; ++i) {
		cout << "WE";
	    }
	}
	if (X<0) {
	    for (int i = 0 ; i > X; --i) {
		cout << "EW";
	    }
	}
	if (Y > 0) {
	    for (int i = 0 ; i < Y; ++i) {    
		cout << "SN";                
	    }
	}                             
	if (Y<0) {
	    for (int i = 0 ; i > Y; --i) {
		cout << "NS";
	    }
	}
	cout << endl;
    }

    return 0;
}
