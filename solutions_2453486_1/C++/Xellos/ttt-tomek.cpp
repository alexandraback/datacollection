// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	int T;
	cin >> T;
	string res[] ={"Draw","Game has not completed","O won","X won"};
	for(int t =0; t < T; t++) {
		string s[4];
		for(int i =0; i < 4; i++) cin >> s[i];
		int stav =-1;
		for(int i =0; i < 4; i++) {
			int a =0, b =0;
			for(int j =0; j < 4; j++) {
				if(s[i][j] == '.' && stav == -1) stav =0;
				if(s[i][j] == 'T' || s[i][j] == 'O') a++;
				if(s[i][j] == 'T' || s[i][j] == 'X') b++;}
			if(a == 4) stav =1;
			else if(b == 4) stav =2;}
		if(stav < 1) for(int i =0; i < 4; i++) {
			int a =0, b =0;
			for(int j =0; j < 4; j++) {
				if(s[j][i] == 'T' || s[j][i] == 'O') a++;
				if(s[j][i] == 'T' || s[j][i] == 'X') b++;}
			if(a == 4) stav =1;
			else if(b == 4) stav =2;}
		int a =0, b =0;
		if(stav < 1) for(int i =0; i < 4; i++) {
			if(s[i][i] == 'T' || s[i][i] == 'O') a++;
			if(s[i][i] == 'T' || s[i][i] == 'X') b++;}
		if(a == 4) stav =1;
		else if(b == 4) stav =2;
		a =b =0;
		if(stav < 1) for(int i =0; i < 4; i++) {
			if(s[3-i][i] == 'T' || s[3-i][i] == 'O') a++;
			if(s[3-i][i] == 'T' || s[3-i][i] == 'X') b++;}
		if(a == 4) stav =1;
		else if(b == 4) stav =2;
		cout << "Case #" << t+1 << ": " << res[stav+1] << endl;}		
	return 0;}
        
// look at my code
// my code is amazing
