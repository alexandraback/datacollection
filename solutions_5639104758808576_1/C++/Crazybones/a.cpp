#include <cstdlib>
#include <set>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm> 
#include <stack>
#include <queue>
#include<map>
using namespace::std;
int T;
int Smax, S;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (size_t j = 1; j <=T; j++)
	{
		scanf("%d", &Smax);
		int sum = 0;
		int res = 0;
		char tmp;
		scanf("%c", &tmp);
		for (size_t i = 0; i <= Smax; i++)
		{
			scanf("%c", &tmp);
			if (sum < i){
				res+=i-sum;
				sum = i;
			}
			sum += (int)(tmp - '0');
		}
		printf("Case #%d: %d\n", j, res);
	}
}