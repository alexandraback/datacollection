#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <cstring>
using namespace std;

int N, J;
int T;
int *arr;
int cnt;

void find_coin(int cur){
	if(cnt == J){
		return;
	}
	else if(cur == 1){
		for(int i = N-1; i >= 0; i--)
			cout << arr[i];
		for(int i = 2; i <= 10; i++)
			printf(" %d", i+1);
		printf("\n");
		cnt++;
	}
	else{
		arr[cur] = 0;
		arr[cur-1] = 0;
		find_coin(cur-2);

		arr[cur] = 1;
		arr[cur-1] = 1;
		find_coin(cur-2);
	}
}

int main(void)
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d:\n", t);
		cin >> N >> J;
		arr = new int[N];
		arr[0] = 1;
		arr[1] = 1;
		arr[N-2] = 1;
		arr[N-1] = 1;
		cnt = 0;

		find_coin(N-3);
	}
}