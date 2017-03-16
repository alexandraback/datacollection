#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <cstring>

using namespace std;

#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

inline void alg(){
	int boadX[4][4]={0};
	int boadO[4][4]={0};
	int enpty_flag=false;
	rep(y,4){
		rep(x,4){
			char c;
			cin >> c;
			if(c=='.'){
				enpty_flag=true;
			}else if(c=='T'){
				boadX[y][x]=1;
				boadO[y][x]=1;
			}else if(c=='X'){
				boadX[y][x]=1;
			}else if(c=='O'){
				boadO[y][x]=1;
			}
		}
	}

	int sum_O[6]={0};
	int sum_X[6]={0};
	rep(y,4){
		int sumH_O=0;
		int sumH_X=0;
		rep(x,4){
			sumH_O+=boadO[y][x];
			sumH_X+=boadX[y][x];
			sum_O[x]+=boadO[y][x];
			sum_X[x]+=boadX[y][x];
		}
		if(sumH_X==4){
			cout <<"X won";
			return;
		}else if(sumH_O==4){
			cout <<"O won";
			return;
		}
	}
	sum_X[4]=boadX[0][0]+boadX[1][1]+boadX[2][2]+boadX[3][3];
	sum_X[5]=boadX[3][0]+boadX[2][1]+boadX[1][2]+boadX[0][3];
	sum_O[4]=boadO[0][0]+boadO[1][1]+boadO[2][2]+boadO[3][3];
	sum_O[5]=boadO[3][0]+boadO[2][1]+boadO[1][2]+boadO[0][3];

	rep(i,6){
		if(sum_X[i]==4){
			cout <<"X won";
			return;
		}else if(sum_O[i]==4){
			cout <<"O won";
			return;
		}
	}


	if(enpty_flag){
		cout <<"Game has not completed";
		return;
	}else{
		cout <<"Draw";
		return;
	}
}


int main(int argc, char** argv)
{	
	if(argc<2)return 0;

	string in_file=argv[1];
	freopen(in_file.c_str(),"r",stdin);
	freopen((in_file.substr(0,in_file.find_last_of("."))+".out").c_str(),"w",stdout);

	int n_cases;
	cin >> n_cases;
	rep(i,n_cases){
		cout << "Case #" << i+1 << ": ";
		alg();
		cout << endl;
	}
	return 0;
}
