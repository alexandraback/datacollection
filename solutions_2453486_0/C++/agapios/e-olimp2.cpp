#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <memory.h>
#include <string.h>
//#include <assert.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define inf 1000000000
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n,m,k,t,x,cur;
char c;
char board[6][6];
bool Ocurrow, Ocurcol, Xcurrow, Xcurcol, Odiag1, Odiag2, Xdiag1, Xdiag2;

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d\n", &t);
	FOR(tt,1,t){
		FOR(i,1,4){			
			gets(&board[i][1]);
		}
		bool Owon = 0;
		bool Xwon = 0;
		bool filled = 1;
		FOR(i,1,4){
			Ocurrow = 1;
			Xcurrow = 1;
			Ocurcol = 1;
			Xcurcol = 1;
			
			FOR(j,1,4){
				if(board[i][j] == '.') filled = 0;
				if(board[i][j] == 'O' || board[i][j] == '.'){
					Xcurrow = 0;
				}
				if(board[i][j] == 'X' || board[i][j] == '.'){
					Ocurrow = 0;
				}
				if(board[j][i] == 'O' || board[j][i] == '.'){
					Xcurcol = 0;
				}
				if(board[j][i] == 'X' || board[j][i] == '.'){
					Ocurcol = 0;
				}				
			}
			Owon |= Ocurcol | Ocurrow;
			Xwon |= Xcurcol | Xcurrow;
		}
		Odiag1 = Odiag2 = Xdiag1 = Xdiag2 = 1;
		FOR(i,1,4)
			FOR(j,1,4){				
				if(board[i][i] == 'O' || board[i][i] == '.'){
					Xdiag1 = 0;
				}
				if(board[i][i] == 'X' || board[i][i] == '.'){
					Odiag1 = 0;
				}
				if(board[i][5-i] == 'O' || board[i][5-i] == '.'){
					Xdiag2 = 0;
				}
				if(board[i][5-i] == 'X' || board[i][5-i] == '.'){
					Odiag2 = 0;
				}		
			}
		Owon |= Odiag1 | Odiag2;
		Xwon |= Xdiag1 | Xdiag2;

		printf("Case #%d: ", tt);
		if(Owon){
			printf("O won\n");
		}else if(Xwon){
			printf("X won\n");
		}else if(filled){
			printf("Draw\n");
		}else{
			printf("Game has not completed\n");			
		}
		gets(board[5]);

	}

	


	return 0;
}