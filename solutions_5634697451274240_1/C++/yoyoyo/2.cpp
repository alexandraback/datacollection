#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <cstring>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	int n;
	char stack[100];
	for(int t = 1; t <= T; t++)
	{

		printf("Case #%d: ", t);
		scanf("%s", stack);

		int diff = 0;
		int count = 0;
		int len = strlen(stack);

		if(len == 1){
			if(stack[0] == '+')
				count = 0;
			else
				count = 1;
		}
		else{
			for(int i = 0; i < len -1; i++)
				if(stack[i] != stack[i+1])
					diff++;
			if(stack[len-1] == '+')
				count = diff;
			else
				count = diff + 1;

		}
		cout << count << endl;
	}
}