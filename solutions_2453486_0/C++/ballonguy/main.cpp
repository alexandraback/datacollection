#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
using namespace std;

typedef long long Int;
#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
#define sqr(x) (x)*(x)
const double PI = acos(-1.0);

char s[4][4];

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	freopen("A-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);
	int tests;scanf("%d\n",&tests);
	for(int test = 1; test <= tests; ++ test) {
		for(int i = 0; i < 4; ++i) gets( s[i] );
		bool owin = false, xwin = false;
		for(int i = 0; i < 4; ++i){
			bool cur = true;
			for(int j = 0; j < 4; ++j)if(s[i][j] != 'T' && s[i][j] != 'X')
				cur = false;
			if(cur)xwin = true;
			cur = true;
			for(int j = 0; j < 4; ++j) if(s[i][j] != 'T' && s[i][j] != 'O')
				cur = false;
			if(cur)owin = true;
		}

		for(int j = 0; j < 4; ++j){
			bool cur = true;
			for(int i = 0; i < 4; ++i)if(s[i][j] != 'T' && s[i][j] != 'X')
				cur = false;
			if(cur)xwin = true;
			cur = true;
			for(int i = 0; i < 4; ++i) if(s[i][j] != 'T' && s[i][j] != 'O')
				cur = false;
			if(cur)owin = true;
		}

		bool cur = true;
		for(int i = 0; i < 4; ++i)if(s[i][i]!='T' && s[i][i] != 'X')cur=false;
		if(cur)xwin = true;

		cur = true;
		for(int i = 0;i<4;++i)if(s[i][i]!='T' && s[i][i]!='O')cur = false;
		if(cur)owin = true;

		cur = true;
		for(int i = 0; i < 4; ++i)if(s[i][3-i]!='T' && s[i][3-i] != 'X')cur=false;
		if(cur)xwin = true;

		cur = true;
		for(int i = 0;i<4;++i)if(s[i][3-i]!='T' && s[i][3-i]!='O')cur = false;
		if(cur)owin = true;

		bool ended = true;
		for(int i = 0;i<4;++i)for(int j=0;j<4;++j)if(s[i][j]=='.')ended = false;

		cout<<"Case #"<<test<<": ";
		if(owin)cout<<"O won"<<endl;else
			if(xwin)cout<<"X won"<<endl;else
				if(!ended)cout<<"Game has not completed"<<endl;else
					cout<<"Draw"<<endl;

		gets(s[0]);
	}
}