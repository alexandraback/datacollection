#include<iostream>
#include<string>
using namespace std;

int main(){
    int T;
    string S;
    cin >> T;
    for(int t=1; t<=T; ++t){
	cin >> S;
	int abcnt[26];
	for(int i=0; i<26; ++i)	abcnt[i] = 0;
	for(char s: S){
	    ++abcnt[s-'A'];
	}
	cout << "Case #" << t << ": ";
	// 0
	int n = abcnt[25];
	while(n > 0){
	    cout << "0";
	    --n;
	}
	// 1
	n = abcnt[14]-abcnt[22]-abcnt[20]-abcnt[25];
	while(n > 0){
	    cout << "1";
	    --n;
	}
	// 2
	n = abcnt[22];
	while(n > 0){
	    cout << "2";
	    --n;
	}
	// 3
	n = abcnt[17]-abcnt[20]-abcnt[25];
	while(n > 0){
	    cout << "3";
	    --n;
	}
	// 4
	n = abcnt[20];
	while(n > 0){
	    cout << "4";
	    --n;
	}
	// 5
	n = abcnt[21]-abcnt[18]+abcnt[23];
	while(n > 0){
	    cout << "5";
	    --n;
	}
	// 6
	n = abcnt[23];
	while(n > 0){
	    cout << "6";
	    --n;
	}
	// 7
	n = abcnt[18]-abcnt[23];
	while(n > 0){
	    cout << "7";
	    --n;
	}
	// 8
	n = abcnt[6];
	while(n > 0){
	    cout << "8";
	    --n;
	}
	// 9
	n = abcnt[8]-abcnt[21]+abcnt[18]-abcnt[23]-abcnt[23]-abcnt[6];
	while(n > 0){
	    cout << "9";
	    --n;
	}
	cout << endl;
    }
    return 0;
}
