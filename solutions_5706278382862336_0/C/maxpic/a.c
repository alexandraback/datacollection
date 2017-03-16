#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

double Potenze2[60];

int IsPot2(double x)
{
int i;
for (i=0; i < 59 && Potenze2[i] < x; i++);
if (x==Potenze2[i]) return i;
return -1;
}

int MinPot2(double x)
{
int i;
for (i=0; i < 59 && Potenze2[i] <= x; i++);
return i-1;
}


long long Euclide(long long a, long long b) // prototipo della funzione Euclide //
{
    if (b == 0) return a; // controlla che b non sia 0, in caso restituisce a //
 
    long long r;
    r = a % b;             // operazione modulo //
    while(r != 0)          // ciclo di iterazione //
    {
        a = b;
        b = r;
        r = a %b;
    }
    return b;
}


void ElaboraCaso(int caso, FILE *fl)
{
int i;
double P,Q;
fscanf(fl, "%lf/%lf\n", &P, &Q);

double e=Euclide(P,Q);
P /= e;
Q /= e;
fprintf(stderr, "caso #%d : %.0f / %.0f euclide %g\n", caso, P, Q,e);


// Cerco di portare Q ad una qualche potenza del 2
int p2=-1;
for (i=1; i < 1000; i++)
	{
	if ((p2=IsPot2(Q*(double)i)) >= 0)
		{
		Q*=i;
		P*=i;
		break;
		}
	}

if ( p2 < 0)
	{
	printf("Case #%d: impossible\n", caso);
	return;
	}
i=MinPot2(Q);
int k=MinPot2(P);
fprintf(stderr, ">>>: %g / %g ===> %d %d \n", P, Q, k, i);
printf("Case #%d: %d\n",caso, i-k);
}

int main(int argc, char *argv[])
{
FILE *fl;
char	row[1024];
if (argc < 2)
	{
	printf("Manca file\n");
	return 1;
	}

fl=fopen(argv[1], "r");
if (!fl)
	{
	perror("Aprendo il file");
	return 1;
	}

if (!fgets(row, sizeof(row), fl))
	{
	perror("leggendo il file");
	return 1;
	}

long casi=atol(row);
fprintf(stderr, "%ld casi\n", casi);

long i;

// Inizializzo potenze del 2
Potenze2[0]=1;
for (i=1; i < 60; i++)
	Potenze2[i]=2*Potenze2[i-1];

for (i=0; i< casi; i++)
	{
	ElaboraCaso(i+1, fl);
	}

fclose(fl);
return 0;
}
