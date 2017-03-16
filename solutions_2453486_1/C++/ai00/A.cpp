#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string ai00(){
	string s[4];
	for (int i = 0; i < 4; ++i) cin>>s[i];
	int empty = 0;
	for (int i = 0; i < 4; ++i){
		int a = 0, b = 0;
		for (int j = 0; j < 4; ++j)
			if (s[i][j] == 'X') ++a;
			else if (s[i][j] == 'O') ++b;
			else if (s[i][j] == 'T'){++a; ++b;}
			else ++empty;
		if (a == 4) return "X won";
		if (b == 4) return "O won";
	}
	for (int i = 0; i < 4; ++i){
		int a = 0, b = 0;
		for (int j = 0; j < 4; ++j)
			if (s[j][i] == 'X') ++a;
			else if (s[j][i] == 'O') ++b;
			else if (s[j][i] == 'T'){++a; ++b;}
		if (a == 4) return "X won";
		if (b == 4) return "O won";
	}
	{
		int a = 0, b = 0;
		for (int i = 0; i < 4; ++i)
			if (s[i][i] == 'X') ++a;
			else if (s[i][i] == 'O') ++b;
			else if (s[i][i] == 'T'){++a; ++b;}
		if (a == 4) return "X won";
		if (b == 4) return "O won";
	}
	{
		int a = 0, b = 0;
		for (int i = 0; i < 4; ++i)
			if (s[i][3 - i] == 'X') ++a;
			else if (s[i][3 - i] == 'O') ++b;
			else if (s[i][3 - i] == 'T'){++a; ++b;}
		if (a == 4) return "X won";
		if (b == 4) return "O won";
	}
	if (empty) return "Game has not completed";
	return "Draw";
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, tt;
	for (scanf("%d ", &t), tt = 0; tt < t; ++tt){
		cout<<"Case #"<<tt + 1<<": "<<ai00()<<endl;
	}
}
