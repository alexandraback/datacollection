#include<bits/stdc++.h>
#define M 20000
using namespace std;
char s[20][20] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int  order[] = {0 , 2 , 6 , 8 , 4 , 7 , 5 , 3 , 1 , 9};
char id[20] = "ZWXGUSFROI";
char input[M + 5];
int c0[33] , c1[33];
void get(int x,char t){
	c1[x] = c0[t - 'A'];
	for(int i = 0 ; i < strlen(s[x]) ; i++)  c0[s[x][i] - 'A'] -= c1[x];
}
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tc = 1 ; tc <= T ; tc++){
		scanf("%s",input);
		int n = strlen(input);
		memset(c0 , 0 , sizeof c0); memset(c1 , 0 , sizeof c1);
		for(int i = 0 ; i < n ; i++)	c0[input[i] - 'A']++;
		for(int i = 0 ; i < 10 ; i++)	get(order[i] , id[i]);
		for(int i = 0 ; i < 26 ; i++)assert(c0[i] == 0);
		printf("Case #%d: ",tc);
		for(int i = 0 ; i < 10 ; i++)
			for(int j = 1 ; j <= c1[i] ; j++)	printf("%d",i);
		printf("\n");
	}
}
