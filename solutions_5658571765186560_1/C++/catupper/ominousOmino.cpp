#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string str;
int n, t, l, x;
int val[108000];
#define I 2
#define J 3
#define K 4

string solve(){
	int x, r, c;
	cin >> x >> r >> c;
	if(r > c)swap(r, c);
	if(x >= 7)return "RICHARD";
	if(r * c % x != 0)return "RICHARD";
	if(x == 1)return "GABRIEL";
	if(x == 2)return "GABRIEL";
	if(x == 3){
		if(r > 1 && c > 1)return "GABRIEL";
		else return "RICHARD";
	}
	if(x == 4){
		if(r <= 2)return "RICHARD";
		else return "GABRIEL";
	}
	if(x == 5){
		if(r <= 2)return "RICHARD";
		if(r == 3 && c <= 5)return "RICHARD";
		if(r == 3 && c >= 10)return "GABRIEL";
		if(r >= 4)return "GABRIEL";
	}
	if(x == 6){
		if(r <= 3)return "RICHARD";
		else return "GABRIEL";
	}
}



int main(){
	cin >> t;
	for(int i = 1;i <= t;i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}