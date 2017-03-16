#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))
   
using namespace std;

char mp[10][10];

int main ()
{
	int t, cases = 1;;
	scanf("%d", &t);
	getchar();
	while(t--){
		int flag = -1;
		int have = 0;
		for(int i=0; i<4; i++){
			gets(mp[i]);
			for(int j=0; j<4; j++)
				if(mp[i][j] == '.')
					have = 1;
		}
			
		getchar();
		
		for(int i=0; i<4; i++){
			flag = -1;
			for(int j=0; j<4; j++){
				if(mp[i][j] == '.'){
					flag = -1;
					break;
				}
				if((flag == -1 || flag == 1) && mp[i][j] == 'O'){
					flag = 1;
				}
				if((flag == -1 || flag == 2) && mp[i][j] == 'X'){
					flag = 2;
				}
				if((flag == 1 && mp[i][j] == 'X') || (flag == 2 && mp[i][j] == 'O'))
					flag = 3;
				
			}
			if(flag == 1 || flag == 2)
				goto out;
		}
		
		for(int i=0; i<4; i++){
			flag = -1;
			for(int j=0; j<4; j++){
				if(mp[j][i] == '.'){
					flag = -1;
					break;
				}
				if((flag == -1 || flag == 1) && mp[j][i] == 'O'){
					flag = 1;
				}
				if((flag == -1 || flag == 2) && mp[j][i] == 'X'){
					flag = 2;
				}
				if((flag == 1 && mp[j][i] == 'X') || (flag == 2 && mp[j][i] == 'O'))
					flag = 3;
				
			}
			if(flag == 1 || flag == 2)
				goto out;
		}
		
		flag = -1;
		for(int i=0; i<4; i++){
			if(mp[i][i] == '.'){
				flag = -1;
				break;
			}
			if((flag == -1 || flag == 1) && mp[i][i] == 'O'){
				flag = 1;
			}
			if((flag == -1 || flag == 2) && mp[i][i] == 'X'){
				flag = 2;
			}
			if((flag == 1 && mp[i][i] == 'X') || (flag == 2 && mp[i][i] == 'O'))
				flag = 3;
		}
		if(flag == 1 || flag == 2)
			goto out;
		
		flag = -1;
		for(int i=0; i<4; i++){
			if(mp[i][3-i] == '.'){
				flag = -1;
				break;
			}
			if((flag == -1 || flag == 1) && mp[i][3-i] == 'O'){
				flag = 1;
			}
			if((flag == -1 || flag == 2) && mp[i][3-i] == 'X'){
				flag = 2;
			}
			if((flag == 1 && mp[i][3-i] == 'X') || (flag == 2 && mp[i][3-i] == 'O'))
				flag = 3;
		}
		if(flag == 1 || flag == 2)
			goto out;
		out:;
		printf("Case #%d: ", cases++);
		if(flag == 1 || flag == 2){
			if(flag == 1)
				printf("O won\n");
			else if(flag == 2)
				printf("X won\n");
			continue;
		}
		
		if(have){
			printf("Game has not completed\n");
		}else{
			printf("Draw\n");
		}
	}
    return 0;
}
