#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
#include <gmp.h>
using namespace std;

//donc : palindrom dont carré palindrome <=> plaindrom, sum des carrés et digits < 10
//ie digits dans {(22),(221),(moins de 10 1)} et (3),(2) mais juste pour 3,2
//donc réponse : f(partieinf(racine de B)) - f(partieinf(racine de (A-1)))
//où f(x) = nb de palindrom dont carré palindrom <= x
//x at most 10^50 (<10^50 qui est pas bon donc au plus 50 digits)
//(22) et (221) yen a 1 par nombre de digits, 200..002 et 200..1..002, just check with x
//sinon pour d digits, si est est impair (d-3)/2 choose 1,2,3 fois deux (un 1 ou pas au milieu)
//si d est pair (d-2)/2 choose 1,2,3
//le résultat est pas énorme, je pense qu'on peut tous les parcourir et vérifier s'ils sont <= x
//t'en as 41250 on dirait, donc on les calcule une fois, et après dichotomie
//use gmp ou des tableaux (test tableaux, avec next_permutation !)
//d'après oeis, les 412 premiers générés sont bons

int pal[42250][101];
char a[102];
char b[102];
int k = 3;

/*
void affiche_pal(int i)
{
    int ind = 100;
    while(pal[i][ind] == 0) ind--;
    while(ind >= 0)
    {
	printf("%d",pal[i][ind]);
	ind--;
    }
    printf("\n");
}
void affiche_2(int *t)
{
    int ind = 100;
    while(t[ind] == 0) ind--;
    while(ind >= 0)
    {
	printf("%d",t[ind]);
	ind--;
    }
    printf("\n");
}*/

void save(int d)
{
    for(int i = 0; i < d/2; i++)
    	pal[k][i+(d+1)/2] = pal[k][d/2-1-i];
    k++;
    for(int i = 0; i < d/2; i++)
	pal[k][i] = pal[k-1][i];
    return;
}

int comp(const void* first, const void* second)
{
    int* aa = (int*) first;
    int* bb = (int*) second;
    for(int i = 100; i >=0; i--)
    	if(aa[i] != bb[i])
	    return aa[i]-bb[i];
    return 0;
}

void reverse_int(char *orig, int* dest)
{
    int dig = 100;
    while(orig[dig] == 0) dig--;
    for(int i = 0; i <= dig; i++)
	dest[i] = (int) orig[dig-i] - '0';
    for(int i = dig+1; i <= 100; i++)
	dest[i] = 0;
    return;
}

int f(int* x)
{
    int mi = -1; int ma = k;
    while(ma - mi > 1)
    {
	int middle = (mi + ma) / 2;
	int comp_result = comp((const void*) x, (const void*) pal[middle]);
	if(comp_result < 0) //x plus petit que middle
	    ma = middle;
	else if (comp_result >= 0)
	    mi = middle;
    }
    return mi+1;
}
	    


int main()
{
    int nb_cas = 0;
    scanf("%d", &nb_cas);
    
    pal[0][0] = 1;
    pal[1][0] = 2;
    pal[2][0] = 3;
    for(int d = 2; d <= 50; d++)
    {
	pal[k][0] = 1;
	int dd = (d-2)/2; //moitié flexible
	save(d);
	if(d % 2)
	{
	    pal[k][1+dd] = 1;
	    save(d);
	    pal[k][1+dd] = 2;
	    save(d);
	}
	if(d >= 4)
	{
	    for(int i = 1; i < 101; i++) pal[k][i] = 0;
	    pal[k][dd] = 1;
	    for(int i = 0; i < dd; i++)
	    {
		save(d);
		if(d % 2)
		{
		    pal[k][1+dd] = 1;
		    save(d);
		    pal[k][1+dd] = 2;
		    save(d);
		    pal[k][1+dd] = 0;
		}
		next_permutation(pal[k]+1,pal[k]+dd+1);
	    }
	}
	if(d >= 6)
	{
	    for(int i = 1; i < 101; i++) pal[k][i] = 0;
	    pal[k][dd] = 1;
	    pal[k][dd-1] = 1;
	    for(int i = 0; i < dd*(dd-1)/2; i++)
	    {
		save(d);
		if(d % 2)
		{
		    pal[k][1+dd] = 1;
		    save(d);
		    pal[k][1+dd] = 0;
		}
		next_permutation(pal[k]+1,pal[k]+dd+1);
	    }
	}
	if(d >= 8)
	{
	    for(int i = 1; i < 101; i++) pal[k][i] = 0;
	    pal[k][dd] = 1;
	    pal[k][dd-1] = 1;
	    pal[k][dd-2] = 1;
	    for(int i = 0; i < dd*(dd-1)*(dd-2)/6; i++)
	    {
		save(d);
		if(d % 2)
		{
		    pal[k][1+dd] = 1;
		    save(d);
		    pal[k][1+dd] = 0;
		}
		next_permutation(pal[k]+1,pal[k]+dd+1);
	    }
	}
	for(int i = 1; i < 101; i++) pal[k][i] = 0;
	pal[k][0] = 2;
	save(d);
	if(d % 2)
	{
	    pal[k][1+dd] = 1;
	    save(d);
	}
    }
    qsort((void*) &pal[0], k, 101*sizeof(int), comp);
    /*for(int i = 0; i < 10; i++)
    {
	printf("%d ",i);
	affiche_pal(i);
	}*/
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	for(int i = 0; i < 102; i++)
	{ a[i] = 0; b[i] = 0;}
	scanf("%s%s",a,b);
	mpz_t biga, bigb;
	mpz_t roota, rootb;
	mpz_t biga_1; mpz_init(biga_1);
	mpz_init(biga); mpz_init(bigb);
	mpz_init(roota); mpz_init(rootb);
	mpz_set_str(biga,a,10);
	mpz_sub_ui(biga_1,biga,(unsigned long int)1);
	mpz_set_str(bigb,b,10);
	mpz_sqrt(roota,biga_1);
	mpz_sqrt(rootb,bigb);
	char *sqa = (char*) calloc(102,sizeof(char));
	char *sqb = (char*) calloc(102,sizeof(char));
	mpz_get_str(sqa,10,roota);
	mpz_get_str(sqb,10,rootb);
	//ok, maintenant le nombre <= sqb - le nombre <= sqa
	int sqa_[101];
	int sqb_[101];
	//they are reverse, let's get them
	reverse_int(sqa,sqa_);
	reverse_int(sqb,sqb_);
	printf("Case #%d: %d\n",cas,f(sqb_) - f(sqa_));
    }
    return 0;
}
