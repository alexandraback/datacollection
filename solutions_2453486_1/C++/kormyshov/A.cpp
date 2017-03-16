#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) ((a)<0?(-1):((a)>0?(1):(0)))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926)
#define INF (2147483647)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

void solve(){
	char ss[9][9];
	int i, j;
	for(i=0;i<4;++i) cin>>ss[i];
	for(i=0;i<4;++i){
		for(j=0;j<4;++j)
			if(ss[i][j]=='.' || ss[i][j]=='O') break;
		if(j==4){
			cout<<"X won\n";
			return ;
		}
		for(j=0;j<4;++j)
			if(ss[i][j]=='.' || ss[i][j]=='X') break;
		if(j==4){
			cout<<"O won\n";
			return ;
		}
	}
	for(i=0;i<4;++i){
		for(j=0;j<4;++j)
			if(ss[j][i]=='.' || ss[j][i]=='O') break;
		if(j==4){
			cout<<"X won\n";
			return ;
		}
		for(j=0;j<4;++j)
			if(ss[j][i]=='.' || ss[j][i]=='X') break;
		if(j==4){
			cout<<"O won\n";
			return ;
		}
	}
	for(i=0;i<4;++i) if(ss[i][i]=='.' || ss[i][i]=='O') break;
	if(i==4){
		cout<<"X won\n";
		return ;
	}
	for(i=0;i<4;++i) if(ss[i][i]=='.' || ss[i][i]=='X') break;
	if(i==4){
		cout<<"O won\n";
		return ;
	}
	for(i=0;i<4;++i) if(ss[i][3-i]=='.' || ss[i][3-i]=='O') break;
	if(i==4){
		cout<<"X won\n";
		return ;
	}
	for(i=0;i<4;++i) if(ss[i][3-i]=='.' || ss[i][3-i]=='X') break;
	if(i==4){
		cout<<"O won\n";
		return ;
	}
	for(i=0;i<4;++i) for(j=0;j<4;++j) if(ss[i][j]=='.'){
		cout<<"Game has not completed\n";
		return ;
	}
	cout<<"Draw\n";
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}

int cpp4cf_main()
{
	/*freopen("A.cpp","r",stdin);*/

	char s[99];
	bool f;

	while(true) {
		cin>>s;
		if(cin.eof()) break;
		if(strstr(s,"/*")) {
			cin>>s;
			if(strstr(s,"Test")) {
				cin>>s;
				if(strstr(s,"on")) {
					cout<<"Output: ";
					cpp4cf_main();
					cout<<"\nAnswer: ";
					f = false;
					while(true) {
						cin>>s;
						if(strstr(s,"*/")) break;
						if(strstr(s,"//")) {
							if(f) cout<<endl;
							else f = true;
						}else cout<<s<<" ";
					}
					cout<<"\n\n";
				}
			}
		}
	}

	return 0;
}


