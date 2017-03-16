#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <math.h>

using namespace std;

//short hand for loops
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//quick print for answer cases
int case_number;
#define gout case_number++, printf("Case #%d: ",case_number), cout
#define INF (1<<29)

//define necessary arrays here 
int a[50][50] = {0}; 

int sumRow(int row, int C){
	int i;
	int sum=0;
	REP(i,C){
		sum += a[row][i];
	}
	return sum;
}

int sumCol(int col, int R){
	int i;
	int sum=0;
	REP(i,R){
		sum += a[i][col];
	}
	return sum;
}

void printBoard(int R, int C, int M){
	int i,j,k;
	REP(i,R){
		REP(j,C){
			if(a[i][j]==1){
				if(i==0 and j==0){
					printf("c");
				}else{
					printf(".");
				}	
			}else{
				printf("*");
			}
		}
		cout << endl;
	}
}

void main2(void){
	int R,C,M,i,j,k,spaces,mines;
	int flag = 0;
	
	REP(i,50){
		REP(j,50){
			a[i][j]=0;
		}
	} 
		
	cin >> R >> C >> M;
	spaces = R*C - M;
	
	//cout << "spaces " << spaces << endl; //

	
	//deal with edge cases
	if(M==R*C){ //all mines 
		goto end;//lose
	}else if (M==(R*C-1)){ //one space
		//win
		a[0][0] = 1;
	}else if (R==1 or C==1){ //one row or col
		//win
		if(R==1){
			REP(i,C){
				if(spaces>0) a[0][i] = 1; spaces--;
			}	
		}else{
			REP(i,R){
				if(spaces>0) a[i][0] = 1; spaces--;
			}
		}
	}else if(M==(R*C-2)){ // 2 spaces with 2*2 or larger
		goto end;//lose
	}else if(spaces % 2==0){ // even number higher than two
		//win
		REP(i,R){
			REP(j,C){
				if(spaces>0){
					a[i][j] = 1;
					spaces--;
				}
			}
		}
		/*
		REP(i,R){ //
			REP(j,C){ //
				printf("%d ",a[i][j]); //
			} //
			cout << endl; //
		} //
		*/
	
		
		goto full; // test for some conditions before drawing
	}else{
		
		//place spaces in grid
		REP(i,R){
			REP(j,C){
				if(spaces>0){
					a[i][j] = 1;
					spaces--;
				}else{
					goto full;
				}
			}		
		}
		full:
		//search cols
		
		/*
		REP(i,R){ //
			REP(j,C){ //
				printf("%d ",a[i][j]); //
			} //
			cout << endl; //
		} //
		*/
		
		for(i=C-1;i>=0;i--){
			if(sumCol(i,R)==1){
				a[0][i] = 0;
				int nxrow=1;
				int found = 1;
				REP(j,R){
					if(sumRow(nxrow,C)==sumRow(0,C)){
						nxrow++;
					}else{
						break;
					}
				} //if nxrow is equal to R then nothing was found
				//cout << "nxrow " << nxrow << " R " << R << endl; //
				if(nxrow>=R){
					goto end;
				}else{
					a[nxrow][sumRow(nxrow,C)] = 1;
					i=C-1; //reset i 
				}	
			}		
		}
		/*
		REP(i,R){ //
			REP(j,C){ //
				printf("%d ",a[i][j]); //
			} //
			cout << endl; //
		} //
		*/
		
		//search rows 
		REP(i,R){
			if(sumRow(i,C)==1){
				if(i!=0){
					a[i-1][sumRow(i-1,C)-1] = 0;
					a[i][1] = 1;
					if(sumRow(i-1,C)==1){
						goto end;
					}
					goto full; // there may now be columns with 1d				
				}else{
					goto end;
				}
			}
		}
			
	} // end else
		
	flag = 1;
	
	end:
	if(flag==1){
		gout << endl;
		printBoard(R,C,M);
	}else{
		gout << endl;
		cout << "Impossible" << endl;
	}
	
	
} //end main2


int main(void){
	int number_of_test_cases, i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
