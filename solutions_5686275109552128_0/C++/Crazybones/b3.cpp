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
const int Max = 10010;
int num[Max];
int T;
int P;


int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	scanf("%d", &T);
	for (size_t i = 1; i <= T; i++)
	{
		int myMax = -1;
		int res = 0;
		int tmp;
		scanf("%d", &P);
		for (size_t j = 0; j < P; j++)
		{
			scanf("%d", &tmp);
			num[j] = tmp;
			if (tmp>myMax)myMax = tmp;
		}
		int myMin = 1010;
		for (size_t k = 1; k <= myMax; k++)
		{
			long long count = 0;
			for (size_t j = 0; j < P; j++)
			{
				if (num[j] % k == 0)count += num[j] / k - 1;
				else count += num[j] / k;
			}
			count += k;
			if (count < myMin)myMin=count;
		}
		printf("Case #%d: %d\n", i, myMin);
	}
}
