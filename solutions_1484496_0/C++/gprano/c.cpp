#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int si = 20;
const int sup = 100000;
int t[si];
int exist[si*sup];

int main()
{
    int nbcas;
    scanf("%d", &nbcas);
    for(int cas = 1; cas <= nbcas; cas++)
    {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < si; i++)
	    scanf("%d", &t[i]);
	for(int i = 0; i < si*sup; i++)
	    exist[i] = 0;
	printf("Case #%d:\n", cas);
	bool impossible = true;
	for(int mask = 1; mask < (1<<si); mask++)
	{
	    int total = 0;
	    for(int i = 0; i < si; i++)
		if(mask & (1<<i)) total += t[i];
	    if(exist[total] != 0)
	    {
		impossible = false;
		for(int i = 0; i < si; i++)
		    if(mask & (1<<i)) printf("%d ", t[i]);
		printf("\n");
		for(int i = 0; i < si; i++)
		    if(exist[total] & (1<<i)) printf("%d ", t[i]);
		printf("\n");
		break;
	    }
	    else exist[total] = mask;
	}
	if(impossible)
	    printf("Impossible\n");
    }
    return 0;
}
