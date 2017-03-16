#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char arr[10][10] , visited[10][10];
int dy [] = {-1,0,1,1,1,0,-1,-1} , dx [] = {-1,-1,-1,0,1,1,1,0} , M , R , C;
bool Exit_t = false;

int Success(int x , int y){
	if(x < 0 || x >= R || y < 0 || y >= C) return 0;
	if(visited[x][y]) return 0;
	if(arr[x][y] == '*') return 0;

	visited[x][y] = true;
	int c = 0 , re = 0;
	for (int i = 0; i < 8; i++)
	{
		if(x+dx[i] > -1 && x+dx[i] < R && y+dy[i] > -1 && y+dy[i] < C)
			c += arr[x+dx[i]][y+dy[i]] == '*' ? 1 : 0;
	}
	if(c == 0){
		for (int i = 0; i < 8; i++)
			re += Success(x+dx[i] , y+dy[i]);
	}
	return 1 + re;
}
void Print(int x , int y){
	arr[x][y] = 'c';
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%c" , arr[i][j]);
		}
		printf("\n");
	}
}

bool check(){
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if(arr[i][j] == '.'){
				memset(visited , false , sizeof visited);
				if( Success(i , j) == R*C - M){
					Print(i,j);
					return true;
				}
			}
		}
	}
	return false;
}

void rec(int n , int st){
	if(n == 0){
		if(check()){
			Exit_t = true;
		}
		return;
	}
	for (int i = st; i < R*C; i++)
	{
		if(Exit_t) return;
		arr[i/C][i%C] = '*';
		rec(n-1 , i+1);
		arr[i/C][i%C] = '.';
	}
}

int main() {
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	int T;
	scanf("%d" , &T);
	for(int h=0 ; h<T ; h++){
		Exit_t = false;
		printf("Case #%d:\n" , h+1);		
		scanf("%d%d%d" , &R , &C , &M);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				arr[i][j] = '.';
		rec(M , 0);
		if(Exit_t == false) printf("Impossible\n");
	}
	return 0;
}
