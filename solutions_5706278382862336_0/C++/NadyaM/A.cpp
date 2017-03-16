#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int T;
long long P, Q;

long long nod(long long x, long long y)
{
	return (y==0? x: nod(y, x%y));
}

int main()
{	int tt, i, a, b, f;
	long long ND, k;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		scanf("%I64d/%I64d", &P, &Q);
		ND = nod(P, Q);
		P /= ND;
		Q /= ND;
		k=1; i=0; a=0; f=0;
		while(k<=Q)
		{
			if(k<=P)
				++a;
			if(Q == k)
			{
				b = i;
				f=1;
				break;
			}
			i++;
			k *= 2;
		}
		if(!f)
			printf("Case #%d: impossible\n", tt);
		else
			printf("Case #%d: %d\n", tt, b-(a-1));
	}
	
	return 0;
}