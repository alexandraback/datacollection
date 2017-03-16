#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

string s[4];

bool eq(char a,char b){
	if (a=='T'||b=='T')return 1;
	return a==b;
}


int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> s[0] >> s[1] >> s[2] >> s[3];
		int t;
		string ans="Draw";
		for (int i=0;i<4;i++)for (int j=0;j<4;j++)if (s[i][j]=='.')ans="Game has not completed";


		for (int i=0;i<4;i++){
			t=1;
			for (int j=0;j<4;j++)if (eq(s[i][j],'X')==0)t=0;
			if (t)ans="X won";
		}
		for (int i=0;i<4;i++){
			t=1;
			for (int j=0;j<4;j++)if (eq(s[j][i],'X')==0)t=0;
			if (t)ans="X won";
		}
		t=1;
		for (int j=0;j<4;j++)if (eq(s[j][j],'X')==0)t=0;
		if (t)ans="X won";
		t=1;
		for (int j=0;j<4;j++)if (eq(s[3-j][j],'X')==0)t=0;
		if (t)ans="X won";






		for (int i=0;i<4;i++){
			t=1;
			for (int j=0;j<4;j++)if (eq(s[i][j],'O')==0)t=0;
			if (t)ans="O won";
		}
		for (int i=0;i<4;i++){
			t=1;
			for (int j=0;j<4;j++)if (eq(s[j][i],'O')==0)t=0;
			if (t)ans="O won";
		}
		t=1;
		for (int j=0;j<4;j++)if (eq(s[j][j],'O')==0)t=0;
		if (t)ans="O won";
		t=1;
		for (int j=0;j<4;j++)if (eq(s[3-j][j],'O')==0)t=0;
		if (t)ans="O won";


		cout << "Case #" << E << ": " << ans << endl;
	}
	return 0;
}


