/* Problem	: 
** Time		:
** Algorithm:
**/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005
#define st first
#define nd second
#define read(x) scanf("%d",&x)
#define rep(i,a,b) for(int i = a ; i <= b ; ++i)
typedef long long int64;

int main (int argc, char const* argv[]){
	if ( argc == 3 ){
		freopen(argv[1],"r",stdin);
		freopen(argv[2],"w",stdout);
	}
	int T; read(T);
	char board[4][5];
	rep(t,1,T){
		rep(i,0,3){
			scanf("%s",board[i]);
		}
		bool complete = true;
		int winner = 0;
		rep(i,0,3){
			if ( winner != 0 ) break;
			rep(j,0,3){
				if ( winner != 0 ) break;
				char st = '-';
				rep(k,0,3){
					if ( board[k][j] != 'T' ){
						if ( st == '-' ){
							st = board[k][j];
						}else if ( board[k][j] != st ) {
							st = '-';
							break;
						}
					} 
				}
//				printf("/ %c\n",st);
				if ( st == '-' ){
//					puts("over here");
					rep(k,0,3){
						if ( board[i][k] != 'T' ){
							if ( st == '-' ){
								st = board[i][k];
							}else if ( board[i][k] != st ) {
								st = '-';
								break;
							}
						} 
					}
//					printf("* %c\n",st);
				}
				if ( st == '-' && i == j ){
//					puts("there");
					rep(k,0,3){
						if ( board[k][k] != 'T' ){
							if ( st == '-' ){
								st = board[k][k];
							}else if ( board[k][k] != st ) {
								st = '-';
								break;
							}
						} 
					}
//					printf("+ %c\n",st);
				}
				if ( st == '-' && i == 3-j ){
//					puts("this place");
//					printf("%d %d\n",i,j);
					rep(k,0,3){
						if ( board[k][3-k] != 'T' ){
							if ( st == '-' ){
								st = board[k][3-k];
							}else if ( board[k][3-k] != st ) {
								st = '-';
								break;
							}
						} 
					}
//					printf("- %c\n",st);
				}
//				printf("%c\n",st);
				if ( st == 'X' ){
					winner = 1;
				}else if ( st == 'O' ){
					winner = -1;
				}
				if ( board[i][j] == '.' ){
					complete = false;
				}
			}
		}
		if ( winner == 1 ){
			printf("Case #%d: X won\n",t);
		}else if ( winner == -1 ){
			printf("Case #%d: O won\n",t);
		}else{
			if ( complete ){
				printf("Case #%d: Draw\n",t);
			}else{
				printf("Case #%d: Game has not completed\n",t);
			}
		}
	}
	return 0;
}

/* DOAN Minh Quy - mquy.doan@gmail.com */
