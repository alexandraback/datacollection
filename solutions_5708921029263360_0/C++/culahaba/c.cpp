#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

#define fi "C-small-attempt0.in"
#define fo "c.out"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int mark_01[11][11];
int mark_02[11][11];
int mark_12[11][11];
int temp[3];
int result[1001][3];
int array[3];
int countResult, ntest, limit;


void input();
void output();

void solve(int d){
	if(d == 3){
		if(mark_01[temp[0]][temp[1]] >= limit ||  mark_02[temp[0]][temp[2]] >= limit || mark_12[temp[1]][temp[2]] >= limit)
			return;
			
		mark_01[temp[0]][temp[1]]++;
		mark_02[temp[0]][temp[2]]++;
		mark_12[temp[1]][temp[2]]++;
			
		result[countResult][0] = temp[0];
		result[countResult][1] = temp[1];
		result[countResult][2] = temp[2];
		
		countResult++;
		
		return;
	}
	
	for(int i = 1 ; i <= array[d]; i++){
		temp[d] = i;
		solve(d + 1);
	}
}

void init(){
	countResult = 0;
	
	for(int i = 1 ; i <= 10; i++){
		for(int j = 1 ; j <= 10 ; j++){
			mark_01[i][j] = 0;
			mark_02[i][j] = 0;
			mark_12[i][j] = 0;
		}
	}
}

void input()
{
	scanf("%d",&ntest);
	for(int i = 0 ; i < ntest; i++){
		scanf("%d %d %d %d", &array[0], &array[1], &array[2], &limit);
		printf("Case #%d: ", i + 1);
		init();
		solve(0);
		printf("%d\n",countResult);
		for(int j = 0 ; j < countResult; j++){
			printf("%d %d %d\n",result[j][0], result[j][1], result[j][2]);
		}
	}
}

void output()
{
}

int main() {
	
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	
	input();
	
	return 0;
}
