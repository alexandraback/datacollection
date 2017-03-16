#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int r,n,m,k;

int prod[7];

int maxp(int pr, int p)
{
    int result = 0;
    while(pr % p == 0)
    {
	result++;
	pr /= p;
    }
    return result;
}
	    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++) //nb_cas == 1
    {
	scanf("%d%d%d%d",&r,&n,&m,&k);
	printf("Case #%d:\n",cas);
	for(int rcas = 0; rcas < r; rcas++)
	{
	    for(int i = 0; i < 7; i++)
		scanf("%d",&prod[i]);
	    int is_a_2 = 0;
	    int nb_3 = 0;
	    int nb_5 = 0;
	    int nb_2 = 0;
	    for(int i = 0; i < 7; i++)
	    {
		nb_3 = max(nb_3, maxp(prod[i],3));
		nb_5 = max(nb_5, maxp(prod[i],5));
		nb_2 = max(nb_2, maxp(prod[i],2));
		if(maxp(prod[i],2) % 2 == 1)
		    is_a_2 = 1;
	    }
	    for(int i = 0; i < nb_5; i++)
		printf("5");
	    for(int i = 0; i < nb_3; i++)
		printf("3");
	    if(is_a_2) printf("2");
	    int restant = 3 - nb_3 - nb_5 - is_a_2;
	    if(restant == 3)
		printf("444");
	    else if(restant == 2)
	    {
		if(nb_2 >= 4)
		    printf("44");
		else if(nb_2 >= 3)
		    printf("42");
		else
		    printf("22");
	    }
	    else if(restant == 1)
	    {
		if(nb_2 >= 2)
		    printf("4");
		else
		    printf("2");
	    }
	    printf("\n");
	}
    }
    return 0;
}
