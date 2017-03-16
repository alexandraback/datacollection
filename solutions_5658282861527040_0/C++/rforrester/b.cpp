
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define DBG(X) 
char tab[120][120];

int main()
{
	
	int t;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		int r = 0;
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
		if ((i & j) < k) r++;
		cout << "Case #" << z << ": " << r << endl;
	}
	
	return 0;
}
