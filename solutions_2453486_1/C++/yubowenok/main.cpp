#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <Windows.h>

#define FORST(X,S,T) for(int X=S; X<=T; X++)  
#define RFORST(X,S,T) for(int X=S; X>=T; X--)  
#define FOR(X,XB) for(int X=0; X<XB; X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)  
#define FILE_W(X) freopen(X, "w", stdout)  
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
using namespace std;

char bd[12][12];

char find(int x, int y){
	char c = bd[x][y];
	if(c=='.') return '*';
	if(bd[x-2][y]==c && bd[x-1][y]==c && bd[x+1][y]==c) return c;
	if(bd[x-1][y]==c && bd[x+1][y]==c && bd[x+2][y]==c) return c;
	if(bd[x][y+2]==c && bd[x][y+1]==c && bd[x][y-1]==c) return c;
	if(bd[x][y-2]==c && bd[x][y+1]==c && bd[x][y-1]==c) return c;
	if(bd[x-1][y-1]==c && bd[x+1][y+1]==c && bd[x-2][y-2]==c) return c;
	if(bd[x-1][y-1]==c && bd[x+1][y+1]==c && bd[x+2][y+2]==c) return c;
	if(bd[x-1][y+1]==c && bd[x+1][y-1]==c && bd[x+2][y-2]==c) return c;
	if(bd[x-1][y+1]==c && bd[x+1][y-1]==c && bd[x-2][y+2]==c) return c;
	return '*';
}

int main(){
	int cs;

	FILE_W("output");

	char line[5];
	cin>>cs;
	cin.getline(line, 5);
	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);

		FORST(i, 2, 5){
			cin.getline(&bd[i][2], 5);
		}
		FOR(i,8){
			bd[0][i] = '#';
			bd[1][i] = '#';
			bd[7][i] = '#';
			bd[6][i] = '#';
			bd[i][0] = '#';
			bd[i][1] = '#';
			bd[i][6] = '#';
			bd[i][7] = '#';
		}
		cin.getline(line, 5);

		bool cd = 1;
		int xx=-1, yy=-1;

		FORST(i, 2, 5) FORST(j, 2, 5){
			if(bd[i][j]=='.'){
				cd = 0;
			}
			if(bd[i][j]=='T'){
				xx = i;
				yy = j;
			}	
		}
		bool win = 0;

		char c;
		FOR(t, 2){
			if(xx!=-1){
				if(t==0) bd[xx][yy]='X';
				else bd[xx][yy]='O';
			}
			FORST(i, 2, 5){
				FORST(j, 2, 5){
					c = find(i, j);
					if(c=='*') continue;
					else{
						win = 1;
						break;
					}
				}
				if(win) break;
			}
			if(win) break;
		}
		if(win){
			printf("%c won\n", c);
		}else{
			if(!cd){
				printf("Game has not completed\n");
			}else{
				printf("Draw\n");
			}
		}
	}
	return 0;
}