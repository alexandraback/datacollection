#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int v[maxn];    
int e, r, n;
int maxgain;

void go(int i, int energy, int gain)
{
	if (i >= n)
	{
		if (gain > maxgain)
			maxgain = gain;
		return;
	}

	if (energy > e)
	{	
		energy = e;
		printf("fuck");
	}

	if (energy < 0)
	{
		energy = 0;
		printf("fuck");
	}


	for (int k = 0;k<=energy; k++)
	{
		go(i+1, min(energy - k + r, e), gain + k * v[i]);
	}
}

void work()
{
	memset(v, 0, sizeof(v));

    scanf("%d%d%d", &e, &r, &n);

    for (int i = 0;i<n;i++)
    {
        scanf("%d", &v[i]);        
    }    

    maxgain = 0;
    go(0, e, 0);
    printf("%d\n", maxgain);
}
 
int main()
{
    freopen("B-small-attempt3.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);    
    // freopen("in.txt", "r", stdin);
    freopen("out_brute.txt", "w", stdout);
 
    int cs, t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        work();
    }
 
    return 0;
}