// =====================================================================================
//       Filename:  Mines.cpp
//    Description:  
//        Created:  04/12/2014 05:49:30 PM
//         Author:  BrOkEN@!
// =====================================================================================

#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

template< class T > inline T _maxOfThree(T a,T b,T c) {return max(max(a,b),c);}
template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _square(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool in_range(T x, T i, T y) { return x<=i && i<=y; }

#define FOR(i,a,b) for(typeof((a)) i=(a); i <= (b) ; ++i)
#define REV_FOR(i,a,b) for(typeof((a)) i=(a); i >= (b) ; --i)
#define FOREACH(it,x) for(typeof((x).begin()) it=(x).begin(); it != (x).end() ; ++it)
#define REV_FOREACH(it,x) for(typeof((x).rbegin()) it=(x).rbegin(); it != (x).rend() ; ++it)
#define SET(p, v) memset(p, v, sizeof(p))
#define CLR(p) SET(p,0)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
#define __int64 long long

typedef pair<int,int> PI;
typedef vector<PI> VI;


const int MAX = 55;

int rows,cols,mines,tocover;

int board[MAX][MAX];
int s_x=0,s_y=0;

void printBoard(){
	FOR(i,0,rows-1){
		FOR(j,0,cols-1){
			if(i==s_x && j==s_y)	printf("c");	//starting
			else if(board[i][j]==0)	printf("*");	//has mine
			else printf(".");			//open grid
		}
		printf("\n");
	}
}

int unCoverGrid(int mx,int my){
	int count=0;
	FOR(x,mx-1,mx+1){
		FOR(y,my-1,my+1){
			if((x>=0 && x<rows) && (y>=0 && y<cols) && (board[x][y]==0)){	//existing uncovered cell
				count++;
			}
		}
	}
	return count;
}

bool recursive(int mx,int my,int& sofar){
	if(sofar>=tocover)	return true;

	sofar++;
	board[mx][my]=1;	//0-chain on mx,my

	if(sofar>=tocover)	return true;	//may be 0-chain can end if is acheived.

	FOR(nx,mx-1,mx+1){
		FOR(ny,my-1,my+1){
			if((nx>=0 && nx<rows) && (ny>=0 && ny<cols) && (board[nx][ny]==0)){
				board[nx][ny]=2;//fill Uncovered NCells
				sofar++;
			}else if((nx>=0 && nx<rows) && (ny>=0 && ny<cols) && (board[nx][ny]==2)){
				board[nx][ny]=-2;//fill Uncovered NCells
			}
		}
	}

	if(sofar>=tocover)	return true;
	
	FOR(nx,mx-1,mx+1){
		FOR(ny,my-1,my+1){
			if((nx>=0 && nx<rows) && (ny>=0 && ny<cols) && (board[nx][ny]==2)){
				board[nx][ny]=0;
				sofar--;
				if(recursive(nx,ny,sofar))	return true;
				sofar++;
				board[nx][ny]=2;
			}
		}
	}

	FOR(nx,mx-1,mx+1){
		FOR(ny,my-1,my+1){
			if((nx>=0 && nx<rows) && (ny>=0 && ny<cols) && (board[nx][ny]==2)){
				board[nx][ny]==0;
				sofar--;
			}else if((nx>=0 && nx<rows) && (ny>=0 && ny<cols) && (board[nx][ny]==-2)){
				board[nx][ny]=2;
			}
		}
	}	
	
	board[mx][my]=0;
	sofar--;

	return (sofar>=tocover);	
}


bool solve(){
	tocover = rows*cols - mines;
	for(s_x=0;s_x<rows;s_x++){
		for(s_y=0;s_y<cols;s_y++){
			FOR(i,0,MAX-1)	CLR(board[i]);
			int sofar=0;
			if(recursive(s_x,s_y,sofar) && sofar==tocover)
				return true;
		}
	}
	return false;	
}


int main(){
	int T=0;
	scanf("%d",&T);
	FOR(t,1,T){
		scanf("%d%d%d",&rows,&cols,&mines);
//		printf("[ROWS:%d,COLS:%d] [MINES:%d], freeZone:%d\n",rows,cols,mines,rows*cols - mines);
		printf("Case #%d:\n",t);
		if(solve())
			printBoard();
		else
			printf("Impossible\n");
//		printf("========================================================\n");
	}
	return 0;
}

