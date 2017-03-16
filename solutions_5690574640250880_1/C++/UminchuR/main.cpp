#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007

char board[55][55];
int r,c,m,x,f;

void output(){
	printf("\n");
	if(f==1){
		REP(i,55)FOR(j,i+1,55)swap(board[j][i],board[i][j]);
		swap(r,c);
	}
	REP(i,r)cout << board[i] << endl;
}

void IMP(){
	cout << "\nImpossible" << endl;
}

void solve(){
	memset(board, '*', sizeof(board));
	cin>>r>>c>>m;
	x=r*c-m;
	if(r>c){
		swap(r,c);
		f=1;
	}else f=0;
	REP(i,r)board[i][c]='\0';
	REP(i,c+1)board[r][i]='\0';
	if(x==1){
		board[0][0]='c';
		return output();
	}
	if(r==1){
		REP(i,x)board[0][i]='.';
		board[0][0]='c';
		return output();
	}
	if(r==2){
		if(x<4||x%2==1)return IMP();
		REP(i,x/2)board[0][i]=board[1][i]='.';
		board[0][0]='c';
		return output();
	}
	if(x==7||x==5||x<4)return IMP();
	if(x>=2*c){
		REP(i,x)board[i/c][i-(i/c)*c]='.';
		if(x-(x/c)*c==1){
			if(x/c==2){
				board[2][1]=board[2][2]='.';
				board[0][c-1]=board[1][c-1]='*';
			}else{
				swap(board[x/c][1], board[x/c-1][c-1]);
			}
		}
		board[0][0]='c';
		return output();
	}
	else{
		if(x%2==1){
			REP(i,3)board[2][i]='.';
			x-=3;
		}
		REP(i,x/2)board[0][i]=board[1][i]='.';
		board[0][0]='c';
		return output();
	}
}


void main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	REP(t,T){
		printf("Case #%d: ", t+1);
		solve();
	}
}