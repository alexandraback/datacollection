#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <deque>


#define FOR(i,a,b) for(int(i)=a;i<b;i++)
#define MAX 200004
#define mp make_pair
using namespace std;

typedef long long ll;
vector<ll> tree(MAX,0);

int main() {
	string a;
	getline(cin,a);
	int t = atoi(a.c_str());
	int num = 1;
	while(t--){
		string a[4];
		string emp="";
		getline(cin,a[0]);
		getline(cin,a[1]);
		getline(cin,a[2]);
		getline(cin,a[3]);
		getline(cin,emp);
		bool dot = false;
		bool done = false;
		for(int i=0;i<4&&!done;i++) {
			for(int j=0;j<4;j++) {
				if(a[i][j] == '.'){
					dot = true;
					done = true;
					break;
				}
			}
		}
		int win = -1;
		if((a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X') || (a[0][0] == 'T' && a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X') || (a[0][0] == 'X' && a[1][1] == 'T' && a[2][2] == 'X' && a[3][3] == 'X')|| (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'T' && a[3][3] == 'X')|| (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'T'))
			win = 0;
		else if((a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'O') || (a[0][0] == 'T' && a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'O') || (a[0][0] == 'O' && a[1][1] == 'T' && a[2][2] == 'O' && a[3][3] == 'O')|| (a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'T' && a[3][3] == 'O')|| (a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'T'))
			win = 1;
		else if((a[0][3] == 'X' && a[1][2] == 'X' && a[2][1] == 'X' && a[3][0] == 'X') || (a[0][3] == 'T' && a[1][2] == 'X' && a[2][1] == 'X' && a[3][0] == 'X') || (a[0][3] == 'X' && a[1][2] == 'T' && a[2][1] == 'X' && a[3][0] == 'X')|| (a[0][3] == 'X' && a[1][2] == 'X' && a[2][1] == 'T' && a[3][0] == 'X')|| (a[0][3] == 'X' && a[1][2] == 'X' && a[2][1] == 'X' && a[3][0] == 'T'))
			win = 0;
		else if((a[0][3] == 'O' && a[1][2] == 'O' && a[2][1] == 'O' && a[3][0] == 'O') || (a[0][3] == 'T' && a[1][2] == 'O' && a[2][1] == 'O' && a[3][0] == 'O') || (a[0][3] == 'O' && a[1][2] == 'T' && a[2][1] == 'O' && a[3][0] == 'O')|| (a[0][3] == 'O' && a[1][2] == 'O' && a[2][1] == 'T' && a[3][0] == 'O')|| (a[0][3] == 'O' && a[1][2] == 'O' && a[2][1] == 'O' && a[3][0] == 'T'))
			win = 1;

		else {
			bool done = false;
			for(int i=0;i<4;i++) {
				if(a[i] == "XXXX" || a[i] == "XXXT" || a[i] == "XXTX" || a[i] == "XTXX" || a[i] == "TXXX")
					win = 0;
				else if(a[i] == "OOOO" || a[i] == "OOOT" || a[i] == "OOTO" || a[i] == "OTOO" || a[i] == "TOOO")
					win = 1;
			}
			for(int i = 0;i<4;i++){
				if((a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X' && a[3][i] == 'X') || (a[0][i] == 'T' && a[1][i] == 'X' && a[2][i] == 'X' && a[3][i] == 'X') || (a[0][i] == 'X' && a[1][i] == 'T' && a[2][i] == 'X' && a[3][i] == 'X')|| (a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'T' && a[3][i] == 'X')|| (a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X' && a[3][i] == 'T'))
					win = 0;
				else if((a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O' && a[3][i] == 'O') || (a[0][i] == 'T' && a[1][i] == 'O' && a[2][i] == 'O' && a[3][i] == 'O') || (a[0][i] == 'O' && a[1][i] == 'T' && a[2][i] == 'O' && a[3][i] == 'O')|| (a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'T' && a[3][i] == 'O')|| (a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O' && a[3][i] == 'T'))
					win = 1;
				}
			
		}
		if(win == 0)
			cout <<"Case #"<<num<<": X won"<<endl;
		else if(win == 1)
			cout <<"Case #"<<num<<": O won"<<endl;
		else {
			if(dot)
				cout <<"Case #"<<num<<": Game has not completed"<<endl;
			else
				cout <<"Case #"<<num<<": Draw"<<endl;
		}
			num++;
	}
	return 0;
}