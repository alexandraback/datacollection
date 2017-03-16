#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

// dichotomie

int juge[200];

int main()
{
    int nbcas;
    scanf("%d", &nbcas);
    for(int cas = 1; cas <= nbcas; cas++)
    {
	int n;
	int x = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
	{
	    scanf("%d", &juge[i]);
	    x += juge[i];
	}
	double bas = 0.;
	double haut = 2*((double)x);
	while((haut - bas) > 0.000001)
	{
	    double test = (bas + haut)/2;
	    double sumb = 0.;
	    for(int i = 0; i < n; i++)
		sumb += max(0.,(test - ((double)juge[i]))/((double)x));
	    if(sumb > 1) haut = test;
	    else bas = test;
	}
	printf("Case #%d:", cas);
	for(int i = 0; i < n; i++)
	    printf(" %lf", 100.*max(0.,(haut - ((double)juge[i]))/((double)x)));
	printf("\n");
    }	
    return 0;
}
