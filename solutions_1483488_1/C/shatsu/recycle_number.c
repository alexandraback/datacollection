#include <stdio.h>
#include <stdlib.h>  // malloc, atof, etc
#include <inttypes.h> // int64
#include <stdbool.h> // bool
#include <string.h>
#include <math.h>

#define _STR(x)      #x
#define _STR2(x)     _STR(x)
#define __SLINE__    _STR2(__LINE__)
#define HERE         __FILE__ "(" __SLINE__ ")"
// usage: printf(HERE "x=%d\n", x);

#define _PFP(str) printf("%s\n", str)
#define ASIZEOF(array) (sizeof(array) / sizeof(array[0]))
#define FOR(i, j) for(((i) = 0); ((i) < (j)); ((i)++))
#define ISR(str) str, #str

#define L 1001
char line[L]; // input buffer

#define MAX 2000001
char check[MAX];

int rotate(int x, int num){ // 1回rotate
	char c1[256];
	char c2[256];
	int i;
	int y = x;
	for(i = num-1; i >= 0; i--){
		if(y == 0){
			c1[i] = '0';
		} else { 
			c1[i] = (y % 10) + '0';
			y = (y - (y%10)) / 10;
		}
	}
//	printf("%d = %s\n", x, c1);
	c1[num]='\0';
	c2[0]=c1[num-1];
	for(i = 0; i < num-1; i++){
		c2[i+1]=c1[i];
	}
	c2[num]='\0';
//	printf("%d = %s\n", x, c2);
	return(atoi(c2));
}

void res(int i, int a, int b){
	memset(check, 'F', MAX*sizeof(char)); // Clear
	int j, k, num_rot;
	int count = 0;
	num_rot = (int)(floor(log10(b)+1));  // 最大の桁数を求める関数
	for( j = a; j <= b; j++){
		if(check[j] == 'T') continue; // すでに見た
		int temp = 1; // ペアの数
		int p = j; 
		for( k = 0; k < num_rot; k++){
			p = rotate(p , num_rot);  // 回転
			if(p != j && a <= p && p <= b && check[p] == 'F'){
				temp++;
				check[p] = 'T';
			}
		}
		if(temp > 1){ // 自分以外のペアが見つかった
			count += (temp*(temp-1))/2; // nC2の計算
		}
	}
	printf("Case #%d: %d\n", i + 1, count);
}

int main( )
{
  int num; // num of case
	unsigned int point;
	fgets(line, L, stdin);
	sscanf(line, "%d", &num);

	unsigned int i,j;
	int a, b;

	for( i = 0 ; i < num; i++){
		fgets(line, L, stdin);
		sscanf(line, "%d %d", &a, &b);
		res(i, a, b);
	}
//	printf("%d = %d\n",9,rotate(9,4));
  exit(EXIT_SUCCESS);
}